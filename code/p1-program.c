#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LECTURES 80


/*typedef struct lecture {
  char *room;
} lecture; */

typedef struct course {
  char *course;
  int lectures;
} course;

void initialPopulation(int inititalPopulationAmount, course *courses,
                       char* population[10][MAX_LECTURES], int arrayLength, int totalLectures);
int getTotalLectures(course *courses, int arrayLength);
void generateSchedule( course *courses, char* population[10][MAX_LECTURES], int arrayLength, int totalLectures, int populationCount);
int getRandomCourse(course *courses, int arrayLength);
void outputSchedule(char* population[10][MAX_LECTURES]);


int main(void) {
  srand(time(NULL));

  int i;

  course courses[4];

  course temp1 = {"LIAL", 20};
  courses[0] = temp1;
  course temp2 = {"IMP", 20};
  courses[1] = temp2;
  course temp3 = {"PV", 20};
  courses[2] = temp3;
  course temp4 = {"PRJ", 20};
  courses[3] = temp4;

  int inititalPopulationAmount = 10, totalLectures, arrayLength = sizeof(courses) / sizeof(courses[0]);

  totalLectures = getTotalLectures(courses, arrayLength);

  char* population[inititalPopulationAmount][totalLectures];

  initialPopulation(inititalPopulationAmount, courses, population, arrayLength, totalLectures);

  /*while (fitness < MAX_FITNESS && runTime != 0) {
    calculateFitness();
    reproduction();
    mutation();
    newPopulation();
  }
*/

  outputSchedule(population);

  return 0;
}

void initialPopulation(int inititalPopulationAmount, course *courses,
                       char* population[10][MAX_LECTURES], int arrayLength, int totalLectures) {
  int populationCount;

  for (populationCount = 0; populationCount < inititalPopulationAmount; populationCount++) {
    printf("\n\n");
    generateSchedule(courses, population, arrayLength, totalLectures, populationCount);
  }
}

int getTotalLectures(course *courses, int arrayLength) {
  int i, totalLectures = 0;

  for (i = 0; i < arrayLength; i++) {
    totalLectures += courses[i].lectures;
  }
  return totalLectures;
}

void generateSchedule(course *courses, char* population[10][MAX_LECTURES], int arrayLength, int totalLectures, int populationCount) {
  course tempCourses[arrayLength];
  int i, lectureCount, random;

  for (i = 0; i < arrayLength; i++) {
    tempCourses[i] = courses[i];
  }

  for (lectureCount = 0; lectureCount < totalLectures; lectureCount++) {
    random = getRandomCourse(tempCourses, arrayLength);
    population[populationCount][lectureCount] = courses[random].course;
  }
}

int getRandomCourse(course *courses, int arrayLength) {
  int random = (rand() % arrayLength);

  while (1) {
    if (courses[random].lectures > 0) {
      courses[random].lectures--;
      printf("SE: %d ", random);
      return random;
    } else {
      random = (rand() % arrayLength);
    }
  }


  /*int randomTemp = random;

  do {
    if (randomTemp == arrayLength) {
      randomTemp -= arrayLength;
    } else if (courses[randomTemp].lectures > 0) {
      courses[randomTemp].lectures--;
      printf("SE: %d ", randomTemp);
      return randomTemp;
    } else {
      printf("OP: %d ", randomTemp);
      randomTemp++;
    }
  } while(randomTemp != 5);
  */
}


/*void calculateFitness() {
​
}
​
void reproduction() {
​
}
​
void mutation() {
​
}

void newPopulation() {


}
​*/
void outputSchedule(char* population[10][MAX_LECTURES]) {
  int i, j;

  for (i = 0; i < 10; i++) {
    printf("\n\n\n");
    for (j = 0; j < MAX_LECTURES; j++) {
      printf("%s ", population[i][j]);
    }
  }
}
