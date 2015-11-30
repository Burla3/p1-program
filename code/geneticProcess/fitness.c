#include <stdio.h>
#include "jsonParser.h"
#include <stdlib.h>
#include <time.h>

#define PENALTY_HARD 100
#define PENALTY_SOFT 1

int main(void) {

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
    unsigned int difference;

    for(i = 0, lecturesTemp = 0; i < ARRAY_LENGTH; i++) {
      for(j = 0; j < lecture[j].type; j++) {
        if (strcmp(course[i]course, lecture[j].type) == 0)
          lecturesTemp += 1;      
      }

      if (course[i].lectures != lecturesTemp) {
        difference = course[i].lectures - lecturesTemp;
        score += PENALTY_HARD * difference;
      }      
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

  /* lecturerAvailable gives a penalty score, if the lecturer is unavailable to educate when the couse is placed in the 
   * timatable. */
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


