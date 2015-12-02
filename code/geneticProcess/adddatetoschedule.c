#include <stdio.h>
#include <stdlib.h>

#define PENALTY_HARD 100
#define PENALTY_SOFT 1
#define DAYS_IN_SEMESTER 120

typedef struct CalenderData {
  double lectureTimeStart;
  int day;
  int month;
} CalenderData;

int nextDay(CalenderData *calender);
int getDaysInMonth(int month);

int main(void) {

  CalenderData calender[DAYS_IN_SEMESTER*2];

  nextDay(calender);

	return 0;
}

int nextDay(CalenderData *calender) {

  int i, day = 1, month = 9, daysInMonth = 0, weekday = 3;

  for(i = 0; i < DAYS_IN_SEMESTER*2; i++, weekday++) {
    printf("%d ", weekday);
    if (daysInMonth == 0)
      daysInMonth = getDaysInMonth(month);
    if (day > daysInMonth) {
      month++;
      day = 1;
      daysInMonth = 0;
    }

    if (weekday < 11) {
      calender[i].day = day;
      calender[i].month = month;

      if (weekday % 2 == 1)
        calender[i].lectureTimeStart = 8.15;
      else {
        calender[i].lectureTimeStart = 12.30;
        day++; 
      }
    printf("%5.2lf, %2d, %2d\n", calender[i].lectureTimeStart, calender[i].day, calender[i].month);
  }

    if (weekday % 12 == 0) {
      day++;
    }

    else if (weekday % 14 == 0) {
      day++;
      weekday = 0;
    }


  }
}

int getDaysInMonth(int month) {

  int daysInMonth;

  switch (month) {
    case 9: case 11:
      daysInMonth = 30;
      break;
    case 10: case 12:
      daysInMonth = 31;
      break;
    }

  return daysInMonth;
}


