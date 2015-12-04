#include <jansson.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

void populateStudyStructFromConfig(json_t *rootConfig, Study *studyArray);
int hasCourseId(json_t *array, int id);
void printStudyStruct(Study study);
int getTotalNumberOfRooms(json_t *rootConfig);