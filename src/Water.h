#ifndef WATER_H
#define WATER_H

#include "Block.h"

class Water : public Block
{
public:
    Water(int x, int y, int size) : Block(x, y, size, BLUE) {}

    void Draw() override
    {
        Block::Draw();
        // Additional drawing logic for Water if needed
    }
};

#endif