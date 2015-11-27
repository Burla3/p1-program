#include "initial.h"

void initialPopulation(course courses[], popMember population[], int arrayLength, int totalLectures) {
  int i, j, k, random;

  for (i = 0; i < POPULATION_SIZE; i++) {
    timetable *studies = (timetable*) malloc(2 * sizeof(timetable));
    popMember member = {-1, studies};
    population[i] = member;
    for (j = 0; j < 2; j++) {
      lecture *lectures = (lecture*) malloc(totalLectures * sizeof(lecture));
      timetable study = {j, totalLectures, lectures};
      population[i].studies[j] = study;
      for (k = 0; k < totalLectures; k++) {
        random = getRandomCourse(courses, arrayLength);
        lecture singleLecture = {courses[random].course, "Random Room"};
        population[i].studies[j].lectures[k] = singleLecture;
      }
    }
  }
}

int getRandomCourse(course courses[], int arrayLength) {
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