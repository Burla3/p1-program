#include <stdlib.h>
#include "structs.h"
#include <stdio.h>

/**
 * Returns a random value from 0 to (upper - 1).
 *
 * @param[in] upper the upper limit that creates the interval in which numbers returned can be in
 */
int getRandomValue(int upper);
void createTimetableWithDates(TimetableWithDates newTimetable[], PopMember population[], int popCount);
void nextDay(CalenderData *calender, int numberOfLectures);
int getDaysInMonth(int month);