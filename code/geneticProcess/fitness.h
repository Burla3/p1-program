#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../structs.h"

void calculateFitness(PopMember population[], Study studyArray[]);
int amountOfLectures(PopMember population[], Study studyArray[], int popCount, int i);
int lecturerOverlap(PopMember population[], int popCount, int i);
int getLeastNumberOfLectures(Timetable study1, Timetable study2);
int lecturerOverlapCheck(Lecture study1lecture, Lecture study2lecture);
int lecturerAvailable(PopMember population[], int popCount);
int courseNotSameDay(PopMember population[], int popCount, int i);