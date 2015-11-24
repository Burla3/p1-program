#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POPULATION 50

typedef struct course {
  char *course;
  int lectures;
} course;

int getTotalLectures(course *courses, int arrayLength);
void initialPopulation(course *courses, char ***population, int arrayLength, int totalLectures);
void generateSchedule(course *courses, char ***population, int arrayLength, int totalLectures, int populationCount);
int getRandomCourse(course *courses, int arrayLength);
void outputSchedule(char ***population, int totalLectures);

int main(void) {
  srand(time(NULL));

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
    population[i] = (char **) malloc(MAX_POPULATION * 4 * sizeof(char));
  }

  initialPopulation(courses, population, arrayLength, totalLectures);

  /*while (fitness < MAX_FITNESS && runTime != 0) {
    calculateFitness();
    reproduction();
    mutation();
    newPopulation();
  }
*/
  outputSchedule(population, totalLectures);



  free(population);

  for (i = 0; i < totalLectures; i++) {
    free(population[i]);
  }

  printf("Done free\n");

  return 0;
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

  for (populationCount = 0; populationCount < MAX_POPULATION; populationCount++) {
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
  /*  if (lectureCount > totalLectures - 5 && (random == 0 || random == 1 || random == 2))
      printf("%d nr er %s\n", lectureCount, courses[random].course); */
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

  for (i = 0; i < MAX_POPULATION; i++) {
    printf("\n\n\n");
    for (j = 0; j < totalLectures; j++) {
      printf("%3s ", population[j][i]);
    }
    printf("\n\n%d\n", i);
  }
  printf("\n");
}
