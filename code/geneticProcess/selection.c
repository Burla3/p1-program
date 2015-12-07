#include "selection.h"

int sortPopulation(const void *ep1, const void *ep2) {
  int result;
  PopMember *popMember1 = (PopMember *)ep1,
            *popMember2 = (PopMember *)ep2;

  return popMember1->fitnessScore - timetable2->fitnessScore;
}

void selection(PopMember population[], PopMember newPopulation[]) {
  int i;

  PopMember tempPopulation[POPULATION_SIZE];

  for (i = 0; i < POPULATION_SIZE; i++) {
    tempPopulation[i] = population[i];
  }

  qsort(tempPopulation, POPULATION_SIZE, sizeof(PopMember), sortPopulation);

  for (i = 0; i < POPULATION_SIZE / 2; i++) {
    newPopulation[i] = tempPopulation[i];
  }
}
