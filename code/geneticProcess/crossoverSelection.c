#include "crossoverSelection.h"

void crossoverSelectionRandom(PopMember population[], int currentPopulationSize, PopMember parent1, PopMember parent2) {
  parent1 = population[rand() % currentPopulationSize],
  parent2 = population[rand() % currentPopulationSize];
}