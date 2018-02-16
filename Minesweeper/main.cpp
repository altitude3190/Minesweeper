//
//  main.cpp
//  Minesweeper
//
//  Created by Hodaka Suzuki on 2017/11/19.
//  Copyright © 2017年 Hodaka Suzuki. All rights reserved.
//

#include <iostream>
#include "Board.hpp"
#include "Cell.hpp"

const int rowNum = 9;
const int colNum = 9;
const int mineNum = 9;

int main()
{
    srand((int)time(0));
    
    Board* board = new Board(rowNum, colNum, mineNum);
    
    while (true)
    {
        while(board->getStatus() == Ongame)
        {
            board->print();
            
            // 入力受付用変数
            int x, y;
            string yn;
            
            while (true)
            {
                // 標準入力受付
                
                cout << "row: ";
                for (cin >> x; !cin; cin >> x)
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please input integer." << endl << "row: ";
                }
                
                cout << "col: ";
                for (cin >> y; !cin; cin >> y)
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please input integer." << endl << "col: ";
                }
                
                cout << "flag? [y/n] ";
                for (cin >> yn; !cin || !(yn == "y" || yn == "n"); cin >> yn)
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input. Please input y or n." << endl << "flag? [y/n] ";
                }
                
                break;
            }
            
            if (yn == "y")
            {
                board->flag(x, y);
            }
            else
            {
                board->open(x, y);
            }
        }
        
        if (board->getStatus() != Ongame) break;
    }
    
    board->print();
    if (board->getStatus() == Win)
    {
        cout << "you win!\n";
    }
    else if (board->getStatus() == Lose)
    {
        cout << "you lose!\n";
    }
}
