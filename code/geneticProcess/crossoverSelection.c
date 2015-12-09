#include "crossoverSelection.h"

void printParent2(PopMember parent) {
  int j,h;

  for (j = 0; j < parent.numberOfStudies; j++) {
    printf("\n%s\n\n", parent.studies[j].studyName);
    for (h = 0; h < parent.studies[j].numberOfLectures; h++) {
      printf("%s\t%s\n", parent.studies[j].lectures[h].type, parent.studies[j].lectures[h].room);
    }
  }
    printf("---------------------------------------\n");
}

void crossoverSelectionRandom(PopMember population[], PopMember parent1, PopMember parent2) {
  parent1 = population[getRandomValue(POPULATION_SIZE / 2)];
  printParent2(parent1);
  parent2 = population[getRandomValue(POPULATION_SIZE / 2)];
}
