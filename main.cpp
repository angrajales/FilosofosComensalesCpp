#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include "mesa.h"

using namespace std;

struct InfoFilo {
  InfoFilo(Mesa& mesa, int pos) : mesa(mesa), pos(pos) { }
  Mesa& mesa;
  int pos;
};

void* filosofo(void *arg);

int
main(void) {

  pthread_t hilo_filosofos[Mesa::nFilosofos];

  Mesa *mesa = new Mesa();

  for (int i = 0; i < Mesa::nFilosofos; ++i) {
    InfoFilo *info = new InfoFilo(*mesa,i);
    pthread_create(&hilo_filosofos[i], NULL, filosofo, (void *) info); 
  }

  
  pthread_join(hilo_filosofos[0], NULL);
  return EXIT_SUCCESS;
}

void*
filosofo(void *arg) {
  InfoFilo *info = (InfoFilo *) arg;

  for (;;) {
    // pensando
    cout << "Filosofo: " << info->pos << " pensando" << endl;
    sleep(rand() % 5 + 1);
    info->mesa.tomar_tenedor(info->pos);
    info->mesa.tomar_tenedor((info->pos + 1) % Mesa::nFilosofos);
    // comer
    cout << "Filosofo: " << info->pos << " comiendo" << endl;
    sleep(rand() % 3 + 1);
    info->mesa.dejar_tenedor(info->pos);
    info->mesa.dejar_tenedor((info->pos + 1) % Mesa::nFilosofos);
  }

  return NULL;
}

