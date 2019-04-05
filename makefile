.PHONY: all
all: filo_pos_bloqueo filo_no_bloqueo

CXXFLAGS=-Wall -std=c++11 -g
LDFLAGS=-pthread

%: %.o
	$(CXX) -o $@ $^ $(LDFLAGS)

filo_pos_bloqueo: filo_pos_bloqueo.o mesa.o funciones_aux.o

filo_no_bloqueo: filo_no_bloqueo.o mesa.o funciones_aux.o

filo_pos_bloqueo.o: filo_pos_bloqueo.cpp mesa.h infofilo.h funciones_aux.h

filo_no_bloqueo.o: filo_no_bloqueo.cpp mesa.h infofilo.h funciones_aux.h

mesa.o: mesa.cpp mesa.h

funciones_aux.o: funciones_aux.cpp funciones_aux.h

.PHONY: clean

clean:
	rm -f *.o *.*~ *~
	rm -f filo_pos_bloqueo filo_no_bloqueo
