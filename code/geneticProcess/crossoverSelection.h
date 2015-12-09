#include <stdlib.h>
#include "../utilities.h"
#include "../structs.h"

/**
 * Selects two random population members for crossover.
 *
 * @param[in] population[] the population that two parents will be selected from randomly
 * @param[in] currentPopulationSize the current size of the population which is used as a limit for selecting randomly
 * @param[out] parent1 the first parent that is selected from the population
 * @param[out] parent2 the second parent that is selected from the population
 */
void crossoverSelectionRandom(PopMember population[], int currentPopulationSize, PopMember parent1, PopMember parent2);
