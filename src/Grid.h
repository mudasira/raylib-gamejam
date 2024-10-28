#ifndef GRID
#define GRID

#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "Block.h"
#include "Cell.h"



class Grid
{
public:
    int rows;
    int cols;
    int cellSize;
    int startX;
    int startY;
    std::vector<std::vector<Cell>> grid;

    Grid(int r = 10, int c = 10, int size = 40);
    std::shared_ptr<Block> GetBlock(int x, int y);
    void SetBlock(int x, int y, std::shared_ptr<Block> block);

    void Draw();
};

#endif