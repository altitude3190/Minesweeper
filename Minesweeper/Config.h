//
//  Config.h
//  Minesweeper
//
//  Created by Hodaka Suzuki on 2018/02/12.
//  Copyright © 2018年 Hodaka Suzuki. All rights reserved.
//

#ifndef Config_h
#define Config_h

enum BoardStatus
{
    Ongame,
    Win,
    Lose
};

enum CellStatus
{
    Opened,
    Flagged,
    Untouched,
};

#endif /* Config_h */
