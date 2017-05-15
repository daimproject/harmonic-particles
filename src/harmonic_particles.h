#include <thrust/device_vector.h>

typedef thrust::device_vector<double> State;

State new_state( size_t N, int i );
