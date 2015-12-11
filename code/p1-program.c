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

  int currentPopulationSize, populationSizeAfterSelection;
  int generation = 0;

  int sameFitness = 0;
  int mutateMulti = 0;

  do {
    printf("----------- Generation %05d -----------\n", generation + 1);

    sameFitness = population[0].fitnessScore;

    calculateFitness(population, studyArray);

    printf("Generation: %d\nFitness: %d\n\n", generation, population[0].fitnessScore);
    printf("BEST!!\n");
    printf("Amount :%d\nOverlap: %d\nNotsameday: %d\n", population[0].amountScore, population[0].overlapScore, population[0].notsamedayScore);
    printf("----------------------------------------\n");
    printf("WORST!!\n");
    printf("Fitness: %d\n", population[POPULATION_SIZE / 2].fitnessScore);
    printf("Amount :%d\nOverlap: %d\nNotsameday: %d\n", population[POPULATION_SIZE / 2 - 1].amountScore, population[POPULATION_SIZE / 2 - 1].overlapScore, population[POPULATION_SIZE / 2 - 1].notsamedayScore);
    printf("----------------------------------------\n");
    printf("EVEN WORSE!!\n");
    printf("Fitness: %d\n", population[POPULATION_SIZE - 1].fitnessScore);
    printf("Amount :%d\nOverlap: %d\nNotsameday: %d\n", population[POPULATION_SIZE - 1].amountScore, population[POPULATION_SIZE - 1].overlapScore, population[POPULATION_SIZE - 1].notsamedayScore);

    printf("----------------------------------------\n\n");

    timeStamp = printTimeDifferenceMillis(timeStamp, "calculateFitness");

    populationSizeAfterSelection = selection(SELECTION_PERCENTAGE, population);
    currentPopulationSize = populationSizeAfterSelection;

    timeStamp = printTimeDifferenceMillis(timeStamp, "selection");

    if (population[0].fitnessScore == sameFitness && mutateMulti < 20) {
      mutateMulti++;
    } else {
      mutateMulti = 0;
    }

    int i;

    for (i = 0; i < populationSizeAfterSelection; i++) {
      currentPopulationSize += mutate(population, populationSizeAfterSelection,
                                      currentPopulationSize, studyArray, mutateMulti);
    }
    printf("Mutation rate is: %d\n", mutateMulti * MUTATION_RATE);
    timeStamp = printTimeDifferenceMillis(timeStamp, "mutate");

    while (currentPopulationSize < POPULATION_SIZE) {
      currentPopulationSize += crossoverMix(population, currentPopulationSize, populationSizeAfterSelection);

      if (currentPopulationSize < POPULATION_SIZE - 1) {
        currentPopulationSize += crossoverSlice(population, currentPopulationSize, populationSizeAfterSelection);
      }
      if (currentPopulationSize < POPULATION_SIZE - 1) {
        currentPopulationSize += crossoverSwitch(population, currentPopulationSize, populationSizeAfterSelection);
      }
      /*printf("%d %d\n", populationSizeAfterSelection, currentPopulationSize);*/
    }

    timeStamp = printTimeDifferenceMillis(timeStamp, "crossover");
    printTimeDifferenceSeconds(timeStampForEnd, "Total runtime");
    generation++;

  } while (population[0].fitnessScore != 0 && generation < MAX_GENERATIONS);
}
