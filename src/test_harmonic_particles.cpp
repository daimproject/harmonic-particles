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
    const double r = 10;
    Complex mp[] = {Complex(1,2), Complex(3,4), Complex(5,6)};
    auto harmonics = Circular<3>(mp, r);
    harmonics.print_harmonics();
    auto field = harmonics(Complex(1,2));
    std::cout << field.imag() << ", " << field.real() << std::endl;
}

int main() {
    std::cout << "Tests Begin" << std::endl;
    run_test(test_circular_field);
    return 0;
}

