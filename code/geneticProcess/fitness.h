#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../jsonParser.h"
#include "../structs.h"

void calculateFitness();
int amountOfLectures();
int roomOverlap();
int lecturerOverlap();
int lecturerAvailable();
int courseNotSameDay();
int lecturerConstraintRoomHard();
int followingCourses();
int lecturerConstraintRoomSoft();
int lecturerConstraintTime();