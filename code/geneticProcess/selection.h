#include "../structs.h"
#include <stdlib.h>

/**
 * Compare function used together with qsort to sort the population by placing PopMembers with the lowest fitnessScore
 * before the ones with a higher fitnessScore.
 */
int sortPopulation(const void *ep1, const void *ep2);

/**
 * Sorts the population and copies the best half into the new population.
 *
 * @param[in] population[] the population that is to be sorted and copied
 * @param[out] newPopulation[] the population that will be copied into and become the new population
 */
void selection(PopMember population[], PopMember newPopulation[]);