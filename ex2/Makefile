CFLAGS=-std=c++11
all: main task1 task2 task3

main: main.cpp
	g++ main.cpp $(CFLAGS) -o main.out

task1: task1.cpp
	g++ task1.cpp $(CFLAGS) -o task1.out

task2: task2.cpp
	g++ task2.cpp $(CFLAGS) -o task2.out

task3: task3.cpp burner
	g++ task3.cpp -DP=0.5 $(CFLAGS) -o task3.out burner.out

burner: burner.cpp
	g++ -c burner.cpp $(CFLAGS) -o burner.out

clean:
	rm -rf *.ppm
