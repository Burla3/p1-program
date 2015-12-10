#include "print.h"

void printTimetables(PopMember population[], int popCount) {
  int i, j;
    TimetableWithDates *newTimetable = (TimetableWithDates*) malloc(population[popCount].numberOfStudies * sizeof(TimetableWithDates));

    createTimetableWithDates(newTimetable, population, popCount);

    for (i = 0; i < population[popCount].numberOfStudies; i++) {
      printf("Study %s\n\n", population[popCount].studies[i].studyName);
      for (j = 0; j < population[popCount].studies[i].numberOfLectures; j++) {
        printf("%5.2f\t%d\t%d\t%s\t%s\t\n", newTimetable[i].calender[j].lectureTimeStart, newTimetable[i].calender[j].day,
                      newTimetable[i].calender[j].month, newTimetable[i].lecture[j].type, newTimetable[i].lecture[j].room);
      }
      printf("\n");
    }
  }
