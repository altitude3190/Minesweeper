//
//  Cell.cpp
//  Minesweeper
//
//  Created by Hodaka Suzuki on 2017/11/19.
//  Copyright © 2017年 Hodaka Suzuki. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell(int x, int y, bool isMine, int aroundMineCount)
    :m_bOpened(false)
    ,m_bFlagged(false)
{
    this->x = x;
    this->y = y;
    this->m_bMine = isMine;
    this->m_aroundMineCount = aroundMineCount;
}

int Cell::getAroundMineCount()
{
    return m_aroundMineCount;
}

void Cell::open()
{
    m_bOpened = true;
}

void Cell::flag()
{
    m_bFlagged = true;
}

void Cell::unflag()
{
    m_bFlagged = false;
}

bool Cell::isOpened()
{
    return m_bOpened;
}

bool Cell::isFlagged()
{
    return m_bFlagged;
}

bool Cell::isMine()
{
    return m_bMine;
}

CellStatus Cell::getStatus()
{
    if (m_bOpened)
        return Opened;
    if (m_bFlagged)
        return Flagged;
    return Untouched;
}
