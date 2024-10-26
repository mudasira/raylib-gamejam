
#include "Grid.h"
#include "Game.h"

void Grid::Draw()
{
    int startX = (screenWidth - cols * cellSize) / 2;
    int startY = (screenHeight - rows * cellSize) / 2;

    for (int i = 0; i <= cols; i++)
    {
        DrawLine(startX + i * cellSize, startY, startX + i * cellSize, startY + rows * cellSize, LIGHTGRAY);
    }
    for (int j = 0; j <= rows; j++)
    {
        DrawLine(startX, startY + j * cellSize, startX + cols * cellSize, startY + j * cellSize, LIGHTGRAY);
    }
}