#pragma once
#include "mesa.h"

struct InfoFilo {
  InfoFilo(Mesa& mesa, int pos) : mesa(mesa), pos(pos) { }
  Mesa& mesa;
  int pos;
};

typedef InfoFilo* PInfoFilo;
