#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POPULATION 10

typedef struct course {
  char *course;
  int lectures;
} course;

int getTotalLectures(course *courses, int arrayLength);
void initialPopulation(course *courses, char *population[][MAX_POPULATION], int arrayLength, int totalLectures);
void generateSchedule(course *courses, char *population[][MAX_POPULATION], int arrayLength,
                                                    int totalLectures, int populationCount);
int getRandomCourse(course *courses, int arrayLength);
void outputSchedule(char *population[][MAX_POPULATION], int totalLectures);

int main(void) {
  srand(time(NULL));

  course courses[4];

  course temp1 = {"LIAL", 20};
  courses[0] = temp1;
  course temp2 = {"IMP", 20};
  courses[1] = temp2;
  course temp3 = {"PV", 20};
  courses[2] = temp3;
  course temp4 = {"PRJ", 20};
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
  }
*/
  outputSchedule(population, totalLectures);

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
