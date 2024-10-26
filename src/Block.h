#ifndef BLOCK_H
#define BLOCK_H

#include <raylib.h>

class Block
{
public:
    int x, y;
    int size;
    Color color;

    Block(int x, int y, int size, Color color) : x(x), y(y), size(size), color(color) {}

    virtual void Draw()
    {
        DrawRectangle(x, y, size, size, color);
    }
};

#endif