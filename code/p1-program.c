#include "p1-program.h"

int main(int argc, const char *argv[]) {

  srand(time(NULL));

  json_t *rootConfig = loadJSON("json/config.json");

  if (rootConfig == NULL) {
    perror("Error loading JSON ");
  }

  int numberOfStudies = getNumberOfStudies(rootConfig);

  PopMember *population = (PopMember*) malloc(POPULATION_SIZE * sizeof(PopMember));
  Study *studyArray = (Study*) malloc(numberOfStudies * sizeof(Study));

  populateStudyStructFromConfig(rootConfig, studyArray);

  int k;

  for (k = 0; k < numberOfStudies; k++)
  {
    printStudyStruct(studyArray[k]);
  }

  initialPopulation(population, studyArray, numberOfStudies, rootConfig);

  calculateFitness(population, studyArray);

  int i, j, h;

  for (i = 0; i < POPULATION_SIZE; i++)
  {
    printf("%d\n", population[i].fitnessScore);
    for (j = 0; j < numberOfStudies; j++)
    {
      for (h = 0; h < population[i].studies[j].numberOfLectures; h++)
      {
        printf("%s\t%s\n", population[i].studies[j].lectures[h].type, population[i].studies[j].lectures[h].room);
      }
    }
  }  

  return 0;
}

int getNumberOfStudies(json_t *rootConfig) {
  json_t *groups = json_object_get(rootConfig, "groups");
  return json_array_size(groups);
}