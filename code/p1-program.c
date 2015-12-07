#include <string.h>
#include "p1-program.h"
#include "structs.h"

/* Global variables */
json_t *rootConfig;

int main(int argc, char *argv[]) {
  initialConfiguration();

  /*PopMember *population = (PopMember*) malloc(POPULATION_SIZE * sizeof(PopMember));*/

  json_t *groups = json_object_get(rootConfig, "groups");
  int numberOfStudies = json_array_size(groups);

  Study *studyArray = (Study*) malloc(numberOfStudies * sizeof(Study));

  populateStudyStructFromConfig(rootConfig, studyArray);

  /*int i;

  for (i = 0; i < numberOfStudies; i++)
  {
    printStudyStruct(studyArray[i]);
  }*/

  return 0;
}

void initialConfiguration() {
  srand(time(NULL));

  rootConfig = loadJSON("json/config.json");

  if (rootConfig == NULL) {
    perror("Error loading JSON ");
  }
}
