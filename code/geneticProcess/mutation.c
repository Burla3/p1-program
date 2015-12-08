#include "mutation.h"

int mutate(int mutationRate, PopMember parent, PopMember offspring) {
  if (getRandomValue(100) + 1 <= mutationRate) {
    offspring = parent;

    int randStudy = getRandomValue(parent.numberOfStudies);
    int randLecture = getRandomValue(parent.studies[randStudy].numberOfLectures);

    if (getRandomValue(2) == 0) {
      strcpy(offspring.studies[randStudy].lectures[randLecture].type, "RndT");/* Random Type */
    } else {
      strcpy(offspring.studies[randStudy].lectures[randLecture].room, "RndR"); /* Random Room */
    }
    return 1;
  } else {
    return 0;
  }
}
