#pragma once
#include <semaphore.h>

class Mesa {
 public:
  static int nFilosofos;
  Mesa();
  ~Mesa();
  void tomar_tenedor(int i);
  void dejar_tenedor(int i);
 private:
  sem_t *sems;
};
