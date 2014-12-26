#CFLAGS=-std=c++11 -lboost_iostreams -lboost_system -lboost_filesystem
CFLAGS=-std=c++11
all: random1 random2 random3

random1: random1.cpp
	g++ random1.cpp $(CFLAGS) -o random1.out

random2: random1.cpp
	g++ random2.cpp $(CFLAGS) -o random2.out

random3: random1.cpp
	g++ random3.cpp $(CFLAGS) -o random3.out

#data: data.txt
#	./plot.sh &
