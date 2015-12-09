#include "crossoverSelection.h"

void crossoverSelectionRandom(PopMember population[], PopMember *parent1, PopMember *parent2) {
  *parent1 = population[getRandomValue(POPULATION_SIZE / 2)];
  *parent2 = population[getRandomValue(POPULATION_SIZE / 2)];
}
