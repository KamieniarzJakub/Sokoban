#include "DestinationSquares.h"

int GetDestSquares()
{
    int count = 0, cell;
    for (int i = 0; i < 10; i++) dest_squares[i] = 111;

    for (int row = 0; row < MAP_HEIGHT; row++)
    {
        for (int col = 0; col < MAP_WIDTH; col++)
        {
            cell = row * MAP_WIDTH + col;

            if (map[cell] == 'x' || map[cell] == 'O') dest_squares[count++] = cell; 
        }
    }
    return count;
}

int Check_destination_Squares()
{
    int dest_count = 0; // reset 'x' cells counter

    for (int i = 0; i < 10; i++) // for all destination squares
    {
        if (map[dest_squares[i]] == 'O')
            dest_count++; // increase 'x' cells counter if box is on 'x' cell

        if (map[dest_squares[i]] == ' ') // if 'x' cell has been erased
            map[dest_squares[i]] = 'x';    // restore it
    }
    return dest_count;
}