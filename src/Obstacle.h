
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Block.h"


    class Obstacle : public Block
    {
    public:
        Obstacle(int x, int y, int size) : Block(x, y, size, GRAY) {}

        void Draw() override
        {
            Block::Draw();
            // Additional drawing logic for Obstacle if needed
        }
    };

    #endif