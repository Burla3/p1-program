#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POPULATION 5000

typedef struct course {
  char *course;
  int lectures;
} course;

typedef struct lecture {
  char *type;
  char *room;
} lecture;

int getTotalLectures(course *courses, int arrayLength);
void initialPopulation(course *courses, char *population[][MAX_POPULATION], int arrayLength, int totalLectures);
void generateSchedule(course *courses, char *population[][MAX_POPULATION], int arrayLength,
                                                    int totalLectures, int populationCount);
int getRandomCourse(course *courses, int arrayLength);
void outputSchedule(char *population[][MAX_POPULATION], int totalLectures);
void crossoverMix(const int totalLectures, const lecture parent1[],
                  const lecture parent2[],       lecture offspring[]);
void crossoverSlice(const int totalLectures, const lecture parent1[], const lecture parent2[],
                                                   lecture offspring1[],    lecture offspring2[]);

int main(void) {
  srand(time(NULL));
/*
  course courses[4];

  course temp1 = {"LIAL", 21};
  courses[0] = temp1;
  course temp2 = {"IMP", 14};
  courses[1] = temp2;
  course temp3 = {"PV", 12};
  courses[2] = temp3;
  course temp4 = {"PRJ", 50};
  courses[3] = temp4;

  int totalLectures, arrayLength = sizeof(courses) / sizeof(courses[0]);

  totalLectures = getTotalLectures(courses, arrayLength);

  char *population[totalLectures][MAX_POPULATION];

  initialPopulation(courses, population, arrayLength, totalLectures);

  /*while (fitness < MAX_FITNESS && runTime != 0) {
    calculateFitness();
    reproduction();
    mutation();
    newPopulation();
  }*/

  //outputSchedule(population, totalLectures);

  lecture timetable1[] = {{"LIAL", "Aud. 6"}, {"PV", "Seminarrum 302"}, {"IMPR", "Aud. 7"}, {"CS:GO", "Kaffestuen"}};
  lecture timetable2[] = {{"LIAL2", "Aud. 6"}, {"PV2", "Seminarrum 302"}, {"IMPR2", "Aud. 7"}, {"CS:GO2", "Kaffestuen"}};

  lecture offspring1[4];
  lecture offspring2[4];

  /*crossoverMix(4, timetable1, timetable2, offspring1);

  crossoverSlice(4, timetable1, timetable2, offspring1, offspring2);

  int i;

  for (i = 0; i < 4; i++) {
    printf("%i: %s\n", i, offspring1[i].type);
  }

  printf("_________\n");

  for (i = 0; i < 4; i++) {
    printf("%i: %s\n", i, offspring2[i].type);
  }*/

  return 0;
}

int getTotalLectures(course *courses, int arrayLength) {
  int i, totalLectures = 0;

  for (i = 0; i < arrayLength; i++) {
    totalLectures += courses[i].lectures;
  }
  return totalLectures;
}

void initialPopulation(course *courses, char *population[][MAX_POPULATION], int arrayLength, int totalLectures) {
  int populationCount;

  for (populationCount = 0; populationCount < MAX_POPULATION; populationCount++) {
    generateSchedule(courses, population, arrayLength, totalLectures, populationCount);
  }
}

void generateSchedule(course *courses, char *population[][MAX_POPULATION], int arrayLength,
                                                    int totalLectures, int populationCount) {
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
  int random = (rand() % arrayLength);

  while (1) {
    if (courses[random].lectures > 0) {
      courses[random].lectures--;
      return random;
    } else {
      random = (rand() % arrayLength);
    }
  }
}

void outputSchedule(char *population[][MAX_POPULATION], int totalLectures) {
  int i, j;

  for (i = 0; i < MAX_POPULATION; i++) {
    printf("\n\n\n");
    for (j = 0; j < totalLectures; j++) {
      printf("%s ", population[j][i]);
    }
  }
  printf("\n");
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
 * @param totalLectures the total amount of lectures per timetable
 * @param parent1 the first parent used for breeding
 * @param parent2 the second parent used for breeding
 * @param offspring the offspring that is generated through breeding
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
 * @param totalLectures the total amount of lectures per timetable
 * @param parent1 the first parent used for breeding
 * @param parent2 the second parent used for breeding
 * @param offspring1 the first offspring that is generated through breeding
 * @param offspring2 the second offspring that is generated through breeding
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