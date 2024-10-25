#ifndef GRID
#define GRID

#include <raylib.h>
#include <vector>
#include <iostream>
#include <string>

    class Grid
    {
    public:
        int rows;
        int cols;
        int cellSize;

        Grid(int r = 10, int c = 10, int size = 40) : rows(r), cols(c), cellSize(size) {}
        void Draw();
    };

#endif