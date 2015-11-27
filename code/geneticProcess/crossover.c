#include "crossover.h"

void crossoverMix(const int totalLectures, const lecture parent1[],
                  const lecture parent2[],       lecture offspring[]) {
  int i;

  for (i = 0; i < totalLectures; i++) {
    if (rand() % 2 == 0) {
      offspring[i] = parent1[i];
    } else {
      offspring[i] = parent2[i];
    }
  }
}


void crossoverSlice(const int totalLectures, const lecture parent1[], const lecture parent2[],
                                                   lecture offspring1[],    lecture offspring2[]) {
  int crossoverPoint = (rand() % (totalLectures - 1)) + 1;

  int i;

  for (i = 0; i < crossoverPoint; i++) {
    offspring1[i] = parent1[i];
    offspring2[i] = parent2[i];
  }

  for (i = crossoverPoint; i < totalLectures; i++) {
    offspring1[i] = parent2[i];
    offspring2[i] = parent1[i];
  }
}