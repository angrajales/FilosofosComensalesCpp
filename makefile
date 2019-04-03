all: filosofos

CXXFLAGS=-Wall -std=c++11 -g
LDFLAGS=-pthread

filosofos: main.o mesa.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: main.cpp mesa.h

mesa.o: mesa.cpp mesa.h
