#include <iostream>
#include <assert.h>
#include "fly.cu"

#define run_test(fn_name)\
    std::cout << fn_name << std::endl;\
    fn_name();

void test_create_state_vector() {
    state_type state = new_state_vector(3,1);
    assert(1 == state[0]);
    assert(1 == state[2]);
}

int main() {
    run_test(test_create_state_vector);
    return 0;
}
