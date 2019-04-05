all: filo_pos_bloqueo

CXXFLAGS=-Wall -std=c++11 -g
LDFLAGS=-pthread

filo_pos_bloqueo: filo_pos_bloqueo.o mesa.o
	$(CXX) -o $@ $^ $(LDFLAGS)

filo_pos_bloqueo.o: filo_pos_bloqueo.cpp mesa.h

mesa.o: mesa.cpp mesa.h

.PHONY: clean

clean:
	rm -f *.o *.*~ *~
	rm -f filo_pos_bloqueo
