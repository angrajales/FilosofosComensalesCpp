#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include "mesa.h"
#include "infofilo.h"
#include "funciones_aux.h"

using namespace std;

static void* filosofo(void *arg);

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
    imprimirFilo(info->pos, " pensando");
    sleep(rand() % 5 + 1);
    info->mesa.tomar_tenedor(info->pos);
    info->mesa.tomar_tenedor((info->pos + 1) % Mesa::nFilosofos);
    // comer
    imprimirFilo(info->pos, " comiendo");
    sleep(rand() % 3 + 1);
    info->mesa.dejar_tenedor(info->pos);
    info->mesa.dejar_tenedor((info->pos + 1) % Mesa::nFilosofos);
  }

  return NULL;
}
