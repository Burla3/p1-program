#include "fitness.h"

void calculateFitness(PopMember population[], Study studyArray[]) {
  int popCount;

  for(popCount = 0; popCount < POPULATION_SIZE; popCount++) {
    int i;

    if (population[popCount].fitnessScore == -1) {

      int score = 0, temp1, temp2, temp3;
      population[popCount].amountScore = 0;
      population[popCount].notsamedayScore = 0;

      for (i = 0; i < population[popCount].numberOfStudies; i++) {
        temp1 = amountOfLectures(population, studyArray, popCount, i);
        population[popCount].amountScore += temp1;
        score += temp1;
        temp3 = courseNotSameDay(population, popCount, i);
        population[popCount].notsamedayScore += temp3;
        score += temp3;
      }

      temp2 = roomOverlap(population, popCount);
      population[popCount].overlapScore = temp2;
      score += temp2;

      population[popCount].fitnessScore = score;
    }
  }
}

/* HARD CONSTRAINTS */
/* amountOfLectures gives a penalty score, if there is a wrong amount of each lecture in the timetable. */
int amountOfLectures(PopMember population[], Study studyArray[], int popCount, int i) {
  int j, l;
  int score = 0;
  int lecturesTemp;

  for (j = 0; j < studyArray[i].numberOfCourses; j++) {
    for (l = 0, lecturesTemp = 0; l < population[popCount].studies[i].numberOfLectures; l++) {
      if (strcmp(studyArray[i].studyCourses[j].course, population[popCount].studies[i].lectures[l].type) == 0) {
        lecturesTemp += 1;
      }
    }
    if (lecturesTemp > 0) {
      score += PENALTY_HARD * abs(studyArray[i].studyCourses[j].numberOfLectures - lecturesTemp);
    }
  }
  return score;
}

/* roomOverlap gives a penalty score, if more than one course needs the same room. */
int roomOverlap(PopMember population[], int popCount) {
  int i, j, k;
  int score = 0, temp = 0;

  for (k = 0; k < population[popCount].studies[0].numberOfLectures ; k++) {
    for (i = 0; i < population[popCount].numberOfStudies; i++) {
      if (i + 1 < population[popCount].numberOfStudies) {
        for (j = i + 1; j < population[popCount].numberOfStudies; j++) {
          if (population[popCount].studies[i].numberOfLectures > k && population[popCount].studies[j].numberOfLectures > k) {
            if ((strcmp(population[popCount].studies[i].lectures[k].room, "Grupperum") != 0) && (strcmp(population[popCount].studies[i].lectures[k].room, population[popCount].studies[j].lectures[k].room) == 0)) {
              score += PENALTY_HARD;
            }
          }
        }
      }
    }
    population[popCount].fitnessPerDay[k] = score - temp;
    temp = score;
  }
  return score;
}

/* courseNotSameDay gives a penalty score, if a group of students have the same course twice on the same day. */
int courseNotSameDay(PopMember population[], int popCount, int i) {
  int j;
  int score = 0;

  for(j = 0; j < population[popCount].studies[i].numberOfLectures; j += 2) {
    if ((strcmp(population[popCount].studies[i].lectures[j].type,
               population[popCount].studies[i].lectures[j + 1].type) == 0) &&
        (strcmp(population[popCount].studies[i].lectures[j].type, "PROJEKT") != 0)) {
      score += PENALTY_HARD;
    }
  }
  return score;
}
