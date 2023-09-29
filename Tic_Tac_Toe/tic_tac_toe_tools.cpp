/****************************************************************
 * Project Name:  Tic_Tac_Toe
 * File Name:     tic_tac_toe_tools.cpp
 * File Function: 工具函数的实现
 * Author:        Jishen Lin (林继申)
 * Update Date:   2023/9/30
 ****************************************************************/

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "..\common\cmd_console_tools.h"
#include "tic_tac_toe.h"

using namespace std;

/*
 * Function Name:    menu
 * Function:         Display menu items and read the correct option
 * Input Parameters: void
 * Return Value:     option
 */
int menu(void)
{
    cct_cls();
    cout << "               Tic Tac Toe" << endl;
    cout << "               井字棋游戏" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "  1.双人对战模式" << endl;
    cout << "    Player vs. Player Mode" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "  2.人机对战模式（AI先手）" << endl;
    cout << "    Player vs. AI Mode (AI Goes First)" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "  3.人机对战模式（AI后手）" << endl;
    cout << "    Player vs. AI Mode (AI Goes Second)" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "  4.AI对战模式" << endl;
    cout << "    AI vs. AI Mode" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "  0.退出" << endl;
    cout << "    Quit" << endl;
    cout << "-----------------------------------------" << endl;;
    cout << "  [请选择:] ";
    char optn;
    while (true) {
        optn = _getch();
        if (optn >= '0' && optn <= '4') {
            cout << optn << endl << endl;
            Sleep(300);
            return optn - '0';
        }
    }
}

/*
 * Function Name:    print_grid_status
 * Function:         Print grid status
 * Input Parameters: GridStatus gridStatus[][BOARD_SIZE]
 * Return Value:     void
 */
void print_grid_status(GridStatus gridStatus[][BOARD_SIZE])
{
    cout << "     1  2  3" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << "   +--+--+--+" << endl << " " << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; j++)
            cout << "|" << (gridStatus[i][j] == Empty ? "  " : (gridStatus[i][j] == FirstPlayer ? "×" : "○"));
        cout << "|" << endl;
    }
    cout << "   +--+--+--+" << endl;
}

/*
 * Function Name:    input_digit
 * Function:         Input and return a digit
 * Input Parameters: int lowerLimit
 *                   int upperLimit
 * Return Value:     digit
 */
int input_digit(int lowerLimit, int upperLimit)
{
    char optn;
    while (true) {
        optn = _getch();
        if (optn >= '0' + lowerLimit && optn <= '0' + upperLimit) {
            cout << optn << endl;
            return optn - '0';
        }
    }
}