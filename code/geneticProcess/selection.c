#include "selection.h"

int sortPopulation(const void *ep1, const void *ep2) {
  int result;
  PopMember *popMember1 = (PopMember *)ep1,
            *popMember2 = (PopMember *)ep2;

  return popMember1->fitnessScore - timetable2->fitnessScore;
}

void selection(const PopMember population[], PopMember newPopulation[]) {
  int i;

  for (i = 0; i < POPULATION_SIZE / 2; i++) {
    newPopulation[i] = population[i];
  }
}
