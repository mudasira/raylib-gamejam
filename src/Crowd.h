#ifndef CROWD_H
#define CROWD_H

#include "Block.h"

enum PersonType
{
    ADULT,
    CHILD,
    ELDER
};

class Person
{
    public:
    int x, y;
    PersonType type;
};

class Crowd : public Block
{
public:
    std::vector<Person>

    Crowd(int x, int y, int size) : Block(x, y, size, BLUE) {}

    void Draw() override
    {
        Block::Draw();
        // Additional drawing logic for Water if needed
        DrawCircle(x + size/2, y + size/2, 5, MAGENTA);

    }
};

#endif