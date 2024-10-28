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
    int size;
    PersonType type;
};

class Crowd : public Block
{
public:
    std::vector<Person> people;

    Crowd(int x, int y, int size) : Block(x, y, size, BEIGE) {
    }

    void setup()
    {
        auto numPeople = GetRandomValue(2, 5);
        auto numAdults = GetRandomValue(0, numPeople);
        auto numChildren = GetRandomValue(0, numPeople - numAdults);
        auto numElders = numPeople - numAdults - numChildren;

        setupPeople(numAdults, numChildren, numElders);
    }

    void setupPeople(int numAdults, int numChildren, int numElders)
    {
        for (int i = 0; i < numAdults; i++)
        {
            Person p;
            p.type = ADULT;
            p.x = x + size/2 + GetRandomValue(-size/4, size/4);
            p.y = y + size/2 + GetRandomValue(-size/4, size/4);
            people.push_back(p);
        }

        for (int i = 0; i < numChildren; i++)
        {
            Person p;
            p.type = CHILD;
            p.x = x + size/2 + GetRandomValue(-size/4, size/4);
            p.y = y + size/2 + GetRandomValue(-size/4, size/4);
            people.push_back(p);
        }

        for (int i = 0; i < numElders; i++)
        {
            Person p;
            p.type = ELDER;
            p.x = x + size/2 + GetRandomValue(-size/4, size/4);
            p.y = y + size/2 + GetRandomValue(-size/4, size/4);
            people.push_back(p);
        }
    }

    void Draw() override
    {
        //Block::Draw();
        DrawRectangle(x, y, size, size, color);
        // Additional drawing logic for Water if needed
        //DrawCircle(x + size/2, y + size/2, 5, MAGENTA);
        for (auto &person : people)
        {
            switch (person.type)
            {
            case ADULT:
                DrawCircle(person.x, person.y, 5, MAGENTA);
                break;
            case CHILD:
                DrawCircle(person.x, person.y, 2, MAGENTA);
                break;
            case ELDER:
                DrawCircle(person.x, person.y, 4, MAGENTA);
                break;
            }
        }

    }
};

#endif