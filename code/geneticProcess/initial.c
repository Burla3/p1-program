#include "initial.h"

void initialPopulation(PopMember population[], Study studyArray[], int numberOfStudies) {
  int i, j, k, l, m, randomCourse, randomRoom, totalNumberOfLectures;
  char *roomName, *courseName;

  for (i = 0; i < POPULATION_SIZE; i++) {
    Timetable *studies = (Timetable*) malloc(numberOfStudies * sizeof(Timetable));
    int *fitnessPerDay = (int*) malloc(studyArray[0].totalNumberOfLectures * sizeof(int));
    PopMember member = {i, -1, fitnessPerDay, -1, -1, -1, numberOfStudies, studies};
    population[i] = member;
    for (j = 0; j < numberOfStudies; j++) {
      totalNumberOfLectures = studyArray[j].totalNumberOfLectures;
      Lecture *lectures = (Lecture*) malloc(totalNumberOfLectures * sizeof(Lecture));

      char *name = (char*) malloc(5 * sizeof(char));
      Timetable study = {name, totalNumberOfLectures, lectures};

      study.studyName = studyArray[j].name;

      population[i].studies[j] = study;

      int *randomCourseArray = (int*) malloc(studyArray[j].totalNumberOfLectures * sizeof(int));

      for (l = 0, m = 0; l < studyArray[j].numberOfCourses; l++) {
        for (k = 0; k < studyArray[j].studyCourses[l].numberOfLectures; k++, m++) {
          randomCourseArray[m] = l;
        }
      }

      for (k = 0; k < totalNumberOfLectures; k++) {
        courseName = (char*) malloc(10 * sizeof(char));
        roomName = (char*) malloc(10 * sizeof(char));

        randomCourse = getRandomCourse(randomCourseArray, studyArray[j].totalNumberOfLectures);

        if (strcmp(studyArray[j].studyCourses[randomCourse].course, "PROJEKT") != 0) {
          randomRoom = getRandomValue(studyArray[j].studyCourses[randomCourse].numberOfRooms);
          strcpy(roomName, studyArray[j].studyCourses[randomCourse].rooms[randomRoom]);
        }
        else {
          strcpy(roomName, "Grupperum");
        }

        strcpy(courseName, studyArray[j].studyCourses[randomCourse].course);

        Lecture singleLecture = {courseName, roomName};

        population[i].studies[j].lectures[k] = singleLecture;
      }
    }
  }
}

int getRandomCourse(int randomCourseArray[], int totalNumberOfLectures) {
  int random = getRandomValue(totalNumberOfLectures);
  int temp;

  while (1) {
    if (randomCourseArray[random] != -1) {
      temp = randomCourseArray[random];
      randomCourseArray[random] = -1;
      return temp;
    } else {
      random = getRandomValue(totalNumberOfLectures);
    }
  }
}
