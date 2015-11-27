#include <stdio.h>
#include "jsonParser.h"
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 10000

enum studyName {
  Dat, Mat
};

typedef struct lecture {
  char *type;
  char *room;
} lecture;

typedef struct timetable {
  enum studyName studyName;
  int numberOfLectures;
  lecture *lectures;
} timetable;

typedef struct popMember {
  int fitnessScore;
  timetable *studies;
} popMember;

typedef struct course {
  char *course;
  int lectures;
} course;



/* Global variables */
json_t *rootConfig;

void initialConfiguration();
void jsonExample();
//int getTotalLectures(course *courses, int arrayLength);
void initialPopulation(course *courses, char ***population, int arrayLength, int totalLectures);
void generateSchedule(course *courses, char ***population, int arrayLength, int totalLectures, int populationCount);
int getRandomCourse(course *courses, int arrayLength);
void outputSchedule(char ***population, int totalLectures);
void crossoverMix(const int totalLectures, const lecture parent1[],
                  const lecture parent2[],       lecture offspring[]);
void crossoverSlice(const int totalLectures, const lecture parent1[], const lecture parent2[],
                                                   lecture offspring1[],    lecture offspring2[]);
int mutate(const int mutationRate, const int totalLectures, const lecture parent[], lecture offspring[]);

int main(void) {
  initialConfiguration();
/*
  json_t *value = json_object_get(rootConfig, "courses");

  int totalLectures = 0;

  size_t index;
  json_t *value2, *asdf;

  json_array_foreach(value, index, value2) {
    json_t *asdf = json_object_get(value2, "lectures");

    totalLectures += json_array_size(asdf);
  }

  printf("%i\n", totalLectures);

  //printf("%s\n", json_dumps(json_array_get(value, 0), JSON_INDENT(2)));

  json_decref(asdf);
  json_decref(value);
  json_decref(value2);

  //jsonExample();

  popMember population[POPULATION_SIZE];



  course courses[4];

  course temp1 = {"LIA", 21};
  courses[0] = temp1;
  course temp2 = {"IMP", 14};
  courses[1] = temp2;
  course temp3 = {"PVV", 12};
  courses[2] = temp3;
  course temp4 = {"PRJ", 100};
  courses[3] = temp4;

  int totalLectures, arrayLength = sizeof(courses) / sizeof(courses[0]);

  totalLectures = getTotalLectures(courses, arrayLength);

  int i;
  char ***population = (char ***) malloc(totalLectures *  sizeof(char *));

  for (i = 0; i < totalLectures; i++) {
    population[i] = (char **) malloc(POPULATION_SIZE * 4 * sizeof(char));
  }

  initialPopulation(courses, population, arrayLength, totalLectures);

  while (fitness < MAX_FITNESS && runTime != 0) {
    calculateFitness();
    reproduction();
    mutation();
    newPopulation();
  }

  outputSchedule(population, totalLectures);

  free(population);

  for (i = 0; i < totalLectures; i++) {
    free(population[i]);
  }

  printf("Done free\n");

  return 0;
}

void initialConfiguration() {
  srand(time(NULL));

  rootConfig = loadJSON("json/config.json");

  if (rootConfig == NULL) {
    perror("Error loading JSON ");
  }
}

void jsonExample() {
  json_t *root, *value;

  root = loadJSON("json/config.json");

  if (root == NULL) {
    perror("Error loading JSON ");
  }

  value = json_object_get(root, "check");

  json_decref(root);

  printf("%s\n", json_string_value(value));

  json_decref(value);
}

int getTotalLectures(course *courses, int arrayLength) {
  int i, totalLectures = 0;

  for (i = 0; i < arrayLength; i++) {
    totalLectures += courses[i].lectures;
  }
  return totalLectures;
}

void initialPopulation(course *courses, char ***population, int arrayLength, int totalLectures) {
  int populationCount;

  for (populationCount = 0; populationCount < POPULATION_SIZE; populationCount++) {
    generateSchedule(courses, population, arrayLength, totalLectures, populationCount);
  }
}

void generateSchedule(course *courses, char ***population, int arrayLength, int totalLectures, int populationCount) {
  course tempCourses[arrayLength];
  int i, lectureCount, random;

  for (i = 0; i < arrayLength; i++) {
    tempCourses[i] = courses[i];
  }

  for (lectureCount = 0; lectureCount < totalLectures; lectureCount++) {
    random = getRandomCourse(tempCourses, arrayLength);
    population[lectureCount][populationCount] = courses[random].course;
  }
}

int getRandomCourse(course *courses, int arrayLength) {
  int random = (rand() % arrayLength + 1);

  while (1) {
    if (random == arrayLength) {
      random = arrayLength - 1;
    } else if (courses[random].lectures > 0) {
      courses[random].lectures--;
      return random;
    } else {
      random = (rand() % arrayLength);
    }
  }
}

void outputSchedule(char ***population, int totalLectures) {
  int i, j;

  for (i = 0; i < POPULATION_SIZE; i++) {
    printf("\n\n\n");
    for (j = 0; j < totalLectures; j++) {
      printf("%3s ", population[j][i]);
    }
    printf("\n\n%d\n", i);
  }
  printf("\n");
}

int sortPopulation(const void *ep1, const void *ep2) {
  int result;
  timetable *timetable1 = (timetable *)ep1,
            *timetable2 = (timetable *)ep2;

  if (timetable1->fitnessScore < timetable2->fitnessScore) {
    result = 1;
  } else if (timetable1->fitnessScore > timetable2->fitnessScore) {
    result = -1;
  } else {
    result = 0;
  }

  return result;
}

void selection(const timetable population[], timetable newPopulation[]) {
  int i;

  for (i = 0; i < POPULATION_SIZE / 2; i++) {
    newPopulation[i] = population[i];
  }
}

/**
 * Breeds one offspring by randomly picking lectures from the first or second parent and putting them into the
 * offspring.
 *
 * Example: The parents below could result in ...
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px white; border-right: solid 1px black;
 *    background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *  </tr>
 * </table>
 * ... the offspring below.
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *  </tr>
 * </table>
 *
 * @param[in] totalLectures the total amount of lectures per timetable
 * @param[in] parent1 the first parent used for breeding
 * @param[in] parent2 the second parent used for breeding
 * @param[out] offspring the offspring that is generated through breeding
 */
void crossoverMix(const int totalLectures, const lecture parent1[],
                  const lecture parent2[],       lecture offspring[]) {
  int i;

  for (i = 0; i < totalLectures; i++) {
    if (rand() % 2 == 0) {
      offspring[i] = parent1[i];
    } else {
      offspring[i] = parent2[i];
    }
  }
}

/**
 * Breeds two offsprings by picking a random crossover point for the parents and swapping the right sides with
 * eachother.
 *
 * Example: The parents below with the marked crossover point results in ...
 * <div style="font-size: 24px; float: left; margin-left: 115px;">&darr;</div>
 * <div style="font-size: 24px; margin-left: 355px;">&darr;</div>
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px white; border-right: solid 1px black;
 *    background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *  </tr>
 * </table>
 * ... the offsprings below.
 * <div style="font-size: 24px; float: left; margin-left: 115px;">&darr;</div>
 * <div style="font-size: 24px; margin-left: 355px;">&darr;</div>
 * <table>
 *  <tr>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px white; border-right: solid 1px black;
 *    background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: white;"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *    <td style="width: 25px; height: 25px; border: solid 1px black; background-color: rgb(180, 180, 180);"></td>
 *  </tr>
 * </table>
 *
 * @param[in] totalLectures the total amount of lectures per timetable
 * @param[in] parent1 the first parent used for breeding
 * @param[in] parent2 the second parent used for breeding
 * @param[out] offspring1 the first offspring that is generated through breeding
 * @param[out] offspring2 the second offspring that is generated through breeding
 */
void crossoverSlice(const int totalLectures, const lecture parent1[], const lecture parent2[],
                                                   lecture offspring1[],    lecture offspring2[]) {
  int crossoverPoint = (rand() % (totalLectures - 1)) + 1;

  int i;

  for (i = 0; i < crossoverPoint; i++) {
    offspring1[i] = parent1[i];
    offspring2[i] = parent2[i];
  }

  for (i = crossoverPoint; i < totalLectures; i++) {
    offspring1[i] = parent2[i];
    offspring2[i] = parent1[i];
  }
}

/**
 * There is a chance that the type or room which is picked from lectures, and there is a chance that either one of
 * variables will mutate.
 *
 * @param[in] mutationRate the chance for something to mutate
 * @param[in] totalLectures the total amount of lectures per timetable
 * @param[in] parent the first parent used for breeding
 * @param[out] offspring the first offspring that is generated through breeding
 */
int mutate(const int mutationRate, const int totalLectures, const lecture parent[], lecture offspring[]) {
  int i;
  for (i = 0; i < totalLectures; i++) {
    offspring[i] = parent[i];
  }

  if ((rand() % 100) + 1 <= mutationRate) {
    int randLecture = rand() % totalLectures;
    if (rand() % 2 == 0) {
      offspring[randLecture].type = "Random Type";
    } else {
      offspring[randLecture].room = "Random Room";
    }
    return 1;
  } else {
    return 0;
  }
}
