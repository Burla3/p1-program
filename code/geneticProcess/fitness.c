#include "fitness.h"

void calculateFitness(PopMember population[], Study studyArray[]) {
  int popCount;

  for(popCount = 0; popCount < POPULATION_SIZE; popCount++) {
    int i;
    int leastNumberOfLectures = population[popCount].studies[0].numberOfLectures;

    TimetableWithDates *newTimetable = (TimetableWithDates*) malloc(population[popCount].numberOfStudies * sizeof(TimetableWithDates));

    createTimetableWithDates(newTimetable, population, popCount);

    for (i = 0; i < population[popCount].numberOfStudies; i++) {
      if (leastNumberOfLectures > population[popCount].studies[i].numberOfLectures) {
        leastNumberOfLectures = population[popCount].studies[i].numberOfLectures;
      }
    }

    if (population[popCount].fitnessScore == -1) {
      population[popCount].fitnessScore = amountOfLectures(population, studyArray, popCount)
      //  + roomOverlap(population, popCount, leastNumberOfLectures)
        + lecturerOverlap(population, popCount, leastNumberOfLectures)
        + lecturerAvailable(population, popCount)
        + courseNotSameDay(population, popCount)
        + lecturerConstraintRoomHard(population, popCount)
        + followingCourses(population, popCount)
        + lecturerConstraintRoomSoft(population, popCount)
        + lecturerConstraintTime(population, popCount);
    }

    free(newTimetable);
  }
}



/* HARD CONSTRAINTS */
/* amountOfLectures gives a penalty score, if there is a wrong amount of each lecture in the timetable. */
int amountOfLectures(PopMember population[], Study studyArray[], int popCount) {
  int i, j, l, lecturesTemp, score = 0;

  for (i = 0; i < population[popCount].numberOfStudies; i++) {
    for (j = 0, lecturesTemp = 0; j < studyArray[i].numberOfCourses; j++) {
      for (l = 0; l < population[popCount].studies[i].numberOfLectures; l++) {
        if (strcmp(studyArray[i].studyCourses[j].course, population[popCount].studies[i].lectures[l].type) == 0) {
        lecturesTemp += 1;
        }
      }
    }
    if (studyArray[i].totalNumberOfLectures != lecturesTemp) {
      score += PENALTY_HARD * abs(studyArray[i].studyCourses[j].numberOfLectures - lecturesTemp);
    }
  }
  return score;
}

/* roomOverlap gives a penalty score, if more than one lecture is planning to use the same room at the same time. */
int roomOverlap(PopMember population[], int popCount, int leastNumberOfLectures) {
  int i, j, k, score = 0, scoreCounter = 0;

  for (i = 0; i < population[popCount].numberOfStudies; i++) {
    for (j = 0; j < population[popCount].numberOfStudies; j++) {
      for (k = 0; k < leastNumberOfLectures; k++) {

      }
    }
  }
  score += PENALTY_HARD * scoreCounter;
  return score;
}

/* lecturerOverlap gives a penalty score, if more than one course needs the lecturer to educate at the same time. */
int lecturerOverlap(PopMember population[], int popCount, int leastNumberOfLectures) {
  int i, j, k, score = 0, scoreCounter = 0;
  char typeJ[5], typeK[5];

  for (i = 0; i < population[popCount].numberOfStudies; i++) {
    for (j = i; j < population[popCount].numberOfStudies; j++) {
      for (k = 0; k < leastNumberOfLectures; k++) {
        strcpy(typeJ, population[popCount].studies[i].lectures[k].type);
        strcpy(typeK, population[popCount].studies[j].lectures[k].type);

        if (((strcmp(typeJ, typeK) == 0) && (strcmp(typeJ, "PROJEKT") != 0)) && (i != j)){
          scoreCounter++;
        }
        if ((strcmp(population[popCount].studies[i].lectures[k].room, "Grupperum") != 0) &&
                                  (strcmp(population[popCount].studies[i].lectures[k].room,
                      population[popCount].studies[j].lectures[k].room) == 0) && (i != j)) {
          scoreCounter++;
        }
      }
    }
  }
  score += PENALTY_HARD * scoreCounter;
  return score;
}

/* lecturerAvailable gives a penalty score, if the lecturer is unavailable to educate when the lecture is placed in
 * the timatable. */
int lecturerAvailable(PopMember population[], int popCount) {
  int score = 0;

  return score;
}

/* courseNotSameDay gives a penalty score, if a group of students have the same course twice on the same day. */
int courseNotSameDay(PopMember population[], int popCount) {
  int i, j, score = 0;


  for (i = 0; i < population[popCount].numberOfStudies; i++) {
    for(j = 0; j < population[popCount].studies[i].numberOfLectures; j += 2) {
      if ((strcmp(population[popCount].studies[i].lectures[j].type,
                 population[popCount].studies[i].lectures[j + 1].type) == 0) &&
          (strcmp(population[popCount].studies[i].lectures[j].type, "PROJEKT") != 0)) {
        score += PENALTY_HARD;
      }
    }
  }
  return score;
}

/* lecturerConstraintRoom gives a penalty, every time one of the lecturer's courses arent planned to happen in the
 * same room as he says it needs to. */
int lecturerConstraintRoomHard(PopMember population[], int popCount) {
  int score = 0;

  return score;
}

/* SOFT CONSTRAINTS */
/* followingCourses gives a penalty score, if two courses dont follow eachother as academically intended. */
int followingCourses(PopMember population[], int popCount) {
  int score = 0;

  return score;
}

/* lecturerConstraintSoft gives a penalty, every time one of the lecturers preference to a room is broken. */
int lecturerConstraintRoomSoft(PopMember population[], int popCount) {
  int score = 0;

  return score;
}

/* lecturerConstraintHard gives a penalty, every time one of the lecturer's courses are planned to happen when he
 * prefered it to. */
int lecturerConstraintTime(PopMember population[], int popCount) {
  int score = 0;

  return score;
}
