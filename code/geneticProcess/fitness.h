#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../jsonParser.h"
#include "../structs.h"

int calculateFitness();
int amountOfLectures();
int roomOverlap();
int lecturerOverlap();
int lecturerAvailable();
int courseNotSameDay();
int lecturerConstraintRoomHard();
int followingCourses();
int lecturerConstraintRoomSoft();
int lecturerConstraintTime();
void createTimeTable();