#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../structs.h"

void calculateFitness(PopMember population[], Study studyArray[]);
int amountOfLectures(PopMember population[], Study studyArray[], int popCount, int i);
int roomOverlap(PopMember population[], int popCount);
int getLeastNumberOfLectures(Timetable study1, Timetable study2);
int courseNotSameDay(PopMember population[], int popCount, int i);
