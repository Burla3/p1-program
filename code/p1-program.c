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

  for (k = 0; k < numberOfStudies; k++) {
    printStudyStruct(studyArray[k]);
  }

  initialPopulation(population, studyArray, numberOfStudies);

  calculateFitness(population, studyArray);

  int i, j, h;

  for (i = 0; i < POPULATION_SIZE; i++) {
    printf("---------------------------------------\n");
    printf("\nMember: %d\nFitness: %d\n", i+1, population[i].fitnessScore);
    for (j = 0; j < numberOfStudies; j++) {
      printf("\n%s\n\n", population[i].studies[j].studyName);
      for (h = 0; h < population[i].studies[j].numberOfLectures; h++) {
        printf("%s\t%s\n", population[i].studies[j].lectures[h].type, population[i].studies[j].lectures[h].room);
      }
    }
  }


  offspring1 = population[0];

  int currentPopulationSize, generation = 0;

  while (population[0].fitnessScore != 0 && generation < MAX_GENERATIONS) {
    selection(population);

    currentPopulationSize = POPULATION_SIZE / 2;
    for (i = 0; i < POPULATION_SIZE / 2; i++) {
      if (mutate(population[i], offspring) == 1) {
        population[currentPopulationSize] = offspring;
        currentPopulationSize++;
      }
    }
     while (currentPopulationSize < POPULATION_SIZE) {
        currentPopulationSize += crossoverMix(population, currentPopulationSize);
        // crossoverSlice(parent1, parent2, offspring, offspring1);
        // currentPopulationSize += 2;

    }
    generation++;
  }

  printf("---------------------------------------\n");
  printf("\nGeneration: %d\nFitness: %d\n", generation, population[0].fitnessScore);
  for (j = 0; j < numberOfStudies; j++) {
    printf("\n%s\n\n", population[0].studies[j].studyName);
    for (h = 0; h < population[0].studies[j].numberOfLectures; h++) {
      printf("%s\t%s\n", population[0].studies[j].lectures[h].type, population[0].studies[j].lectures[h].room);
    }
  }
  return 0;
}

int getNumberOfStudies(json_t *rootConfig) {
  json_t *groups = json_object_get(rootConfig, "groups");
  return json_array_size(groups);
}
