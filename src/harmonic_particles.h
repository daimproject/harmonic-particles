#include <iostream>
#include <complex.h>
#include <thrust/device_vector.h>

typedef thrust::device_vector<double> State;
typedef std::vector<std::complex<double>> Harmonics;

class Circular
{
    double ref_radius;
    Harmonics harmonics;

    public:
        Circular( Harmonics field_harmonics, double ref_radius );
        void operator() ( const State &x , State &dxdt , const double t );
};
