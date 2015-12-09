#include "addDateToSchedule.h"

void nextDay(CalenderData *calender, int numberOfLectures) {

  int i, day = 1, month = 9, daysInMonth = 0, weekday = 3;

  for(i = 0; i < numberOfLectures; weekday++) {
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
      i++;
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
