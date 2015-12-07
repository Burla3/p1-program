#include "initial.h"

void initialPopulation(PopMember *population, Study *studyArray, int numberOfStudies) {
  int i, j, k, l, randomCourse, randomRoom, totalNumberOfLectures;

  for (i = 0; i < POPULATION_SIZE; i++) {
    Timetable *studies = (Timetable*) malloc(numberOfStudies * sizeof(Timetable));
    PopMember member = {-1, studies};
    population[i] = member;
    for (j = 0; j < numberOfStudies; j++) {
      totalNumberOfLectures = studyArray[j].totalNumberOfLectures;
      Lecture *lectures = (Lecture*) malloc(totalNumberOfLectures * sizeof(Lecture));
      Timetable study = {j, totalNumberOfLectures, lectures};
      population[i].studies[j] = study;

      int *array = (int*) malloc(studyArray[j].numberOfCourses * sizeof(int));

      for (l = 0; l < totalNumberOfLectures; l++) {
        array[l] = studyArray[j].studyCourses[l].numberOfRooms;
      }

      for (k = 0; k < totalNumberOfLectures; k++) {
        randomCourse = getRandomCourse(array, studyArray[j].numberOfCourses);
        randomRoom = getRandomRoom(studyArray[j].studyCourses[randomCourse].numberOfRooms);
        Lecture singleLecture;
        strcpy(singleLecture.type, studyArray[j].studyCourses[randomCourse].course);
        strcpy(singleLecture.room, studyArray[j].studyCourses[randomCourse].rooms[randomRoom]);

        population[i].studies[j].lectures[k] = singleLecture;
      }
    }
  }
}

int getRandomCourse(int array[], int numberOfCourses) {
  int random = (rand() % numberOfCourses);

  while (1) {
    if (array[random] > 0) {
      array[random]--;
      return random;
    } else {
      random = (rand() % numberOfCourses);
    }
  }
}

int getRandomRoom(int numberOfRooms) {
  return (rand() % numberOfRooms);
}
