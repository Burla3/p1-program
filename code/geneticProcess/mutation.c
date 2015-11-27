#include "mutation.h"

int mutate(const int mutationRate, const int totalLectures, const lecture parent[], lecture offspring[]) {
  int i;
  for (i = 0; i < totalLectures; i++) {
    offspring[i] = parent[i];
  }

  if ((rand() % 100) + 1 <= mutationRate) {
    int randLecture = rand() % totalLectures;
    if (rand() % 2 == 0) {
      offspring[randLecture].type = "Random Type";
    } else {
      offspring[randLecture].room = "Random Room";
    }
    return 1;
  } else {
    return 0;
  }
}