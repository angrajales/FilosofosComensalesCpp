all: filo_pos_bloqueo

CXXFLAGS=-Wall -std=c++11 -g
LDFLAGS=-pthread

filo_pos_bloqueo: main.o mesa.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: main.cpp mesa.h

mesa.o: mesa.cpp mesa.h

.PHONY: clean

clean:
	rm -f *.o *.*~ *~
	rm -f filo_pos_bloqueo
