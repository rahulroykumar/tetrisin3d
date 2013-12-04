#include "Board.h"

Board::Board(int col, int row)
{
    mCol = col;
    mRow = row;
}

Board::~Board()
{
    for(int i=0; i<mRow; i++)
        delete [] mLanded[i];
    delete [] mLanded;
}

void Board::InitBoard()
{
    mLanded = new unsigned int*[mRow];
    for(int i=0; i<mRow; i++) mLanded[i] = new unsigned int[mCol];

    for(int row=0; row<mRow; row++)
    {
        for(int col=0; col<mCol; col++)
        {
            mLanded[row][col] = 0;
        }
    }

    for(int col=0; col<mCol; col++)
    {
        mLanded[9][col] = 1;
    }
}

unsigned int** Board::GetLanded()
{
    return mLanded;
}

void Board::LandShape(Tetromino *tetromino)
{
    for (int row=0; row<4; row++)
    {
        for (int col=0; col<4; col++)
        {
            if (tetromino->getShape()[row][col] != 0)
            {
                mLanded[row + tetromino->getPositionRow()][col + tetromino->getPositionCol()] = tetromino->getShape()[row][col];
            }
     }
}
}