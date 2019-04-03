#include "mesa.h"

int Mesa::nFilosofos = 5;

Mesa::Mesa() {
  sems = new sem_t[nFilosofos];
  for (int i = 0; i < nFilosofos; ++i) {
    sem_init(&sems[i], 0, 1);
  }
};

Mesa::~Mesa() {
  delete []sems;
}

void
Mesa::tomar_tenedor(int i) {
  sem_wait(&sems[i]);
}

void
Mesa::dejar_tenedor(int i) {
  sem_post(&sems[i]);
}
