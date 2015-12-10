#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities.h"
#include "../structs.h"

void calculateFitness(PopMember population[], Study studyArray[]);
int amountOfLectures(PopMember population[], Study studyArray[], int popCount);
int lecturerOverlap(PopMember population[], int popCount, int leastNumberOfLectures);
int lecturerAvailable(PopMember population[], int popCount);
int courseNotSameDay(PopMember population[], int popCount);