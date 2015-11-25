#include <stdio.h>
#include "jsonParser.h"

void jsonExample();

int main()
{
  jsonExample();

  return 0;
}

void jsonExample() {
  json_t *root, *value;

  root = loadJSON("json/config.json");

  if (root == NULL) {
    perror("Error loading JSON ");
  }

  value = json_object_get(root, "check");

  json_decref(root);

  printf("%s\n", json_string_value(value));

  json_decref(value);
}