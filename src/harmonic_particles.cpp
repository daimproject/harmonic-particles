#include "harmonic_particles.h"
#include <iostream>
#include <boost/numeric/odeint.hpp>
#include <boost/numeric/odeint/external/thrust/thrust.hpp>

using namespace boost::numeric;

State new_state( size_t N, int i )
{
  State state(N);
  thrust::fill(state.begin(), state.end(), i);
  return state;
}

void update( const State &x, State &dxdt, double t)
{
    thrust::fill(dxdt.begin(), dxdt.end(), 1);
}

void integrate() 
{
    State x = new_state(10, 4);
    odeint::runge_kutta4<State> stepper;

    double t0 = 0.0;
    double t1 = 10.0;
    double dt = 0.1;

    odeint::integrate( update, x, t0, t1, dt );
}
