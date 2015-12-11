#include "fitness.h"

void calculateFitness(PopMember population[], Study studyArray[]) {
  int popCount;

  for(popCount = 0; popCount < POPULATION_SIZE; popCount++) {
    int i;

    TimetableWithDates *newTimetable = (TimetableWithDates*) malloc(population[popCount].numberOfStudies * sizeof(TimetableWithDates));

    createTimetableWithDates(newTimetable, population, popCount);

    if (population[popCount].fitnessScore == -1) {
      int score = 0, temp1, temp2, temp3;
      population[popCount].amountScore = 0;
      population[popCount].overlapScore = 0;
      population[popCount].notsamedayScore = 0;



      for (i = 0; i < population[popCount].numberOfStudies; i++) {
        temp1 = amountOfLectures(population, studyArray, popCount, i);
        population[popCount].amountScore += temp1;                              ;
        score += temp1;
        temp2 = lecturerOverlap(population, popCount, i);
        population[popCount].overlapScore += temp2;
        score += temp2;
        /* lecturerAvailable */
        temp3 = courseNotSameDay(population, popCount, i);
        population[popCount].notsamedayScore += temp3;
        score += temp3;
      }
      population[popCount].fitnessScore = score;
    }
    free(newTimetable);
  }
}

/* HARD CONSTRAINTS */
/* amountOfLectures gives a penalty score, if there is a wrong amount of each lecture in the timetable. */
int amountOfLectures(PopMember population[], Study studyArray[], int popCount, int i) {
  int j, l;
  int score = 0;
  int lecturesTemp;
  int projectTemp;

  for (j = 0; j < studyArray[i].numberOfCourses; j++) {
    for (l = 0, lecturesTemp = 0, projectTemp = 0; l < population[popCount].studies[i].numberOfLectures; l++) {
      if ((strcmp(studyArray[i].studyCourses[j].course, "PROJEKT") == 0) && (strcmp("PROJEKT", population[popCount].studies[i].lectures[l].type) == 0)) {
         projectTemp += 1;
        }
      else if (strcmp(studyArray[i].studyCourses[j].course, population[popCount].studies[i].lectures[l].type) == 0) {
        lecturesTemp += 1;
      }
    }
    if (projectTemp > 0) {
      score += PENALTY_HARD * abs(studyArray[i].studyCourses[j].numberOfLectures - projectTemp);
    } else if (lecturesTemp > 0) {
      score += PENALTY_HARD * abs(studyArray[i].studyCourses[j].numberOfLectures - lecturesTemp);
    }
  }
  return score;
}

/* lecturerOverlap gives a penalty score, if more than one course needs the lecturer to educate at the same time. */
int lecturerOverlap(PopMember population[], int popCount, int i) {
  int leastNumberOfLectures, j, k;
  int score = 0;

  for (j = i + 1; j < population[popCount].numberOfStudies; j++) {
    leastNumberOfLectures = getLeastNumberOfLectures(population[popCount].studies[i], population[popCount].studies[j]);

    for (k = 0; k < leastNumberOfLectures; k++) {
      score += lecturerOverlapCheck(population[popCount].studies[i].lectures[k],
                                    population[popCount].studies[j].lectures[k]);
    }
  }
  return score;
}

int getLeastNumberOfLectures(Timetable study1, Timetable study2) {
  int leastNumberOfLectures;

  if (study1.numberOfLectures < study2.numberOfLectures) {
    leastNumberOfLectures = study1.numberOfLectures;
  } else {
    leastNumberOfLectures = study2.numberOfLectures;
  }
  return leastNumberOfLectures;
}

int lecturerOverlapCheck(Lecture study1lecture, Lecture study2lecture) {
  int score = 0;

  /*if ((strcmp(study1lecture.type, study2lecture.type) == 0) &&
      (strcmp(study1lecture.type, "PROJEKT") != 0) &&
      (strcmp(study1lecture.type, "PV") != 0)) {
    score += PENALTY_HARD;
  }*/

  if ((strcmp(study1lecture.room, "Grupperum") != 0) && (strcmp(study1lecture.room, study2lecture.room) == 0)) {
    score += PENALTY_HARD;
  }

  return score;
}

/* lecturerAvailable gives a penalty score, if the lecturer is unavailable to educate when the lecture is placed in
 * the timatable. */
int lecturerAvailable(PopMember population[], int popCount) {
  int score = 0;

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
