#include "selection.h"
/*
int sortPopulation(const void *ep1, const void *ep2) {
  int result;
  timetable *timetable1 = (timetable *)ep1,
            *timetable2 = (timetable *)ep2;

  if (timetable1->fitnessScore < timetable2->fitnessScore) {
    result = 1;
  } else if (timetable1->fitnessScore > timetable2->fitnessScore) {
    result = -1;
  } else {
    result = 0;
  }

  return result;
}*/

void selection(const Timetable population[], Timetable newPopulation[]) {
  int i;

  for (i = 0; i < POPULATION_SIZE / 2; i++) {
    newPopulation[i] = population[i];
  }
}
