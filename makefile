MPFLAGS := -fopenmp -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -lgomp
NVFLAGS := -Wno-deprecated-gpu-targets -std=c++11
HEADERS := $(wildcard *.h)
CXXFLAGS += -std=c++11 -lboost_program_options

.PHONY: test test-cpu test-gpu cpu gpu all

test: test-cpu

test-cpu: bin/cpu/test_harmonic_particles
	./bin/cpu/test_harmonic_particles

test-gpu: bin/gpu/test_harmonic_particles
	./bin/gpu/test_harmonic_particles

cpu: bin/cpu/fly

gpu: bin/gpu/fly


bin/cpu/test_harmonic_particles: obj/cpu/test_harmonic_particles.o obj/cpu/harmonic_particles.o | bin/cpu
	$(CXX) $(CXXFLAGS) $(MPFLAGS) $(LDFLAGS) -o bin/cpu/test_harmonic_particles $^

bin/gpu/test_harmonic_particles: obj/gpu/test_harmonic_particles.o obj/gpu/harmonic_particles.o | bin/gpu
	nvcc $(NVFLAGS) $(LDFLAGS) -Xcompiler "$(CXXFLAGS)" -o bin/gpu/test_harmonic_particles $^
	
bin/cpu/fly: obj/cpu/fly.o obj/cpu/harmonic_particles.o | bin/cpu
	$(CXX) $(CXXFLAGS) $(MPFLAGS) $(LDFLAGS) -o bin/cpu/fly $^

bin/gpu/fly: obj/gpu/fly.o obj/gpu/harmonic_particles.o | bin/gpu
	nvcc $(NVFLAGS) $(LDFLAGS) -Xcompiler "$(CXXFLAGS)" -o bin/gpu/fly $^

obj/cpu/%.o: src/%.cpp $(HEADERS) | obj/cpu
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(MPFLAGS) -o $@ -c $< 

obj/gpu/%.o: src/%.cpp $(HEADERS) | obj/gpu
	nvcc $(NVFLAGS) $(LDFLAGS) -Xcompiler "$(CXXFLAGS)" -x cu -o $@ -c $< 

obj/cpu:
	mkdir -p obj/cpu

obj/gpu:
	mkdir -p obj/gpu

bin/cpu:
	mkdir -p bin/cpu

bin/gpu:
	mkdir -p bin/gpu

clean:
	rm -rf obj bin

