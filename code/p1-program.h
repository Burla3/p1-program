#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "jsonReadToStructs.h"
#include "geneticProcess/geneticProcess.h"
#include "structs.h"
#include "print.h"

int getNumberOfStudies(json_t *rootConfig);

void runGeneticAlgorithm(PopMember *population, Study *studyArray, int numberOfStudies);
