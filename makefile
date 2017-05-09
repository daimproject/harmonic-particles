CC := g++
SOURCE := src/fly.cu
TARGET := bin/fly
LDFLAGS := 

cpu: $(SOURCE)
	$(CC) -O2 -o $(TARGET) -x c++ $(SOURCE) $(LDFLAGS) -fopenmp -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -lgomp

gpu: $(SOURCE)
	nvcc -O2 -o $(TARGET) $(SOURCE)
