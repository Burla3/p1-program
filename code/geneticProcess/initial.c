#include "initial.h"

void initialPopulation(PopMember population[], Study studyArray[], int numberOfStudies) {
  int i, j, k, l, randomCourse, randomRoom, totalNumberOfLectures;
  char *roomName, *courseName;

  for (i = 0; i < POPULATION_SIZE; i++) {
    Timetable *studies = (Timetable*) malloc(numberOfStudies * sizeof(Timetable));
    PopMember member = {-1, numberOfStudies, studies};
    population[i] = member;
    for (j = 0; j < numberOfStudies; j++) {
      totalNumberOfLectures = studyArray[j].totalNumberOfLectures;
      Lecture *lectures = (Lecture*) malloc(totalNumberOfLectures * sizeof(Lecture));

      char *name = (char*) malloc(5 * sizeof(char));
      Timetable study = {name, totalNumberOfLectures, lectures};

      study.studyName = studyArray[j].name;

      population[i].studies[j] = study;

      int *numberOfLectures = (int*) malloc(studyArray[j].numberOfCourses * sizeof(int));

      for (l = 0; l < studyArray[j].numberOfCourses; l++) {
        numberOfLectures[l] = studyArray[j].studyCourses[l].numberOfLectures;
      }

      for (k = 0; k < totalNumberOfLectures; k++) {

        courseName = (char*) malloc(5 * sizeof(char));
        roomName = (char*) malloc(10 * sizeof(char));

        randomCourse = getRandomCourse(numberOfLectures, studyArray[j].numberOfCourses);

        if (randomCourse != studyArray[j].numberOfCourses - 1) {
          randomRoom = getRandomValue(studyArray[j].studyCourses[randomCourse].numberOfRooms);
          strcpy(roomName, studyArray[j].studyCourses[randomCourse].rooms[randomRoom]);
        }
        else {
          strcpy(roomName, "GR");
        }

        strcpy(courseName, studyArray[j].studyCourses[randomCourse].course);
        Lecture singleLecture = {courseName, roomName};

        population[i].studies[j].lectures[k] = singleLecture;
      }
    }
  }
}

int getRandomCourse(int numberOfLectures[], int numberOfCourses) {
  int random = getRandomValue(numberOfCourses);

  while (1) {
    if (numberOfLectures[random] > 0) {
      numberOfLectures[random] -= 1;
      return random;
    } else {
      random = getRandomValue(numberOfCourses);
    }
  }
}
