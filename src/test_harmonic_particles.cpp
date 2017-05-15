#include <iostream>
#include <assert.h>
#include "harmonic_particles.h"

#define run_test(fn_name)\
    std::cout << #fn_name;\
    fn_name();\
    std::cout << " *" << std::endl;

void test_create_state_vector() {
    State state = new_state(3,1);
    assert(1 == state[0]);
    assert(1 == state[2]);
}

int main() {
    std::cout << "Tests Begin" << std::endl;
    run_test(test_create_state_vector);
    return 0;
}
