#include <thrust/complex.h>
#include <thrust/device_vector.h>
#include <array>
#include <iostream>

using Complex = thrust::complex<double>;

template<int N>
class Circular
{
    Complex harmonics[N];
    const double ref_radius;

    public:

        Circular( Complex harmonics_ [N], const double ref_radius ):
            ref_radius(ref_radius)
            {
                for (int i=0; i<N; i++){
                    harmonics[i] = harmonics_[i];
                }
            }

        __device__
        Complex operator() ( Complex z )
        {
            auto field = Complex(0);
            auto zp = z / ref_radius;
            for (int n=0; n<N; n++){
                field += harmonics[n] * thrust::pow(zp, n);
            }
            return field;
        };

        void print_harmonics()
        {
          for (int n=0; n<N; n++){
              Complex h = harmonics[n];
              std::cout << n << "\t" << h.imag() << "\t" << h.real() << std::endl;
          }
        }
};
