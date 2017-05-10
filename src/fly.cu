// Fly ions through multipole fields
// vim:set ts=2 sts=2 sw=2 expandtab:

#include <iostream>

#include <thrust/device_vector.h>
//#include <thrust/reduce.h>
//#include <thrust/functional.h>
#include <boost/numeric/odeint.hpp>

// When compiled with nvcc
#ifdef __CUDACC__
#include <cuda_profiler_api.h>
void CleanUp(){ cudaProfilerStop();}
#else
void CleanUp(){ }
#endif

using namespace boost::numeric::odeint;

// State types
typedef double value_type;
typedef thrust::device_vector< value_type > state_type;
typedef thrust::device_vector< size_t > index_vector_type;

// Constants -- units are SI
const size_t N = 10;
const value_type dx = 1;
const value_type dt = 0.01;

state_type new_state_vector( size_t N, size_t i )
{
  state_type state_vector( N );
  thrust::fill(state_vector.begin(), state_vector.end(), i);
  return state_vector;
}

int main( int arc , char* argv[] )
{
  std::cout << "Hello \n";

  state_type x = new_state_vector( 10, 8 );
  
  for( size_t i=0; i<N; ++i ){
    std::cout << x[i]; 
  }

  
  CleanUp();
  return 0;
}
