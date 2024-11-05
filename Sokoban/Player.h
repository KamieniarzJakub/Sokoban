#pragma once
#include <stdio.h>
#include <string.h>
#include "Settings.h"

#define PLAYER_POSITION pos_y *MAP_WIDTH + pos_x

void MoveCharacter(int pos_x, int pos_y, int offset);
void PlayerPosition(int* pos_x, int* pos_y);