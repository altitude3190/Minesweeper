//
//  Cell.hpp
//  Minesweeper
//
//  Created by Hodaka Suzuki on 2017/11/19.
//  Copyright © 2017年 Hodaka Suzuki. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "Config.h"

class Cell{

public:
    Cell(int x, int y, bool isMine, int aroundMineCount);
    int getAroundMineCount();
    
    void open();
    void flag();
    void unflag();
    
    bool isOpened();
    bool isFlagged();
    bool isMine();
    
    CellStatus getStatus();
    
private:
    int x,y;
    bool m_bMine;
    int m_aroundMineCount;
    
    bool m_bFlagged;
    bool m_bOpened;
};

#endif /* Cell_hpp */
