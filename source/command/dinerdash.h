#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "../ADT/map/map.h"
#include "../ADT/queuedinerdash/queue.h"
#include "../ADT/mesinkata/mesinkata.h"

#ifndef DINERDASH_H
#define DINERDASH_H

void displayOrder(QueueInt Q);

void displayCook(Map C);

void displayServe(Map C);

int randomNumber(int max, int min);

int idxToInt(char *idx);

void sortMap(Map *Map);

void dinerdash();

#endif