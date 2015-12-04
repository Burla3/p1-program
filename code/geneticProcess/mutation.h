#include <stdlib.h>
#include "../structs.h"

/**
 * There is a chance that the type or room which is picked from lectures, and there is a chance that either one of
 * variables will mutate.
 *
 * @param[in] mutationRate the chance for something to mutate
 * @param[in] totalLectures the total amount of lectures per timetable
 * @param[in] parent the first parent used for breeding
 * @param[out] offspring the first offspring that is generated through breeding
 */
int mutate(const int mutationRate, const int totalLectures, const Lecture parent[], Lecture offspring[]);
