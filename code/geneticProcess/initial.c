#include "initial.h"

void initialPopulation(Course courses[], PopMember population[]) {
  int i, j, k, randomCourse, coursesLength, roomsLength;

  for (i = 0; i < POPULATION_SIZE; i++) {
    Timetable *studies = (Timetable*) malloc(STUDIES * sizeof(Timetable));
    PopMember member = {-1, studies};
    population[i] = member;
    for (j = 0; j < STUDIES; j++) {
      Lecture *lectures = (Lecture*) malloc(totalLectures * sizeof(Lecture));
      Timetable study = {j, totalLectures, lectures};
      population[i].studies[j] = study;
      for (k = 0; k < totalLectures; k++) {
        randomCourse = getRandomCourse(array[j].courses, array[j].numberOfCourses);
        randomRoom = getRandomRoom(array[j].courses, array[j].array[randomCourse].numberOfRooms);
        Lecture singleLecture = {array[j].courses[randomCourse].course, array[j].courses[randomRoom].rooms};
        population[i].studies[j].lectures[k] = singleLecture;
      }
    }
  }
}

int getRandomCourse(course courses[], int coursesLength) {
  int random = (rand() % coursesLength);

  while (1) {
    if (random == coursesLength) {
      random = coursesLength - 1;
    } else if (array[j].courses[random].lectures > 0) {
      arrray[j].courses[random].lectures--;
      return random;
    } else {
      random = (rand() % coursesLength);
    }
  }
}

int getRandomRoom(course courses[], int roomsLength) {
  return (rand() % array[j].array[j].numberOfRooms);
}
