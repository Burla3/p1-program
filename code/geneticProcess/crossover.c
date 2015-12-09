#include "crossover.h"

void crossoverMix(PopMember parent1, PopMember parent2, PopMember offspring) {
/*  int i, j;



  for (i = 0; i < parent1.numberOfStudies; i++) {
    for (j = 0; j < parent1.studies[i].numberOfLectures; j++) {
      if (getRandomValue(2) == 0) {
        offspring.studies[i].lectures[j] = parent1.studies[i].lectures[j];
      } else {
        offspring.studies[i].lectures[j] = parent2.studies[i].lectures[j];;
      }
    }
  }
  */
}

void crossoverSlice(PopMember parent1, PopMember parent2, PopMember offspring1, PopMember offspring2) {
/*  int i, j, crossoverPoint;

  for (i = 0; i < parent1.numberOfStudies; i++) {
    crossoverPoint = getRandomValue(parent1.studies[i].numberOfLectures - 1) + 1;

    for (j = 0; j < crossoverPoint; j++) {
      offspring1.studies[i].lectures[j] = parent1.studies[i].lectures[j];
      offspring2.studies[i].lectures[j] = parent2.studies[i].lectures[j];
    }

    for (j = crossoverPoint; j < parent1.studies[i].numberOfLectures; j++) {
      offspring1.studies[i].lectures[j] = parent2.studies[i].lectures[j];
      offspring2.studies[i].lectures[j] = parent1.studies[i].lectures[j];
    }
  }
  */
}
