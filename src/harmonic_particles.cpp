#include "harmonic_particles.h"

Circular::Circular( Harmonics field_harmonics, double reference_radius ) 
            : harmonics(field_harmonics), ref_radius(reference_radius) {} ;

void Circular::operator() ( const State &x , State &dxdt , const double t )
{
    dxdt[0] = x[1];
    dxdt[1] = -x[0] - ref_radius*x[1];
};


