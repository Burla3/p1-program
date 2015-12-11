#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <stdio.h>
#include "structs.h"

/**
 * Returns a random value from 0 to (upper - 1).
 *
 * @param[in] upper the upper limit that creates the interval in which numbers returned can be in
 */
int getRandomValue(int upper);
void createTimetableWithDates(TimetableWithDates newTimetable[], PopMember population[], int popCount);
void nextDay(CalenderData *calender, int numberOfLectures);
int getDaysInMonth(int month);
int64_t currentTimestamp();
int64_t printTimeDifferenceMillis(int64_t startTime, char *strToPrint);
int64_t printTimeDifferenceSeconds(int64_t startTime, char *strToPrint);