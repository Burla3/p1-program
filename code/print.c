#include "print.h"

void printTimetables(PopMember population[], int popCount) {
    TimetableWithDates *newTimetable = (TimetableWithDates*) malloc(population[popCount].numberOfStudies * sizeof(TimetableWithDates));

    createTimetableWithDates(newTimetable, population, popCount);

    //printWall(population, newTimetable, popCount);

    //printToConsol(population, newTimetable, popCount);

  printf("\n");
}

void printWall(PopMember population[], TimetableWithDates newTimetable[], int popCount) {
  int i, j;

  for (i = 0; i < population[popCount].numberOfStudies; i++) {
    printf("Study %s\n\n", population[popCount].studies[i].studyName);
    for (j = 0; j < population[popCount].studies[i].numberOfLectures; j++) {
      printf("%5.2f\t%d\t%d\t%s\t%s\t\n", newTimetable[i].calender[j].lectureTimeStart, newTimetable[i].calender[j].day,
                    newTimetable[i].calender[j].month, newTimetable[i].lecture[j].type, newTimetable[i].lecture[j].room);
    }
  }
}

void printToConsol(PopMember population[], TimetableWithDates newTimetable[], int popCount) {
  int i, j, k;

  for (i = 0; i < population[popCount].numberOfStudies; i++) {
    printf("Studieretning %s\n\n", population[popCount].studies[i].studyName);
    for (j = 0; j < population[popCount].studies[i].numberOfLectures; j += 9) {
      printf("+-----+-------------------+-------------------+-------------------+-------------------+-------------------+\n|     |");
      for (k = j; k < j + 10; k += 2) {
        if (k < population[popCount].studies[i].numberOfLectures) {
          printf("%02d/%-16d|", newTimetable[i].calender[k].day, newTimetable[i].calender[k].month);
        } else {
          printf("                   |");
        }
      }
      printf("\n|     |%-19s|%-19s|%-19s|%-19s|%-19s|\n", "Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag");
      printf("+-----+-------------------+-------------------+-------------------+-------------------+-------------------+\n");
      printf("|%5.2f|", 8.15);


      for (k = j; k < j + 10; k += 2) {
        if (k < population[popCount].studies[i].numberOfLectures) {
          printf(" %7s %-9s |", newTimetable[i].lecture[k].type, newTimetable[i].lecture[k].room);
        } else {
          printf("                   |");
        }
      }
      j++;

      printf("\n|%5.2f|", 12.30);

      for (k = j; k < j + 10; k += 2) {
        if (k < population[popCount].studies[i].numberOfLectures) {
          printf(" %7s %-9s |", newTimetable[i].lecture[k].type, newTimetable[i].lecture[k].room);
        } else {
          printf("                   |");
        }
      }

      printf("\n+-----+-------------------+-------------------+-------------------+-------------------+-------------------+\n\n\n");
    }
    printf("\n\n\n");
  }
}
