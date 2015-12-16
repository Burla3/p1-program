#include "crossover.h"
#include "crossoverSelection.h"

void printParent(PopMember parent) {
  int j,h;

  for (j = 0; j < 1; j++) {
    printf("\n%s\n\n", parent.studies[j].studyName);
    for (h = 0; h < 10; h++) {
      printf("%s\t%s\n", parent.studies[j].lectures[h].type, parent.studies[j].lectures[h].room);
    }
  }
    printf("---------------------------------------\n");
}

int crossoverMix(PopMember population[], int currentPopulationSize, int populationSizeAfterSelection) {
  int i, j;

  PopMember parent1, parent2;

  crossoverSelectionRandom(population, &parent1, &parent2, populationSizeAfterSelection);

  /*New popmembers must have a negative fitnessScore*/
  population[currentPopulationSize].fitnessScore = -1;

  for (j = 0; j < parent1.studies[0].numberOfLectures; j++) {
    if (getRandomValue(2) == 0) {
      for (i = 0; i < parent1.numberOfStudies; i++) {
        if (parent1.studies[i].numberOfLectures > j) {
          Lecture temlec = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
          population[currentPopulationSize].studies[i].lectures[j] = temlec;
        }
      }
    } else {
      for (i = 0; i < parent1.numberOfStudies; i++) {
        if (parent1.studies[i].numberOfLectures > j) {
          Lecture temlec = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
          population[currentPopulationSize].studies[i].lectures[j] = temlec;
        }
      }
    }
  }

  return 1;
}

int crossoverSlice(PopMember population[], int currentPopulationSize, int populationSizeAfterSelection) {
  int i, j, crossoverPoint;

  PopMember parent1, parent2;
  crossoverSelectionRandom(population, &parent1, &parent2, populationSizeAfterSelection);

  /*New popmembers must have a negative fitnessScore*/
  population[currentPopulationSize].fitnessScore = -1;
  population[currentPopulationSize + 1].fitnessScore = -1;

  crossoverPoint = getRandomValue(parent1.studies[0].numberOfLectures) + 1;

  for (j = 0; j < crossoverPoint; j++) {
    for (i = 0; i < parent1.numberOfStudies; i++) {
      if (parent1.studies[i].numberOfLectures > j && parent2.studies[i].numberOfLectures > j) {
        Lecture temlec1 = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
        Lecture temlec2 = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
        population[currentPopulationSize].studies[i].lectures[j] = temlec1;
        population[currentPopulationSize + 1].studies[i].lectures[j] = temlec2;
      }
    }


  for (j = crossoverPoint; j < parent1.studies[0].numberOfLectures; j++) {
    for (i = 0; i < parent1.numberOfStudies; i++) {
      if (parent1.studies[i].numberOfLectures > j && parent2.studies[i].numberOfLectures > j) {
        Lecture temlec1 = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
        Lecture temlec2 = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
        population[currentPopulationSize].studies[i].lectures[j] = temlec2;
        population[currentPopulationSize + 1].studies[i].lectures[j] = temlec1;
      }
    }
  }

  return 2;
}

int crossoverSwitch(PopMember population[], int currentPopulationSize, int populationSizeAfterSelection) {
  int i, j, k, crossoverPoint;

  PopMember parent1, parent2;
  crossoverSelectionRandom(population, &parent1, &parent2, populationSizeAfterSelection);

  /*New popmembers must have a negative fitnessScore*/
  population[currentPopulationSize].fitnessScore = -1;
  population[currentPopulationSize + 1].fitnessScore = -1;

  crossoverPoint = getRandomValue(parent1.studies[0].numberOfLectures) + 1;

  for (j = 0, k = parent1.studies[0].numberOfLectures - 1; j < crossoverPoint; j++, k--) {
    for (i = 0; i < parent1.numberOfStudies; i++) {
      if (parent1.studies[i].numberOfLectures > j && parent2.studies[i].numberOfLectures > j) {
        Lecture temlec1 = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
        Lecture temlec2 = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
        population[currentPopulationSize].studies[i].lectures[k] = temlec1;
        population[currentPopulationSize + 1].studies[i].lectures[k] = temlec2;
      }
    }
  }
  for (j = crossoverPoint, k = parent1.studies[0].numberOfLectures - crossoverPoint - 1; j < parent1.studies[0].numberOfLectures; j++, k--) {
    for (i = 0; i < parent1.numberOfStudies; i++) {
      if (parent1.studies[i].numberOfLectures > j && parent2.studies[i].numberOfLectures > j) {
        Lecture temlec1 = {parent1.studies[i].lectures[j].type, parent1.studies[i].lectures[j].room};
        Lecture temlec2 = {parent2.studies[i].lectures[j].type, parent2.studies[i].lectures[j].room};
        population[currentPopulationSize].studies[i].lectures[k] = temlec2;
        population[currentPopulationSize + 1].studies[i].lectures[k] = temlec1;
      }
    }
  }

  return 2;
}
