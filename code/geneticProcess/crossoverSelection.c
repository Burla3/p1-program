#include "crossoverSelection.h"

void crossoverSelectionRandom(PopMember population[], PopMember *parent1, 
							  PopMember *parent2, int populationSizeAfterSelection) {
  *parent1 = population[getRandomValue(populationSizeAfterSelection)];
  *parent2 = population[getRandomValue(populationSizeAfterSelection)];
}
