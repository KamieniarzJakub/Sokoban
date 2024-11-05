#include "Player.h"

void MoveCharacter(int pos_x, int pos_y, int offset) {
    if (map[PLAYER_POSITION + offset] != '#')
    {
        if ((map[PLAYER_POSITION + offset] == 'B' ||
           map[PLAYER_POSITION + offset] == 'O') && (map[PLAYER_POSITION + offset * 2] != '#' ||
                map[PLAYER_POSITION + offset * 2] != 'B' || map[PLAYER_POSITION + offset * 2] != 'O'))
        {
            map[PLAYER_POSITION] = ' ';
            pos_x += offset;

            if (map[PLAYER_POSITION + offset] == ' ')
                map[PLAYER_POSITION + offset] = 'B';

            else if (map[PLAYER_POSITION + offset] == 'x')
                map[PLAYER_POSITION + offset] = 'O';

            else {
                map[PLAYER_POSITION - offset] = '@';
                return;
            }

            map[PLAYER_POSITION] = '@';
        }

        else
        {
            map[PLAYER_POSITION] = ' ';
            pos_x += offset;
            map[PLAYER_POSITION] = '@';
        }
    }
}

void PlayerPosition(int* pos_x, int* pos_y) {
    int cell; // current cell index

    for (int row = 0; row < MAP_HEIGHT; row++) // loop ower map rows
    {
        for (int col = 0; col < MAP_WIDTH; col++) // loop ower map columns
        {
            cell = row * MAP_WIDTH + col; // init current cell index

            if (map[cell] == '@') // if current cell on the map contains player
            {
                *pos_x = col; // store player's x coordinate
                *pos_y = row; // store player's y coordinate
            }
        }
    }
}