#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../structs.h"

/**
 * OUTDATED
 * There is a chance that the type or room which is picked from lectures, and there is a chance that either one of
 * variables will mutate.
 *
 * @param[in] mutationRate the chance for something to mutate
 * @param[in] parent the parent used for mutation
 * @param[out] offspring the offspring that is generated through mutation
 */
int mutate(PopMember *population, int populationSizeAfterSelection,
            int currentPopulationSize, Study *studyArray);

int getCourseIndex(Study *studyArray, PopMember offspring, int randStudy, int randLecture);

void setRandomRoom(Study *studyArray, PopMember *offspring, int randStudy, int randLecture, int courseIndex);

int mutateRoom1(PopMember *population, Study *studyArray, int currentPopulationSize);
