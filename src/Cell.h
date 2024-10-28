#ifndef CELL_H
#define CELL_H


#include <memory>

class Block;
class Grid;

class Cell
{
public:
    const Grid &grid;
    const int x, y;
    std::shared_ptr<Block> block;
};

#endif