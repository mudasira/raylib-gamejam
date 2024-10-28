#ifndef BLOCK_H
#define BLOCK_H

#include <raylib.h>
#include <vector>
#include <memory>

class Cell;

class Block
{
public:
    int cellX, cellY;
    int x, y;
    int size;
    Color color;
    // std::vector<std::shared_ptr<Cell>> cells;

    Block(int x, int y, int size, Color color) : x(x), y(y), size(size), color(color) {}

    virtual void Draw()
    {
        DrawRectangle(x, y, size, size, color);
    }
};

#endif