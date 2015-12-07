#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jsonParser.h"
#include "jsonReadToStructs.h"
#include "geneticProcess/geneticProcess.h"
#include "structs.h"

/**
 * Function used to load the initial configurations used in the rest of the program.
 */
void initialConfiguration(json_t *rootConfig);

int getNumberOfStudies(json_t *rootConfig);