#include "mutation.h"

int mutate(PopMember parent, PopMember offspring) {
  if (getRandomValue(100) + 1 <= MUTATION_RATE) {

    int randStudy = getRandomValue(parent.numberOfStudies);
    int randLecture = getRandomValue(parent.studies[randStudy].numberOfLectures);

    if (getRandomValue(2) == 0) {
      strcpy(offspring.studies[randStudy].lectures[randLecture].type, "RndT");
    } else {
      strcpy(offspring.studies[randStudy].lectures[randLecture].room, "RndR");
    }
    return 1;
  } else {
    return 0;
  }

return 0;
}
