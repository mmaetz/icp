CFLAGS=-std=c++11
all: main task1 task2

main: main.cpp
	g++ main.cpp $(CFLAGS) -o main.out

task1: task1.cpp
	g++ task1.cpp $(CFLAGS) -o task1.out

task2: task1.cpp
	g++ task2.cpp $(CFLAGS) -o task2.out

clean:
	rm -rf *.ppm
