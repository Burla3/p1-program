#include "initial.h"

void initialPopulation(PopMember *population, Study *studyArray, int numberOfStudies, json_t *rootConfig) {
  int i, k, l, randomCourse, randomRoom, totalNumberOfLectures;

  for (i = 0; i < POPULATION_SIZE; i++) {
    Timetable *studies = (Timetable*) malloc(numberOfStudies * sizeof(Timetable));
    PopMember member = {-1, numberOfStudies, studies};
    population[i] = member;

    /* root->groups[] */
    json_t *groups = json_object_get(rootConfig, "groups");

    int gJ;
    json_t *groupsValue;

    /* root->groups[i] */
    json_array_foreach(groups, gJ, groupsValue) {
      totalNumberOfLectures = studyArray[gJ].totalNumberOfLectures;
      Lecture *lectures = (Lecture*) malloc(totalNumberOfLectures * sizeof(Lecture));

      /* root->groups[i]->name */
      json_t *nameValue = json_object_get(groupsValue, "name");

      Timetable study = {"", totalNumberOfLectures, lectures};
      strcpy(study.studyName, json_string_value(nameValue));
       
      population[i].studies[gJ] = study;

      int *array = (int*) malloc(studyArray[gJ].numberOfCourses * sizeof(int));

      for (l = 0; l < studyArray[gJ].numberOfCourses; l++) {
        array[l] = studyArray[gJ].studyCourses[l].numberOfLectures;
      }

      for (k = 0; k < totalNumberOfLectures; k++) {
        Lecture singleLecture;
        randomCourse = getRandomCourse(array, studyArray[gJ].numberOfCourses);

        if (randomCourse != studyArray[gJ].numberOfCourses - 1) {
          randomRoom = getRandomRoom(studyArray[gJ].studyCourses[randomCourse].numberOfRooms);
          strcpy(singleLecture.room, studyArray[gJ].studyCourses[randomCourse].rooms[randomRoom]);
        }
        else {
          strcpy(singleLecture.room, "GR");
        }

        strcpy(singleLecture.type, studyArray[gJ].studyCourses[randomCourse].course);
        population[gJ].studies[gJ].lectures[k] = singleLecture;
      }     
    }
  }
}

int getRandomCourse(int array[], int numberOfCourses) {
  int random = (rand() % numberOfCourses);

  while (1) {
    if (array[random] > 0) {
      array[random] -= 1;
      return random;
    } else {
      random = (rand() % numberOfCourses);
    }
  }
}

int getRandomRoom(int numberOfRooms) {
  return (rand() % numberOfRooms);
}
