#include "print.h"

void printTimetables(PopMember population[], int popCount) {
  int i, j, k;
    TimetableWithDates *newTimetable = (TimetableWithDates*) malloc(population[popCount].numberOfStudies * sizeof(TimetableWithDates));

    createTimetableWithDates(newTimetable, population, popCount);

    /*for (i = 0; i < population[popCount].numberOfStudies; i++) {
      printf("Study %s\n\n", population[popCount].studies[i].studyName);
      for (j = 0; j < population[popCount].studies[i].numberOfLectures; j++) {
        printf("%5.2f\t%d\t%d\t%s\t%s\t\n", newTimetable[i].calender[j].lectureTimeStart, newTimetable[i].calender[j].day,
                      newTimetable[i].calender[j].month, newTimetable[i].lecture[j].type, newTimetable[i].lecture[j].room);
      }
    }*/

    for (i = 0; i < population[popCount].numberOfStudies; i++) {
      printf("Studieretning %s\n\n", population[popCount].studies[i].studyName);
      for (j = 0; j < population[popCount].studies[i].numberOfLectures;) {
        printf("+-----+----------------+----------------+----------------+----------------+----------------+\n");
        printf("|     |");
        for (k = j; k < j + 10; k += 2) {
          printf("%02d/%-13d|", newTimetable[i].calender[k].day, newTimetable[i].calender[k].month);
        }
        printf("\n");
        printf("|     |");
        printf("%-16s|%-16s|%-16s|%-16s|%-16s|\n", "Mandag", "Tirsdag", "Onsdag", "Torsdag", "Fredag");
        printf("+-----+----------------+----------------+----------------+----------------+----------------+\n");
        printf("|%5.2f|", 8.15);


        for (k = j; k < j + 10; k += 2) {
          printf(" %4s %-9s |", newTimetable[i].lecture[k].type, newTimetable[i].lecture[k].room);
        }
        j++;

        printf("\n");
        printf("|%5.2f|", 12.30);

        for (k = j; k < j + 10; k += 2) {
          printf(" %4s %-9s |", newTimetable[i].lecture[k].type, newTimetable[i].lecture[k].room);
        }

        j += 10;

        printf("\n");
        printf("+-----+----------------+----------------+----------------+----------------+----------------+\n");
        printf("\n\n");
      }
      printf("\n\n\n");
    }
    printf("\n");
  }
