#include "BrickArea.h"
#include "Brick.h"

#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <cstdio>
using std::scanf;

/// Parses a line into a Brick object.
static bool parseToBrick(const string & line, Brick & brick,
                         unsigned rows, unsigned cols);

BrickArea::BrickArea(unsigned nRows, unsigned nColumns) :
    bricks_(0), nRows_(nRows), nColumns_(nColumns), totalBricks_(0),
    breakableBricks_(0), remainingBricks_(0)
{
    unsigned size = nRows * nColumns;
    
    bricks_ = new Brick[size];
    for (unsigned i = 0; i < size; i++) {
        bricks_[i].setParent(this);
    }
}

BrickArea::~BrickArea()
{
    if (bricks_ != 0) {
        delete [] bricks_;
    }
}

const Brick * BrickArea::bricks() const
{
    return bricks_;
}

Brick * BrickArea::bricks()
{
    return bricks_;
}

unsigned BrickArea::nRows() const
{
    return nRows_;
}

unsigned BrickArea::nColumns() const
{
    return nColumns_;
}

unsigned BrickArea::totalBricks() const
{
    return totalBricks_;
}

unsigned BrickArea::breakableBricks() const
{
    return breakableBricks_;
}

unsigned BrickArea::remainingBricks() const
{
    return remainingBricks_;
}

void BrickArea::setTotalBricks(unsigned totalBricks)
{
    totalBricks_ = totalBricks;
}

void BrickArea::setBreakableBricks(unsigned breakableBricks)
{
    breakableBricks_ = breakableBricks;
}

void BrickArea::setRemainingBricks(unsigned remainingBricks)
{
    remainingBricks_ = remainingBricks;
}

bool BrickArea::loadLevel(const char * levelName)
{
    ifstream levelFile(levelName);
    string line;
    unsigned index = 0;
    bool levelLoaded = false;
    bool parseOk = true;
    
    if (levelFile.is_open()) {
        totalBricks_ = breakableBricks_ = remainingBricks_ = 0;
        getline(levelFile, line);
        while (!levelFile.eof() && parseOk) {
            parseOk = parseToBrick(line, bricks_[index], nRows_, nColumns_);
            if (bricks_[index].isBreakable()) {
                breakableBricks_++;
                remainingBricks_++;
            }
            totalBricks_++;
            line = "";
            getline(levelFile, line);
            index++;
        }
        levelLoaded = (parseOk && levelFile.eof());
        levelFile.close();
    }
    
    return levelLoaded;
}

bool BrickArea::isCleared() const
{
    return (remainingBricks_ == 0);
}

///////////////
// Functions //
///////////////

bool parseToBrick(const string & line, Brick & brick,
                  unsigned rows, unsigned cols)
{
    unsigned row, column, color, breakable, type;
    bool parseOk = true;
    
    sscanf(line.c_str(), "%u,%u,%u,%u,%u", &row, &column, &color, &breakable, &type);
    if ((row >= rows) || (column >= cols) ||
        (color >= Brick::BRICK_COLOR_N_COLORS) ||
        (type >= Brick::BRICK_TYPE_N_TYPES)) {
        parseOk = false;
    }
    
    if (parseOk) {
        brick.setRow(row);
        brick.setColumn(column);
        brick.setBreakable(breakable != 0);
        switch (type) {
        case Brick::BRICK_TYPE_NORMAL:
            brick.setHitPoints(1);
            break;
        case Brick::BRICK_TYPE_METAL:
            brick.setHitPoints(2);
            color = Brick::BRICK_COLOR_SILVER;
            break;
        case Brick::BRICK_TYPE_IMMORTAL:
            brick.setHitPoints(0xFFFFFFFF);
            color = Brick::BRICK_COLOR_GOLDEN;
            break;
        }
        brick.setColor(color);
    }
    
    return parseOk;
}
