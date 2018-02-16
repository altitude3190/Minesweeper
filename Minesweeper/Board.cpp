//
//  Board.cpp
//  Minesweeper
//
//  Created by Hodaka Suzuki on 2017/11/20.
//  Copyright © 2017年 Hodaka Suzuki. All rights reserved.
//

#include <iostream>
#include "Board.hpp"
#include "Cell.hpp"
#include <vector>

Board::Board(int rowNum, int colNum, int mineNum)
    :m_bOpenMineCell(false)
    ,m_openSafeCellCount(0)
{
    this->m_rowNum = rowNum;
    this->m_colNum = colNum;
    this->m_mineNum = mineNum;
    this->m_safeCellNum = m_rowNum * m_colNum - m_mineNum;
    
    // 地雷の座標決め
    map<int, map<int, bool>> mineMap;
    for (int i = 0; i < m_mineNum; i++)
    {
        bool alreadyMined = false;
        do
        {
            int x = rand() % m_rowNum + 1;
            int y = rand() % m_colNum + 1;
            alreadyMined = mineMap[x][y] ? true : false;
            if (!alreadyMined)
                mineMap[x][y] = true;
            printf("x: %d, y: %d", x, y);
        }
        while (alreadyMined);
    }
    
    m_cells.resize(m_rowNum + 2);
    for (int i = 0; i <= m_rowNum + 1; i++)
    {
        m_cells[i].resize(m_rowNum + 2);
        for (int j = 0; j <= m_colNum + 1; j++)
        {
            // 8近傍の地雷数チェック（自身が地雷であったとしてもカウント処理は走らせておく）
            int mineCount = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (mineMap[k][l] && !(k == i && l == j))
                        mineCount++;
                }
            }
            m_cells[i][j] = new Cell(i, j, mineMap[i][j], mineCount);
            
            // 番兵は最初からオープンしておく
            if (i == 0 || j == 0 || i == m_rowNum + 1 || j == m_colNum + 1)
                m_cells[i][j]->open();
        }
    }
}

void Board::print()
{
    cout << "\n";
    for (int i = 0; i <= m_rowNum; i++)
    {
        for(int j = 0; j <= m_colNum; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                    cout << " ";
                else
                    cout << j << " ";
                continue;
            }
            
            if (j == 0)
            {
                cout << i;
                continue;
            }
            
            switch (m_cells[i][j]->getStatus())
            {
                case Opened:
                    if (m_cells[i][j]->isMine())
                        cout << "* ";
                    else if (m_cells[i][j]->getAroundMineCount() == 0)
                        cout << "- ";
                    else
                        cout << m_cells[i][j]->getAroundMineCount() << " ";
                    break;
                case Flagged:
                    cout << "f ";
                    break;
                case Untouched:
                    cout << "  ";
                    break;
                default:
                    break;
            }
        }
        cout << "\n";
    }
}

void Board::open(int x, int y)
{
    if (!m_cells[x][y])
        return;
    
    if (m_cells[x][y]->isOpened())
        return;
    
    // フラグが立っていた場合は、フラグを折る
    if (m_cells[x][y]->isFlagged())
        m_cells[x][y]->unflag();
    
    m_cells[x][y]->open();
    
    if (m_cells[x][y]->isMine())
    {
        m_bOpenMineCell = true;
        return;
    }
    
    m_openSafeCellCount++;
    
    // 8近傍の爆弾の数が0のときは、8近傍のマスもオープンしていく
    if (m_cells[x][y]->getAroundMineCount() > 0)
        return;
    
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            open(i, j);
        }
    }
}

void Board::flag(int x, int y)
{
    if (!m_cells[x][y])
        return;
    
    m_cells[x][y]->flag();
}

BoardStatus Board::getStatus()
{
    if (m_bOpenMineCell)
        return Lose;
    
    if (m_safeCellNum == m_openSafeCellCount)
        return Win;
    
    return Ongame;
}







