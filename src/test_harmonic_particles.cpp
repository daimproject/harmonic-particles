#include <iostream>
#include <assert.h>
#include "harmonic_particles.h"
#include <array>
#include <complex>

#define run_test(fn_name)\
    std::cout << #fn_name;\
    fn_name();\
    std::cout << " *" << std::endl;

void test_circular_field() {
    auto f = Circular<3>({
            Complex(2,1),
            Complex(4,3),
            Complex(6,5)}, 10 );
    f.print_harmonics();
    auto fp = f(Complex(1,2));
    std::cout << fp.imag() << ", " << fp.real() << std::endl;
}

int main() {
    std::cout << "Tests Begin" << std::endl;
    run_test(test_circular_field);
    return 0;
}

