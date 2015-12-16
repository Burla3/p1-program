#include "p1-program.h"

int main(int argc, const char *argv[]) {
  srand(time(NULL));

  int64_t timeStamp = currentTimestamp();
  int64_t timeStampForEnd = currentTimestamp();

  json_t *rootConfig;
  json_error_t error;

  rootConfig = json_load_file("json/halfDataV2.json", 0, &error);

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

  do {
    printf("----------- Generation %05d -----------\n", generation + 1);

    calculateFitness(population, studyArray);

    timeStamp = printTimeDifferenceMillis(timeStamp, "calculateFitness");

    populationSizeAfterSelection = selection(population);
    currentPopulationSize = populationSizeAfterSelection;

    timeStamp = printTimeDifferenceMillis(timeStamp, "selection");

    int i, sameFitness = 0, averageFitness = 0;

    for (i = 1; i < POPULATION_SIZE; i++) {
      if (population[0].fitnessScore == population[i].fitnessScore) {
        sameFitness++;
      }
      averageFitness += population[i].fitnessScore;
    }
    averageFitness = averageFitness / POPULATION_SIZE;

    printf("----------------------------------------\n\n");
    printf("Generation: %d\nFitness: %d\nAverageFitness: %d\nSameFitness: %d\n\n", generation, population[0].fitnessScore, averageFitness, sameFitness);

    printf("BEST!!\n");
    printf("ID: %5d\tFitness: %d\n", population[0].id, population[0].fitnessScore);
    printf("Amount :%d\nOverlap: %d\nNotsameday: %d\n", population[0].amountScore, population[0].overlapScore, population[0].notsamedayScore);
    for (i = 0; i < population[0].studies[0].numberOfLectures; i++) {
      printf("%5d ", population[0].fitnessPerDay[i]);
    }
    printf("\n");
    printf("----------------------------------------\n");
    printf("WORST!!\n");
    printf("Fitness: %d\n", population[POPULATION_SIZE / 2 - 1].fitnessScore);
    printf("Amount :%d\nOverlap: %d\nNotsameday: %d\n", population[POPULATION_SIZE / 2 - 1].amountScore, population[POPULATION_SIZE / 2 - 1].overlapScore, population[POPULATION_SIZE / 2 - 1].notsamedayScore);
    printf("----------------------------------------\n");
    printf("EVEN WORSE!!\n");
    printf("Fitness: %d\n", population[POPULATION_SIZE - 1].fitnessScore);
    printf("Amount :%d\nOverlap: %d\nNotsameday: %d\n", population[POPULATION_SIZE - 1].amountScore, population[POPULATION_SIZE - 1].overlapScore, population[POPULATION_SIZE - 1].notsamedayScore);
    printf("----------------------------------------\n\n");

    mutateRoom(population, studyArray);

    // BUGGED!
    //currentPopulationSize += mutateRoom1(population, studyArray, currentPopulationSize);

    // for (i = 0; i < populationSizeAfterSelection; i++) {
    //   currentPopulationSize += mutate(population, populationSizeAfterSelection,
    //                                   currentPopulationSize, studyArray);
    // }
    timeStamp = printTimeDifferenceMillis(timeStamp, "mutate");

    while (currentPopulationSize < POPULATION_SIZE) {
      currentPopulationSize += crossoverMix(population, currentPopulationSize, populationSizeAfterSelection);

      // if (currentPopulationSize < POPULATION_SIZE - 1) {
      //   currentPopulationSize += crossoverSlice(population, currentPopulationSize, populationSizeAfterSelection);
      // }
      // if (currentPopulationSize < POPULATION_SIZE - 1) {
      //   currentPopulationSize += crossoverSwitch(population, currentPopulationSize, populationSizeAfterSelection);
      // }
    }

    timeStamp = printTimeDifferenceMillis(timeStamp, "crossover");

    printTimeDifferenceSeconds(timeStampForEnd, "Total runtime");
    generation++;

  } while (population[0].fitnessScore != 0 && generation < MAX_GENERATIONS);
}

/* Aggresive mutate, temp */
void mutateRoom(PopMember *population, Study *studyArray) {
  int i, j, k, l;

  for (i = 0; i < POPULATION_SIZE; i++) {
    for (j = 0; j < population[i].studies[0].numberOfLectures; j++) {
      if (population[i].fitnessPerDay[j] > 0) {
        population[i].fitnessScore = -1;
        for (k = 0; k < population[i].numberOfStudies; k++) {
          if (population[i].studies[k].numberOfLectures > j  && strcmp(population[i].studies[k].lectures[j].type, "PROJEKT") != 0) {
            for (l = 0; l < studyArray[k].numberOfCourses; l++) {
              if (strcmp(population[i].studies[k].lectures[j].type,
                studyArray[k].studyCourses[l].course) == 0) {
                break;
              }
            }
            int numberOfRooms = studyArray[k].studyCourses[l].numberOfRooms;
            int randRoom = getRandomValue(numberOfRooms);

            strcpy(population[i].studies[k].lectures[j].room,
              studyArray[k].studyCourses[l].rooms[randRoom]);
          }
        }
      }
    }
  }
}
