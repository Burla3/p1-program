#include "utilities.h"

int getRandomValue(int upper) {
  if (upper == 0) {
    return 0;
  }

  return rand() % upper;
}