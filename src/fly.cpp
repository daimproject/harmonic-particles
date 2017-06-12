// Fly ions through multipole fields
// vim:set ts=2 sts=2 sw=2 expandtab:

#include <iostream>

#include <thrust/device_vector.h>
#include <boost/program_options.hpp>
#include "harmonic_particles.h"

namespace po = boost::program_options;

// When compiled with nvcc
#ifdef __CUDACC__
#include <cuda_profiler_api.h>
void CLEANUP(){ cudaProfilerStop();}
#else
void CLEANUP(){ }
#endif

using harmonics_type = std::pair<std::vector<double>,std::vector<double>>;

harmonics_type parse_command_line(int argc, char* argv[]){
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
  return std::make_pair(normal, skew);
}

void print_harmonics(harmonics_type harmonics)
{
  std::cout << "Normal:\n";
  for(auto x : harmonics.first) {
    std::cout << "  " << x << "\n";
  }
  std::cout << "Skew:\n";
  for(auto x : harmonics.second) {
    std::cout << "  " << x << "\n";
  }
}

int main( int argc , char* argv[] )
{
  auto harmonics = parse_command_line(argc, argv);
  print_harmonics(harmonics);
  
  CLEANUP();
  return 0;
}
