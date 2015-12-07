#include "crossover.h"

void crossoverMix(int totalStudies, int totalLectures, PopMember parent1, PopMember parent2, PopMember offspring) {
  int i, j;

  for (i = 0; i < totalStudies; i++) {
    for (j = 0; j < totalLectures; j++) {
      if (rand() % 2 == 0) {
        offspring.studies[i].lectures[j] = parent1.studies[i].lectures[j];
      } else {
        offspring.studies[i].lectures[j] = parent2.studies[i].lectures[j];;
      }
    }
  }
}


void crossoverSlice(int totalStudies, int totalLectures, PopMember parent1, PopMember parent2,
                                                         PopMember offspring1, PopMember offspring2) {
  int i, j, crossoverPoint;

  for (i = 0; i < totalStudies; i++) {
    crossoverPoint = (rand() % (totalLectures - 1)) + 1;

    for (j = 0; j < crossoverPoint; j++) {
      offspring1.studies[i].lectures[j] = parent1.studies[i].lectures[j];
      offspring2.studies[i].lectures[j] = parent2.studies[i].lectures[j];
    }

    for (j = crossoverPoint; j < totalLectures; j++) {
      offspring1.studies[i].lectures[j] = parent2.studies[i].lectures[j];
      offspring2.studies[i].lectures[j] = parent1.studies[i].lectures[j];
    }
  }
}
