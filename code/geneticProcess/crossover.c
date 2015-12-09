#include "crossover.h"
#include "crossoverSelection.h"

void printParent(PopMember parent) {
  int j,h;

  for (j = 0; j < parent.numberOfStudies; j++) {
    printf("\n%s\n\n", parent.studies[j].studyName);
    for (h = 0; h < parent.studies[j].numberOfLectures; h++) {
      printf("%s\t%s\n", parent.studies[j].lectures[h].type, parent.studies[j].lectures[h].room);
    }
  }
    printf("---------------------------------------\n");
}

int crossoverMix(PopMember population[], int currentPopulationSize) {
  int i, j;

  PopMember parent1, parent2;

  crossoverSelectionRandom(population, &parent1, &parent2);

  /*New popmembers must have a negative fitnessScore*/
  population[currentPopulationSize].fitnessScore = -1;

  for (i = 0; i < parent1.numberOfStudies; i++) {
    for (j = 0; j < parent1.studies[i].numberOfLectures; j++) {
      if (getRandomValue(2) == 0) {
        Lecture temlec = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
        population[currentPopulationSize].studies[i].lectures[j] = temlec;
      } else {
        Lecture temlec = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
        population[currentPopulationSize].studies[i].lectures[j] = temlec;
      }
    }
  }
  return 1;
}

int crossoverSlice(PopMember population[], int currentPopulationSize) {
  int i, j, crossoverPoint;

  PopMember parent1, parent2;
  crossoverSelectionRandom(population, &parent1, &parent2);

  /*New popmembers must have a negative fitnessScore*/
  population[currentPopulationSize].fitnessScore = -1;
  population[currentPopulationSize + 1].fitnessScore = -1;

  for (i = 0; i < parent1.numberOfStudies; i++) {
    crossoverPoint = getRandomValue(parent1.studies[i].numberOfLectures) + 1;

    for (j = 0; j < crossoverPoint; j++) {
      Lecture temlec1 = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
      Lecture temlec2 = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
      population[currentPopulationSize].studies[i].lectures[j] = temlec1;
      population[currentPopulationSize + 1].studies[i].lectures[j] = temlec2;
    }

    for (j = crossoverPoint; j < parent1.studies[i].numberOfLectures; j++) {
      Lecture temlec1 = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
      Lecture temlec2 = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
      population[currentPopulationSize].studies[i].lectures[j] = temlec2;
      population[currentPopulationSize + 1].studies[i].lectures[j] = temlec1;
    }
  }
  return 2;
}
