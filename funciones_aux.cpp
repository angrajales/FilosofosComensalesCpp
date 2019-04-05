#include "funciones_aux.h"
#include <semaphore.h>
#include <iostream>

using namespace std;

static sem_t *imprimirFiloMutex = nullptr;

static void crearMutex() {
  if (imprimirFiloMutex == nullptr) {
    imprimirFiloMutex = new sem_t;
    sem_init(imprimirFiloMutex, 0, 1);
  }
}

void imprimirFilo(int i, const char* mensaje) {
  crearMutex();

  sem_wait(imprimirFiloMutex);
  cout << "Filosofo: " << i
       << mensaje << endl;
  sem_post(imprimirFiloMutex);
}
