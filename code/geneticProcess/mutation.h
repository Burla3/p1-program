#include <stdlib.h>
#include <string.h>
#include "../structs.h"

/**
 * There is a chance that the type or room which is picked from lectures, and there is a chance that either one of
 * variables will mutate.
 *
 * @param[in] mutationRate the chance for something to mutate
 * @param[in] totalStudies the total amount of studies per PopMember
 * @param[in] totalLectures the total amount of lectures per Timetable
 * @param[in] parent the parent used for mutation
 * @param[out] offspring the offspring that is generated through mutation
 */
int mutate(int mutationRate, int totalStudies, int totalLectures, PopMember parent, PopMember offspring);
