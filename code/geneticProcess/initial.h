#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include "../utilities.h"
#include "../structs.h"

void initialPopulation(PopMember *population, Study *studyArray, int numberOfStudies, json_t *rootConfig);

int getRandomCourse(int array[], int numberOfCourses);
