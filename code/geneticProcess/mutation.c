#include "mutation.h"

int mutate(PopMember *population, int currentPopulationSize, Study *studyArray) {

  if (getRandomValue(100) + 1 <= MUTATION_RATE) {

    PopMember parent = population[getRandomValue(currentPopulationSize)];
    PopMember offspring = parent;

    int randStudy = getRandomValue(offspring.numberOfStudies);
    int randLecture = getRandomValue(offspring.studies[randStudy].numberOfLectures);
    int randCourse = getRandomValue(studyArray[randStudy].numberOfCourses);

    if (getRandomValue(2) == 0) {
      strcpy(offspring.studies[randStudy].lectures[randLecture].type,
        studyArray[randStudy].studyCourses[randCourse].course);

      int courseIndex = getCourseIndex(studyArray, offspring, randStudy, randLecture);

      setRandomRoom(studyArray, &offspring, randStudy, randLecture, courseIndex);

    } else {
      int courseIndex = getCourseIndex(studyArray, offspring, randStudy, randLecture);

      setRandomRoom(studyArray, &offspring, randStudy, randLecture, courseIndex);
    }
    return 1;
  } else {
    return 0;
  }

return 0;
}

int getCourseIndex(Study *studyArray, PopMember offspring, int randStudy, int randLecture) {
  int i;

  for (i = 0; i < studyArray[randStudy].numberOfCourses; i++)
  {
    if (strcmp(offspring.studies[randStudy].lectures[randLecture].type,
      studyArray[randStudy].studyCourses[i].course) == 0) {
      break;
    }
  }
  return i;
}

void setRandomRoom(Study *studyArray, PopMember *offspring, int randStudy, int randLecture, int courseIndex) {

  if (strcmp(offspring->studies[randStudy].lectures[randLecture].type, "PROJ") == 0) {
    strcpy(offspring->studies[randStudy].lectures[randLecture].room, "Grupperum");

  } else {

    int numberOfRooms = studyArray[randStudy].studyCourses[courseIndex].numberOfRooms;
    int randRoom = getRandomValue(numberOfRooms);

    strcpy(offspring->studies[randStudy].lectures[randLecture].room,
      studyArray[randStudy].studyCourses[courseIndex].rooms[randRoom]);
  }
}
