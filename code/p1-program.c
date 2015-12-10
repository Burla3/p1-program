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

  initialPopulation(population, studyArray, numberOfStudies);

  int currentPopulationSize, generation = 0;

  while (population[0].fitnessScore != 0 && generation < MAX_GENERATIONS) {
    calculateFitness(population, studyArray);

    selection(population);
    currentPopulationSize = POPULATION_SIZE / 2;

    printf("---------------------------------------\n");
    printf("\nGeneration: %d\nFitness: %d\n", generation, population[0].fitnessScore);

    for (i = 0; i < POPULATION_SIZE / 2; i++) {
      currentPopulationSize += mutate(population, currentPopulationSize, studyArray);
    }
    while (currentPopulationSize < POPULATION_SIZE) {
      currentPopulationSize += crossoverMix(population, currentPopulationSize);

      /* Test som ikke virker */
      //currentPopulationSize += crossoverSwitch(population, currentPopulationSize);

      if (currentPopulationSize < POPULATION_SIZE - 1) {
        currentPopulationSize += crossoverSlice(population, currentPopulationSize);
      }
   }
   generation++;
  }
  printf("\n\n");

  printTimetables(population, 0);

  return 0;
}

int getNumberOfStudies(json_t *rootConfig) {
  json_t *groups = json_object_get(rootConfig, "groups");
  return json_array_size(groups);
}
