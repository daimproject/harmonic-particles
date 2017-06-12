#include <thrust/device_vector.h>

typedef thrust::device_vector<double> State;
//typedef std::vector<double> State;

State new_state( size_t N, int i );
void update( const State &x, State &dxdt, double t);
void integrate();
