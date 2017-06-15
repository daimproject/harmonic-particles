#include <thrust/complex.h>
#include <thrust/device_vector.h>
#include <array>
#include <iostream>

using Complex = thrust::complex<double>;

template<int N>
class Circular
{
    const double ref_radius;
    const std::array<Complex, N> harmonics;

    public:
        Circular( std::array<Complex, N> field_harmonics, double ref_radius );
        __device__
        Complex operator() ( Complex z );
        void print_harmonics();
};

template<int N>
Circular<N>::Circular( std::array<Complex, N> field_harmonics, double reference_radius ) 
            : harmonics(field_harmonics), ref_radius(reference_radius) {};

template<int N>
void Circular<N>::print_harmonics()
{
  for (int n=0; n<N; n++){
      Complex h = harmonics[n];
      std::cout << n << "\t" << h.imag() << "\t" << h.real() << std::endl;
  }
}

__device__
template<int N>
Complex Circular<N>::operator() ( Complex z )
{
    auto field = Complex(0);
    auto zp = z / ref_radius;
    for (int n=0; n<N; n++){
        field += harmonics[n] * thrust::pow(zp, n);
    }
    return field;
};
