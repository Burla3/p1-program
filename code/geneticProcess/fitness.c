#include <stdio.h>
#include "jsonParser.h"
#include <stdlib.h>
#include <time.h>

#define PENALTY_HARD 100
#define PENALTY_SOFT 1
#define DAYS_IN_SEMESTER 120

typedef struct CalenderData {
  double lectureTimeStart;
  int day;
  int month;
} CalenderData;

 typedef struct TimetableWithDates {
  Lecture lecture;
  CalenderData calender;
} TimetableWithDates;

int nextDay(CalenderData *calender);
int getDaysInMonth(int month);

int main(void) {

  CalenderData calender[DAYS_IN_SEMESTER];
  TimetableWithDates timetable[DAYS_IN_SEMESTER];

	return 0;
}


int calculateFitness() {

  int fitness;

  
  fitness = amountOfLectures() + roomOverlap() + lecturerOverlap() + lecturerAvailable() + courseNotSameDay() + 
  		      lecturerConstraintRoomHard() + followingCourses() + lecturerConstraintSoft() + lecturerConstraintTime();

	return fitness;
}


/* HARD CONSTRAINTS */
/* amountOfLectures gives a penalty score, if there is a wrong amount of each lecture in the timetable. */
int amountOfLectures() {

  int i, j, lecturesTemp, score = 0;


  for(i = 0, lecturesTemp = 0; i < ARRAY_LENGTH; i++) {
    for(j = 0; j < lecture[j].type; j++) {
      if (strcmp(course[i]course, lecture[j].type) == 0)
        lecturesTemp += 1;      
    }

    if (course[i].lectures != lecturesTemp) 
      score += PENALTY_HARD * abs(course[i].lectures - lecturesTemp);      
  }

  return score;	
}

/* roomOverlap gives a penalty score, if more than one lecture is planning to use the same room at the same time. */
int roomOverlap() {

  int i, j, k, score = 0;

  for(i = 0; i < MAX_LECTURES; i++) {
    for(j = 0; j < MAX_STUDIES; j++) {
      for(k = 0; k < MAX_STUDIES; k++) {
        if ((j != k) && (strcmp(studies[j].lectures[i].room, studies[k].lectures[i].room) == 0))
          score += PENALTY_HARD;
      } 
    }
  }

  return score;
}

/* lecturerOverlap gives a penalty score, if more than one course needs the lecturer to educate at the same time. */
int lecturerOverlap() {

  int i, j, k, score = 0;

  for(i = 0; i < MAX_LECTURES; i++) {
    for(j = 0; j < MAX_STUDIES; j++) {
      for(k = 0; k < MAX_STUDIES; k++) {
        if ((j != k) && (strcmp(, ) == 0))
          score += PENALTY_HARD;
      } 
    }
  }

  return score;
}

/* lecturerAvailable gives a penalty score, if the lecturer is unavailable to educate when the lecture is placed in 
 * the timatable. */
int lecturerAvailable() {

}

/* courseNotSameDay gives a penalty score, if a group of students have the same course twice on the same day. */
int courseNotSameDay() {

}

/* lecturerConstraintRoom gives a penalty, every time one of the lecturer's courses arent planned to happen in the
 * same room as he says it needs to. */
int lecturerConstraintRoomHard() {

}

/* SOFT CONSTRAINTS */
/* followingCourses gives a penalty score, if two courses dont follow eachother as academically intended. */
int followingCourses() {

}

/* lecturerConstraintSoft gives a penalty, every time one of the lecturers preference to a room is broken. */
int lecturerConstraintRoomSoft() {

}

/* lecturerConstraintHard gives a penalty, every time one of the lecturer's courses are planned to happen when he
 * prefered it to. */
int lecturerConstraintTime() {

}

void createTimeTable() {

  int i;


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


