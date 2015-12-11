#include "p1-program.h"

int main(int argc, const char *argv[]) {
  srand(time(NULL));

  int64_t timeStamp = currentTimestamp();
  int64_t timeStampForEnd = currentTimestamp();

  json_t *rootConfig;
  json_error_t error;

  rootConfig = json_load_file("json/data.json", 0, &error);

  if(error.line != -1) {
    printf("json_load_file returned an invalid line number\n");
  }

  timeStamp = printTimeDifferenceMillis(timeStamp, "json_load_file");

  int numberOfStudies = getNumberOfStudies(rootConfig);

  PopMember *population = (PopMember*) malloc(POPULATION_SIZE * sizeof(PopMember));
  Study *studyArray = (Study*) malloc(numberOfStudies * sizeof(Study));

  populateStudyStructFromConfig(rootConfig, studyArray);

  timeStamp = printTimeDifferenceMillis(timeStamp, "populateStudyStructFromConfig");

  runGeneticAlgorithm(population, studyArray, numberOfStudies, timeStampForEnd);

  timeStamp = printTimeDifferenceMillis(timeStamp, "runGeneticAlgorithm");

  printf("\n\n");

  printTimetables(population, 0);

  timeStamp = printTimeDifferenceMillis(timeStamp, "printTimetables");

  timeStampForEnd = printTimeDifferenceSeconds(timeStampForEnd, "Whole program");

  return 0;
}

int getNumberOfStudies(json_t *rootConfig) {
  json_t *groups = json_object_get(rootConfig, "groups");
  return json_array_size(groups);
}

void runGeneticAlgorithm(PopMember *population, Study *studyArray, int numberOfStudies, int64_t timeStampForEnd) {
  int64_t timeStamp = currentTimestamp();

  initialPopulation(population, studyArray, numberOfStudies);

  timeStamp = printTimeDifferenceMillis(timeStamp, "initialPopulation");

  printf("Done init\n\n");

  int currentPopulationSize, generation = 0;

  do {
    printf("----------- Generation %05d -----------\n", generation + 1);

    calculateFitness(population, studyArray);

    timeStamp = printTimeDifferenceMillis(timeStamp, "calculateFitness");

    currentPopulationSize = selection(SELECTION_PERCENTAGE, population);

    timeStamp = printTimeDifferenceMillis(timeStamp, "selection");

    int i;

    for (i = 0; i < POPULATION_SIZE / 2; i++) {
      currentPopulationSize += mutate(population, currentPopulationSize, studyArray);
    }
    timeStamp = printTimeDifferenceMillis(timeStamp, "mutate");

    while (currentPopulationSize < POPULATION_SIZE) {
      currentPopulationSize += crossoverMix(population, currentPopulationSize);

      if (currentPopulationSize < POPULATION_SIZE - 1) {
        currentPopulationSize += crossoverSlice(population, currentPopulationSize);
      }
      if (currentPopulationSize < POPULATION_SIZE - 1) {
        currentPopulationSize += crossoverSwitch(population, currentPopulationSize);
      }
    }
    timeStamp = printTimeDifferenceMillis(timeStamp, "crossover");
    printTimeDifferenceSeconds(timeStampForEnd, "Total runtime");
    generation++;

    printf("----------------------------------------\n");
    printf("Generation: %d\nFitness: %d\n\n", generation, population[0].fitnessScore);
  } while (population[0].fitnessScore != 0 && generation < MAX_GENERATIONS);
}
