#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../jsonParser.h"
#include "../structs.h"

void calculateFitness(PopMember population[], Study studyArray[]);
int amountOfLectures(PopMember population[], Study studyArray[], int popCount);
int roomOverlap(PopMember population[], int popCount);
int lecturerOverlap(PopMember population[], int popCount);
int lecturerAvailable(PopMember population[], int popCount);
int courseNotSameDay(PopMember population[], int popCount);
int lecturerConstraintRoomHard(PopMember population[], int popCount);
int followingCourses(PopMember population[], int popCount);
int lecturerConstraintRoomSoft(PopMember population[], int popCount);
int lecturerConstraintTime(PopMember population[], int popCount);