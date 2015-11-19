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


  random = rand() % sizeof(courses);

  for()
  population[populationCount][totalCount] = courses[random]



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
