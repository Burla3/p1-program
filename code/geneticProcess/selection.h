#include <stdlib.h>
#include "../structs.h"

/**
 * Compare function used together with qsort to sort the population by placing PopMembers with the lowest fitnessScore
 * before the ones with a higher fitnessScore.
 */
int sortPopulation(const void *ep1, const void *ep2);

/**
 * Sorts the population and copies the best half into the new population.
 *
 * @param[out] population[] the population that will be sorted and selected from
 *
 * @return returns an integer that marks how much of the population is selected for further processing
 */
int selection(PopMember population[]);
