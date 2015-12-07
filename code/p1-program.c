#include "p1-program.h"

int main(int argc, char *argv[]) {

  json_t *rootConfig = NULL;
  initialConfiguration(rootConfig);

  PopMember *population = (PopMember*) malloc(POPULATION_SIZE * sizeof(PopMember));

  Study *studyArray = (Study*) malloc(getNumberOfStudies(rootConfig) * sizeof(Study));

  populateStudyStructFromConfig(rootConfig, studyArray);

  return 0;
}

void initialConfiguration(json_t *rootConfig) {
  srand(time(NULL));

  rootConfig = loadJSON("json/config.json");

  if (rootConfig == NULL) {
    perror("Error loading JSON ");
  }
}

int getNumberOfStudies(json_t *rootConfig) {
  json_t *groups = json_object_get(rootConfig, "groups");
  return json_array_size(groups);
}