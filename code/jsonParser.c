#include "jsonParser.h"

json_t * loadJSON(const char *fileName)
{
  json_t *root;
  
  /* Open JSON file */
  FILE *fp = openFile(fileName);

  long fsize = getFileCharLength(fp);

  /* Retrieve the JSON object from the file */
  root = readJSON(fp, fsize + 1);

  return root;
}

FILE * openFile(const char *fileName) {
  FILE *fp;
  fp = fopen(fileName, "r");

  if (fp == NULL) {
    perror("Error opening file ");
    return fp;
  }

  return fp;
}

long getFileCharLength(FILE *fp) {
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  return fsize;
}

json_t * readJSON(FILE *fp, const long maxLength) {
  json_t *root = NULL;
  json_error_t error;

  char *buffer = (char*) malloc(maxLength);

  if (buffer == NULL) {
    perror("Can not allocate enough RAM ");
    return root;
  }

  /* Reads the first line of the file */
  if (fgets(buffer, maxLength, fp) == NULL) {
    perror("Error reading file ");
    return root;
  }

  /* Close file after use */
  fclose(fp);

  /* Create JSON structure */
  root = json_loads(buffer, 0, &error);
  free(buffer);

  if(!root) {
    fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
  }

  return root;
}