//
//  Board.hpp
//  Minesweeper
//
//  Created by Hodaka Suzuki on 2017/11/20.
//  Copyright © 2017年 Hodaka Suzuki. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include "Cell.hpp"
#include "Config.h"

using namespace std;

class Board{
    
public:
    Board(int rowNum, int colNum, int mineNum);

    void print();

    void open(int x, int y);
    void flag(int x, int y);
    
    BoardStatus getStatus();
    
private:
    vector<vector<Cell*>> m_cells;
    
    int m_rowNum;
    int m_colNum;
    int m_mineNum;
    int m_safeCellNum;
    
    int m_openSafeCellCount; // オープンした地雷ではないマスの数
    
    bool m_bOpenMineCell;
};

#endif /* Board_hpp */
