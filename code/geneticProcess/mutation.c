#include "mutation.h"

void printParent1(PopMember parent) {
  int j,h;

      printf("NUMBER OF STUDIES %d\n", parent.numberOfStudies);

  for (j = 0; j < parent.numberOfStudies; j++) {
    printf("\n%s\n\n", parent.studies[j].studyName);
    printf("NUMBER OF LECTURES %d\n", parent.studies[j].numberOfLectures);
    for (h = 0; h < parent.studies[j].numberOfLectures; h++) {


      printf("%s\t%s\n", parent.studies[j].lectures[h].type, parent.studies[j].lectures[h].room);
    }
  }
    printf("---------------------------------------\n");
}

int mutate(PopMember *population, int populationSizeAfterSelection,
            int currentPopulationSize, Study *studyArray) {

  if (getRandomValue(100) + 1 <= (MUTATION_RATE)) {

    PopMember parent = population[getRandomValue(populationSizeAfterSelection)];
    PopMember offspring = population[currentPopulationSize];

    int i, j;

    for (i = 0; i < offspring.numberOfStudies; i++) {
      for (j = 0; j < offspring.studies[i].numberOfLectures; j++) {
        strcpy(offspring.studies[i].lectures[j].type, parent.studies[i].lectures[j].type);
        strcpy(offspring.studies[i].lectures[j].room, parent.studies[i].lectures[j].room);
      }
    }

    offspring.fitnessScore = -1;

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
    population[currentPopulationSize] = offspring;
    return 1;
  } else {
    return 0;
  }

return 0;
}

int getCourseIndex(Study *studyArray, PopMember offspring, int randStudy, int randLecture) {
  int i;

  for (i = 0; i < studyArray[randStudy].numberOfCourses; i++) {
    if (strcmp(offspring.studies[randStudy].lectures[randLecture].type,
      studyArray[randStudy].studyCourses[i].course) == 0) {
      break;
    }
  }
  return i;
}

void setRandomRoom(Study *studyArray, PopMember *offspring, int randStudy, int randLecture, int courseIndex) {

  if (strcmp(offspring->studies[randStudy].lectures[randLecture].type, "PROJEKT") == 0) {
    strcpy(offspring->studies[randStudy].lectures[randLecture].room, "Grupperum");

  } else {

    int numberOfRooms = studyArray[randStudy].studyCourses[courseIndex].numberOfRooms;
    int randRoom = getRandomValue(numberOfRooms);

    strcpy(offspring->studies[randStudy].lectures[randLecture].room,
      studyArray[randStudy].studyCourses[courseIndex].rooms[randRoom]);
  }
}

int mutateRoom1(PopMember *population, Study *studyArray, int currentPopulationSize) {
  int i, j, k, l;

  for (i = 0; i < POPULATION_SIZE / 10; i++) {
    printf("I: \t\t\t\t\t\t\t\t\t\t%d\n\n", i);
    PopMember parent = population[getRandomValue(POPULATION_SIZE / 10)];

    //printParent1(parent);

    PopMember offspring = population[currentPopulationSize];
    printf("numberOfLectures %d\n", parent.studies[0].numberOfLectures);
    for (j = 0; j < parent.studies[0].numberOfLectures; j++) {
      if (parent.fitnessPerDay[j] > 0) {
          // printf("J: \t\t\t\t\t\t\t\t\t\t%d\n", j);

        offspring.fitnessScore = -1;
        for (k = 0; k < parent.numberOfStudies; k++) {
          if (parent.studies[k].numberOfLectures > j  && strcmp(parent.studies[k].lectures[j].type, "PROJEKT") != 0) {
            // printf("K: \t\t\t\t\t\t\t\t\t\t%d\n", k);
            for (l = 0; l < studyArray[k].numberOfCourses; l++) {
              // printf("L: \t\t\t\t\t\t\t\t\t\t%d\n", l);
              if (strcmp(parent.studies[k].lectures[j].type, studyArray[k].studyCourses[l].course) == 0) {
                break;
              }
            }
            // printf("studyArray %s\n", studyArray[k].studyCourses[l].course);
            // printf("Offspring Type %s\n", offspring.studies[k].lectures[j].type);
            strcpy(offspring.studies[k].lectures[j].type, parent.studies[k].lectures[j].type);

            int numberOfRooms = studyArray[k].studyCourses[l].numberOfRooms;
            int randRoom = getRandomValue(numberOfRooms);

            strcpy(offspring.studies[k].lectures[j].room, studyArray[k].studyCourses[l].rooms[randRoom]);
          }
        }
        population[currentPopulationSize] = offspring;
        currentPopulationSize++;
      }
    }
  }
  printf("sdfasdfasdfasdfasdf\n\n\n");
  return currentPopulationSize;
}
