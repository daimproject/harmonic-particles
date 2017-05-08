SOURCE := src/fly.cu
TARGET := bin/fly

cpu: $(SOURCE)
	g++ -O2 -o $(TARGET) -x c++ $(SOURCE) -fopenmp -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -lgomp

gpu: $(SOURCE)
	nvcc -O2 -o $(TARGET) $(SOURCE)
