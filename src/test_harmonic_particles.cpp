#include <iostream>
#include <assert.h>
#include "harmonic_particles.h"

#define run_test(fn_name)\
    std::cout << #fn_name;\
    fn_name();\
    std::cout << " *" << std::endl;

void test_circular_field() {
    Harmonics harmonics {1, 2, 3};
    auto f = Circular(harmonics, 5 );
}

int main() {
    std::cout << "Tests Begin" << std::endl;
    run_test(test_circular_field);
    return 0;
}

