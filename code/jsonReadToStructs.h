#include <jansson.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"

/**
 * Fills the input array with data from the JSON object that is loaded from the config file.
 *
 * @param[in] rootConfig Root of the JSON config object.
 * @param[out] studyArray An array of Study structs to fill with config data.
 */
void populateStudyStructFromConfig(json_t *rootConfig, Study *studyArray);

/**
 * Searches in array for an specified id and returns a boolean value
 *
 * @param[in] array Array to check.
 * @param[in] id Id to check.
 * @returns A boolean value. 1 is true (id is found inside array). 0 is false.
 */
int hasCourseId(json_t *array, int id);

/**
 * Prints a Study struct.
 *
 * @param[in] study A Study struct to print.
 */
void printStudyStruct(Study study);

/**
 * Get the total number of rooms to choose from.
 * All "AUDITORIUM"'s, "SEMINAR_ROOM"'s & "GROUPROOM"'s.
 *
 * @param[in] rootConfig Root of the JSON config object.
 * @returns The total number of rooms.
 */
int getTotalNumberOfRooms(json_t *rootConfig);
