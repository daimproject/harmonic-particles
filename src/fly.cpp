// Fly ions through multipole fields
// vim:set ts=2 sts=2 sw=2 expandtab:

#include <iostream>
#include <boost/program_options.hpp>
#include <boost/range/combine.hpp>
#include "harmonic_particles.h"

namespace po = boost::program_options;

// When compiled with nvcc
#ifdef __CUDACC__
#include <cuda_profiler_api.h>
void CLEANUP(){ cudaProfilerStop();}
#else
void CLEANUP(){ }
#endif

using Harmonics = std::vector<std::complex<double>>;

Harmonics parse_command_line(int argc, char* argv[]){
  // normal and skew
  std::vector<double> normal;
  std::vector<double> skew;

  // Command-line options
  po::options_description opt_desc("Allowed options");
  opt_desc.add_options()
    ("help", "produce help message")
    ("normal", po::value<std::vector<double>>(&normal)
                ->multitoken(), "set normal harmonics")
    ("skew", po::value<std::vector<double>>(&skew)
                ->multitoken(), "set skew harmonics")
    ;
  po::variables_map vars;
  po::store(po::parse_command_line(argc, argv, opt_desc), vars);
  po::notify(vars);

  // Pad normal and skew components to the same size
  auto n_harmonics = std::max(normal.size(), skew.size());
  normal.resize(n_harmonics, 0);
  skew.resize(n_harmonics, 0);

  // Combine harmonics to complex vector
  Harmonics harmonics;
  for (auto ns : boost::combine(normal, skew)){
    double n, s;
    boost::tie(n, s) = ns;
    harmonics.push_back(std::complex<double>(n, s));
  }
  return harmonics;
}


void print_harmonics(Harmonics harmonics)
{
  std::cout << "Harmonics:\n";
  for(auto x : harmonics) {
    std::cout << x.real() << "\t" << x.imag() << std::endl;
  }
}

int main( int argc , char* argv[] )
{
  auto harmonics = parse_command_line(argc, argv);
  print_harmonics(harmonics);
  
  CLEANUP();
  return 0;
}
