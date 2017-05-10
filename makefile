CC := g++
SOURCES := src/*
LDFLAGS := 

test: $(SOURCES)
	mkdir -p bin
	$(CC) -O2 -o bin/test_fly src/test_fly.cpp $(LDFLAGS) -fopenmp -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -lgomp
	./bin/test_fly

cpu: $(SOURCES)
	mkdir -p bin
	$(CC) -O2 -o bin/fly -x c++ src/fly.cu $(LDFLAGS) -fopenmp -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -lgomp

gpu: $(SOURCES)
	mkdir -p bin
	nvcc -O2 -o bin/fly src/fly.cu
