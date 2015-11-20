#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct course {
  char *course;
  int lectures;
} course;

void initialPopulation(int inititalPopulationAmount, course *courses,
                       course *population[inititalPopulationAmount][totalLectures], int arrayLength, int totalLectures);
int getTotalLectures(course *courses, int arrayLength);
int getRandomCourse(course *courses, int arrayLength);

int main(void) {
  srand(time(NULL));

  course courses[3];

  course temp1 = {"LIAL", 25};
  courses[0] = temp1;
  course temp2 = {"IMP", 20};
  courses[1] = temp2;
  course temp3 = {"PV", 12};
  courses[2] = temp3;
  course temp4 = {"PRJ", 35};
  courses[3] = temp4;

  int inititalPopulationAmount = 10, totalLectures, arrayLength = sizeof(courses);

  totalLectures = getTotalLectures(courses, arrayLength);

  course population[inititalPopulationAmount][totalLectures];

  initialPopulation(inititalPopulationAmount, courses, population, arrayLength, totalLectures);

  /*while (fitness < MAX_FITNESS && runTime != 0) {
    calculateFitness();
    reproduction();
    mutation();
    newPopulation();
  }

  outputSchedule();
*/
  return 0;
}

void initialPopulation(int inititalPopulationAmount, course *courses,
                       course *population[inititalPopulationAmount][totalLectures], int arrayLength, int totalLectures) {
  int random, populationCount, lectureCount;

  for (populationCount = 0; populationCount < inititalPopulationAmount; populationCount++) {
    for (lectureCount = 0; lectureCount < totalLectures; lectureCount++) {
      random = getRandomCourse(courses, arrayLength);
      population[populationCount][lectureCount] = courses[random].course;
    }
  }
}

int getTotalLectures(course *courses, int arrayLength) {
  int i, totalLectures = 0;

  for (i = 0; i < arrayLength; i++) {
    totalLectures += courses[i].lectures;
  }

  return totalLectures;
}

int getRandomCourse(course *courses, int arrayLength) {
  int random = (rand() % arrayLength);
  int randomTemp = random;

  do {
    if (courses[randomTemp].lectures > 0) {
      courses[randomTemp].lectures--;
      return random;
    } else if (randomTemp == arrayLength) {
      randomTemp -= arrayLength;
    } else
      randomTemp++;
  } while(randomTemp != random);
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
​
void outputSchedule() {
​
}
*/
