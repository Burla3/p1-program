#include "mutation.h"

int mutate(int mutationRate, int totalStudies, int totalLectures, PopMember parent, PopMember offspring) {
  if ((rand() % 100) + 1 <= mutationRate) {
    offspring = parent;

    int randStudy = rand() % totalStudies;
    int randLecture = rand() % totalLectures;

    if (rand() % 2 == 0) {
      strcpy(offspring.studies[randStudy].lectures[randLecture].type, "RndT");/* Random Type */
    } else {
      offspring.studies[randStudy].lectures[randLecture].room = "Random Room";
    }
    return 1;
  } else {
    return 0;
  }
}
