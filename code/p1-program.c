#include "hellofunc.h"

int main(void) {
  srand(time(NULL));
  // call a function in another file
  myPrintHelloMake();

  initialPopulation(inititalPopulationAmount, courses, array);

  while(fitness < MAX_FITNESS) {
    calculateFitness();
    reproduction();
    mutation();
  }

  outputSchedule();

  return 0;
}

void initialPopulation(int inititalPopulationAmount, struct courses[], struct population[][]) {

  for(populationCount = 0; populationCount < populationAmount; populationCount++) {
    for(lectureCount = 0; lectureCount < totalLectures; lectureCount++) {
      random = rand() % (sizeof(courses) / sizeof(courses[0]);
      population[populationCount][lectureCount] = courses[random];
    }
  }
}

void calculateFitness() {
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
​
void outputSchedule() {
​
}
