#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <stdio.h>
#include "structs.h"

/**
 * Returns a random value from 0 to (upper - 1).
 * If upper is 0 then 0 is returned instead of division by 0 error.
 *
 * @param[in] upper The upper limit that creates the interval in which numbers returned can be in.
 * @returns A random value above 0 and lower than the upper param.
 */
int getRandomValue(int upper);

void createTimetableWithDates(TimetableWithDates newTimetable[], PopMember population[], int popCount);

void nextDay(CalenderData *calender, int numberOfLectures);

/**
 * Gets the number of day in a month, although limited to the last  months(9, 10, 11, 12).
 *
 * @param[in] month A specified month. 1 = January, 12 = December.
 * @returns The number of days in the month.
 */
int getDaysInMonth(int month);

/**
 * @returns The current timestamp in milliseconds represented by a 64 bit int.
 */
int64_t currentTimestamp();

/**
 * Prints the time difference in milliseconds between the startTime of the call of this function.
 *
 * @param[in] startTime A timestamp to compare difference with.
 * @param[in] strToPrint A string to print infront of the calculated time difference.
 * @returns The current timestamp in milliseconds.
 */
int64_t printTimeDifferenceMillis(int64_t startTime, char *strToPrint);

/**
 * Prints the time difference in seconds between the startTime of the call of this function.
 *
 * @param[in] startTime A timestamp to compare difference with.
 * @param[in] strToPrint A string to print infront of the calculated time difference.
 * @returns The current timestamp in milliseconds.
 */
int64_t printTimeDifferenceSeconds(int64_t startTime, char *strToPrint);