#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>
#include "jsonReadToStructs.h"
#include "geneticProcess/geneticProcess.h"
#include "structs.h"
#include "print.h"
#include "utilities.h"

/**
 * Gets the number of studies from the config object.
 *
 * @param[in] rootConfig Root of the JSON config object.
 * @returns Number of studies in config object.
 */
int getNumberOfStudies(json_t *rootConfig);

/**
 * Runs all the genetic algorithms and contionue to do so, 
 * until a fitness of 0 has been reached or the max number of
 * generations has been reached.
 * 
 * @param[out] population The population which will be altered by the genetic algorithms.
 * @param[in] studyArray The configuration array for each study and courses.
 * @param[in] numberOfStudies The total number of studies.
 * @param[in] timeStampForEnd A timestamp to compare total runtime with after each generation.
 */
void runGeneticAlgorithm(PopMember *population, Study *studyArray, int numberOfStudies, int64_t timeStampForEnd);
