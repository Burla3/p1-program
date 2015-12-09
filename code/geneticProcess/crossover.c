#include "crossover.h"


int crossoverMix(PopMember population[], int currentPopulationSize) {
  int i, j;

  PopMember parent1, parent2;

  crossoverSelectionRandom(population, parent1, parent2);

  for (i = 0; i < parent1.numberOfStudies; i++) {
    for (j = 0; j < parent1.studies[i].numberOfLectures; j++) {
      if (getRandomValue(2) == 0) {
        population[currentPopulationSize].studies[i].lectures[j] = parent1.studies[i].lectures[j];
      } else {
        population[currentPopulationSize].studies[i].lectures[j] = parent2.studies[i].lectures[j];;
      }
    }
  }
  return 1;
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
