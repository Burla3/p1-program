#include "selection.h"

int sortPopulation(const void *ep1, const void *ep2) {
  PopMember *popMember1 = (PopMember *)ep1,
            *popMember2 = (PopMember *)ep2;

  return popMember1->fitnessScore - popMember2->fitnessScore;
}

int selection(PopMember population[]) {
  qsort(population, POPULATION_SIZE, sizeof(PopMember), sortPopulation);

  return ((double)SELECTION_PERCENTAGE / 100) * POPULATION_SIZE;
}
