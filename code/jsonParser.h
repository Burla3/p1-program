#include <jansson.h>
#include <stdlib.h>

/**
 * Returns a JSON structure from the entered file name by the Jansson library.
 *
 * @param[in] fileName The name of the JSON file (with .json extension).
 * @return JSON structure.
 */
json_t * loadJSON(const char *fileName);

/**
 * Returns a FILE pointer from the entered file name in read mode.
 *
 * @param[in] fileName The name of the file to open in read.
 * @return A FILE pointer in read mode.
 */
FILE * openFile(const char *fileName);

/**
 * Gets the maximum char length of the specified file.
 * Example of a file containing "Example" will return 7.
 *
 * @param[in] fp FILE to check length on.
 * @return Maximum char length.
 */
long getFileCharLength(FILE *fp);

/**
 * Reads a JSON file and place it in a JSON structure 
 *
 * @param[in] fp FILE to read JSON from.
 * @param[in] maxLength Max length to read from the file.
 * @return JSON structure.
 */
json_t * readJSON(FILE *fp, const long maxLength);