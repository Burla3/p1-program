#include "selection.h"

int sortPopulation(const void *ep1, const void *ep2) {
  PopMember *popMember1 = (PopMember *)ep1,
            *popMember2 = (PopMember *)ep2;

  int i, result, goodDays1, goodDays2, highestFitness1 = 0, highestFitness2 = 0;

  for (i = 0; i < popMember1->studies[0].numberOfLectures; i++) {
    if (popMember1->fitnessPerDay[i] == 0) {
      goodDays1++;
    } else {
      if (highestFitness1 < popMember1->fitnessPerDay[i]){
        highestFitness1 = popMember1->fitnessPerDay[i];
      }
    }

    if (popMember2->fitnessPerDay[i] == 0) {
      goodDays2++;
    } else {
      if (highestFitness2 < popMember1->fitnessPerDay[i]) {
        highestFitness2 = popMember1->fitnessPerDay[i];
      }
    }
  }

  if (popMember1->fitnessScore < popMember2->fitnessScore) {
    result = -1;
  } else if (popMember1->fitnessScore > popMember2->fitnessScore) {
    result = 1;
  } else {
    if (goodDays1 < goodDays2) {
      result = -1;
    } else if (goodDays1 > goodDays2) {
      result = 1;
    } else {
      if (highestFitness1 < highestFitness2) {
        result = -1;
      } else if (highestFitness1 > highestFitness2) {
        result = 1;
      } else {
        result = 0;
      }
    }
  }

  return result;
}

int selection(PopMember population[]) {
  qsort(population, POPULATION_SIZE, sizeof(PopMember), sortPopulation);

  return ((double)SELECTION_PERCENTAGE / 100) * POPULATION_SIZE;
}
