#include "harmonic_particles.h"

State new_state( size_t N, int i )
{
  State state(N);
  thrust::fill(state.begin(), state.end(), i);
  return state;
}
