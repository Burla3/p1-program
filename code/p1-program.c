#include "p1-program.h"
#include "structs.h"

/* Global variables */
json_t *rootConfig;

int main(void) {
  initialConfiguration();

  PopMember *population = (PopMember*) malloc(POPULATION_SIZE * sizeof(PopMember));

  return 0;
}

void initialConfiguration() {
  srand(time(NULL));

  rootConfig = loadJSON("json/config.json");

  if (rootConfig == NULL) {
    perror("Error loading JSON ");
  }
}
