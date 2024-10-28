
#include "Grid.h"
#include "Game.h"

Grid::Grid(int r, int c, int size) : rows(r), cols(c), cellSize(size)
{
    for (int i = 0; i < rows; i++)
    {
        std::vector<Cell> row;
        for (int j = 0; j < cols; j++)
        {
            row.emplace_back(Cell{*this, j, i});
        }
        grid.push_back(row);
    }

    startX = (screenWidth - cols * cellSize) / 2;
    startY = (screenHeight - rows * cellSize) / 2;
}

std::shared_ptr<Block> Grid::GetBlock(int x, int y)
{
    return grid[x][y].block;
}

void Grid::SetBlock(int x, int y, std::shared_ptr<Block> block)
{
    grid[x][y].block = block;
}

void Grid::Draw()
{

    for (int i = 0; i <= cols; i++)
    {
        DrawLine(startX + i * cellSize, startY, startX + i * cellSize, startY + rows * cellSize, LIGHTGRAY);
    }
    for (int j = 0; j <= rows; j++)
    {
        DrawLine(startX, startY + j * cellSize, startX + cols * cellSize, startY + j * cellSize, LIGHTGRAY);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[j][i].block)
            {

                grid[j][i].block->Draw();
            }
        }
    }
}