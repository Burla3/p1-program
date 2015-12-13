#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../structs.h"

/**
 * Mutates the population at a random chance. Mutates the courses of a study and or a room.
 *
 * @param[out] population The population to mutate.
 * @param[in] populationSizeAfterSelection The original size of the population after the selection procces.
 * @param[in] currentPopulationSize The growing population size after the selection procces.
 * @param[in] studyArray The configuration array for each study and courses.
 * @param[in] mutateMulti A multiplier for the mutation rate. Used when the fitness don't change from earlier generation.
 * @returns The number of PopMembers that have been mutated.
 */
int mutate(PopMember *population, int populationSizeAfterSelection, 
            int currentPopulationSize, Study *studyArray, int mutateMulti);

/**
 * Gets the course index for a study found from the random study & lecture parameter. 
 *
 * @param[in] studyArray The configuration array for each study and courses.
 * @param[in] offspring The offspring from the mutation procces.
 * @param[in] randStudy A random study index (from the population).
 * @param[in] randLecture A random lecture index (from the population).
 * @returns A course index found from the random study & lecture.
 */
int getCourseIndex(Study *studyArray, PopMember offspring, int randStudy, int randLecture);

/**
 * Sets a random possible room for the offspring.
 *
 * @param[in] studyArray The configuration array for each study and courses.
 * @param[out] offspring The offspring to change room for from the mutation procces.
 * @param[in] randStudy A random study index (from the population).
 * @param[in] randLecture A random lecture index (from the population).
 * @param[in] courseIndex The index used to set the random room.
 */
void setRandomRoom(Study *studyArray, PopMember *offspring, int randStudy, int randLecture, int courseIndex);
