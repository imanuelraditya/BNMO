#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "queue.h"
#include "map.h"

#ifndef DINERDASH_H
#define DINERDASH_H

void displayOrder(Queue Q);

void displayCook(Map C);

void displayServe(Map C);

int randomNumber(int max, int min);

int idxToInt(char *idx);

void sortMap(Map *Map);

void main();

#endif