#include "initial.h"

void initialPopulation(PopMember *population, Study *studyArray, int numberOfStudies) {
  int i, j, k, l, randomCourse, randomRoom, totalNumberOfLectures;

  for (i = 0; i < POPULATION_SIZE; i++) {
    Timetable *studies = (Timetable*) malloc(numberOfStudies * sizeof(Timetable));
    PopMember member = {-1, numberOfStudies, studies};
    population[i] = member;

    for (j = 0; j < numberOfStudies; j++) {
      totalNumberOfLectures = studyArray[j].totalNumberOfLectures;
      Lecture *lectures = (Lecture*) malloc(totalNumberOfLectures * sizeof(Lecture));
      Timetable study = {j, totalNumberOfLectures, lectures};
      population[i].studies[j] = study;

      int *array = (int*) malloc(studyArray[j].numberOfCourses * sizeof(int));

      for (l = 0; l < studyArray[j].numberOfCourses; l++) {
        array[l] = studyArray[j].studyCourses[l].numberOfLectures;
      }

      for (k = 0; k < totalNumberOfLectures; k++) {
        Lecture singleLecture;
        randomCourse = getRandomCourse(array, studyArray[j].numberOfCourses);

        if (randomCourse != studyArray[j].numberOfCourses - 1) {
          randomRoom = getRandomValue(studyArray[j].studyCourses[randomCourse].numberOfRooms);
          strcpy(singleLecture.room, studyArray[j].studyCourses[randomCourse].rooms[randomRoom]);
        }
        else {
          strcpy(singleLecture.room, "GR");
        }

        strcpy(singleLecture.type, studyArray[j].studyCourses[randomCourse].course);
        population[i].studies[j].lectures[k] = singleLecture;
      }
    }
  }
}

int getRandomCourse(int array[], int numberOfCourses) {
  int random = getRandomValue(numberOfCourses);

  while (1) {
    if (array[random] > 0) {
      array[random] -= 1;
      return random;
    } else {
      random = getRandomValue(numberOfCourses);
    }
  }
}
