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

int getNumberOfStudies(json_t *rootConfig);

void runGeneticAlgorithm(PopMember *population, Study *studyArray, int numberOfStudies);
