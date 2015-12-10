#include "p1-program.h"

int main(int argc, const char *argv[]) {
  srand(time(NULL));

  /*struct timeval tStart, tStop;
  float elapsed;

  gettimeofday(&tStart, NULL);*/

  json_t *rootConfig;
  json_error_t error;

  rootConfig = json_load_file("json/data.json", 0, &error);

  if(error.line != -1) {
    printf("json_load_file returned an invalid line number\n");
  }

  /*gettimeofday(&tStop, NULL);
  elapsed = timeDifferenceMillis(tStart, tStop);
  printf("%s in %f milliseconds.\n", "asdf", elapsed);
  gettimeofday(&tStart, 0);*/

  //printTimeDifferenceMillis(&tStart, "Config file read by Jansson");

  int numberOfStudies = getNumberOfStudies(rootConfig);


  PopMember *population = (PopMember*) malloc(POPULATION_SIZE * sizeof(PopMember));
  Study *studyArray = (Study*) malloc(numberOfStudies * sizeof(Study));

  populateStudyStructFromConfig(rootConfig, studyArray);

  int i;

  /*for (i = 0; i < numberOfStudies; i++)
  {
    printf("\n\n");
    printStudyStruct(studyArray[i]);
  }*/

  /*gettimeofday(&tStop, NULL);
  elapsed = timeDifferenceMillis(tStart, tStop);
  printf("%s in %f milliseconds.\n", "asdf", elapsed);*/
  //gettimeofday(&tStart, NULL);

  //printTimeDifferenceMillis(&tStart, "populateStudyStructFromConfig");

  runGeneticAlgorithm(population, studyArray, numberOfStudies);

  printf("\n\n");

  printTimetables(population, 0);


  return 0;
}

int getNumberOfStudies(json_t *rootConfig) {
  json_t *groups = json_object_get(rootConfig, "groups");
  return json_array_size(groups);
}

void runGeneticAlgorithm(PopMember *population, Study *studyArray, int numberOfStudies) {
  initialPopulation(population, studyArray, numberOfStudies);

  printf("Done init\n");

  int currentPopulationSize, generation = 0;

  do {
    calculateFitness(population, studyArray);

    selection(population);
    currentPopulationSize = POPULATION_SIZE / 2;


    int i;

    for (i = 0; i < POPULATION_SIZE / 2; i++) {
      currentPopulationSize += mutate(population, currentPopulationSize, studyArray);
    }

    while (currentPopulationSize < POPULATION_SIZE) {
      currentPopulationSize += crossoverMix(population, currentPopulationSize);

      /* Test som ikke virker */
      //currentPopulationSize += crossoverSwitch(population, currentPopulationSize);

      if (currentPopulationSize < POPULATION_SIZE - 1) {
        //currentPopulationSize += crossoverSlice(population, currentPopulationSize);
      }
   }
   generation++;

   printf("---------------------------------------\n");
   printf("\nGeneration: %d\nFitness: %d\n", generation, population[0].fitnessScore);
 } while (population[0].fitnessScore != 0 && generation < MAX_GENERATIONS);
}
