#include "crossoverSelection.h"

void crossoverSelectionRandom(PopMember population[], int currentPopulationSize, PopMember parent1, PopMember parent2) {
  parent1 = population[getRandomValue(currentPopulationSize)];
  parent2 = population[getRandomValue(currentPopulationSize)];
}
