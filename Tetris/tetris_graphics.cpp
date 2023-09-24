/****************************************************************
 * Project Name:  Tetris
 * File Name:     tetris_graphics.cpp
 * File Function: ͼ�λ����溯����ʵ��
 * Author:        Jishen Lin (�ּ���)
 * Update Date:   2023/9/25
 ****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "tetris.h"
using namespace std;

/*
 * Function Name:    print_specified_grid
 * Function:         Print a grid with specified number of rows and columns
 * Input Parameters: int startRow
 *                   int startCol
 *                   int row
 *                   int col
 * Return Value:     void
 */
static void print_specified_grid(int startRow, int startCol, int row = gridRow, int col = gridCol)
{
    int offsetX = startCol * (gridSideLength + gridSpace), offsetY = startRow * (gridSideLength + gridSpace);
    for (int i = 0; i <= row; i++)
        for (int j = 0; j < gridSpace; j++) {
            int y = topGridMargin + i * (gridSideLength + gridSpace) + j;
            line(leftGridMargin + offsetX, y + offsetY, leftGridMargin + col * (gridSideLength + gridSpace) + gridSpace - 1 + offsetX, y + offsetY);
        }
    for (int i = 0; i <= col; i++)
        for (int j = 0; j < gridSpace; j++) {
            int x = leftGridMargin + i * (gridSideLength + gridSpace) + j;
            line(x + offsetX, topGridMargin + offsetY, x + offsetX, topGridMargin + row * (gridSideLength + gridSpace) + gridSpace - 1 + offsetY);
        }
}

/*
 * Function Name:    print_frame
 * Function:         Print frame
 * Input Parameters: int startRow
 *                   int startCol
 *                   int endRow
 *                   int endCol
 * Return Value:     void
 */
static void print_frame(int startRow, int startCol, int endRow, int endCol)
{
    /* Set line color */
    setlinecolor(BLACK);

    /* Calculate offsets */
    int offsetX = startCol * (gridSideLength + gridSpace), offsetY = startRow * (gridSideLength + gridSpace);

    /* Print frame */
    for (int i = 0; i < gridSpace; i++) {
        int y = topGridMargin + i;
        line(leftGridMargin + offsetX, y + offsetY, leftGridMargin + (endCol - startCol) * (gridSideLength + gridSpace) + gridSpace - 1 + offsetX, y + offsetY);
    }
    for (int i = 0; i < gridSpace; i++) {
        int x = leftGridMargin + i;
        line(x + offsetX, topGridMargin + offsetY, x + offsetX, topGridMargin + (endRow - startRow) * (gridSideLength + gridSpace) + gridSpace - 1 + offsetY);
    }
    for (int i = 0; i < gridSpace; i++) {
        int y = topGridMargin + (endRow - startRow) * (gridSideLength + gridSpace) + i;
        line(leftGridMargin + offsetX, y + offsetY, leftGridMargin + (endCol - startCol) * (gridSideLength + gridSpace) + gridSpace - 1 + offsetX, y + offsetY);
    }
    for (int i = 0; i < gridSpace; i++) {
        int x = leftGridMargin + (endCol - startCol) * (gridSideLength + gridSpace) + i;
        line(x + offsetX, topGridMargin + offsetY, x + offsetX, topGridMargin + (endRow - startRow) * (gridSideLength + gridSpace) + gridSpace - 1 + offsetY);
    }
}

/*
 * Function Name:    initialize_graphics
 * Function:         Initialize the graphical interface
 * Input Parameters: void
 * Return Value:     void
 */
void initialize_graphics(void)
{
    /* Initialize the graphical interface */
    initgraph(leftGridMargin + rightGridMargin + (gridCol + displayGridSideLength + 1) * (gridSideLength + gridSpace) + gridSpace, topGridMargin + bottomGridMargin + gridRow * (gridSideLength + gridSpace) + gridSpace);
    setbkcolor(GRID_BLANK_COLOR);
    setlinecolor(GRID_LINE_COLOR);
    cleardevice();

    /* Print specified grids */
    print_specified_grid(0, 0);
    print_specified_grid(4, gridCol + 1, displayGridSideLength, displayGridSideLength);
    print_specified_grid(5 + 1 * (displayGridSideLength + 1), gridCol + 1, displayGridSideLength, displayGridSideLength);
    print_specified_grid(5 + 2 * (displayGridSideLength + 1), gridCol + 1, displayGridSideLength, displayGridSideLength);
    print_specified_grid(5 + 3 * (displayGridSideLength + 1), gridCol + 1, displayGridSideLength, displayGridSideLength);

    /* Print frames */
    print_frame(0, 0, gridRow, gridCol);
    print_frame(4, gridCol + 1, 4 + displayGridSideLength, gridCol + 1 + displayGridSideLength);
    print_frame(5 + 1 * (displayGridSideLength + 1), gridCol + 1, 5 + 1 * (displayGridSideLength + 1) + displayGridSideLength, gridCol + 1 + displayGridSideLength);
    print_frame(5 + 2 * (displayGridSideLength + 1), gridCol + 1, 5 + 2 * (displayGridSideLength + 1) + displayGridSideLength, gridCol + 1 + displayGridSideLength);
    print_frame(5 + 3 * (displayGridSideLength + 1), gridCol + 1, 5 + 3 * (displayGridSideLength + 1) + displayGridSideLength, gridCol + 1 + displayGridSideLength);

    /* Print highest score */
    TCHAR infoText[96];
    _stprintf(infoText, _T("[��ʷ��߷֣�%d] ���ո����ʼ��Ϸ"), readHighestScore());
    settextcolor(BLACK);
    settextstyle(&Font_CN);
    outtextxy(leftGridMargin, topInfoMargin, infoText);
    _stprintf(infoText, _T("Lines:"));
    settextstyle(&Font_EN);
    outtextxy(leftGridMargin + (gridCol + 1) * (gridSideLength + gridSpace), topInfoMargin + 1 * (gridSideLength + gridSpace) + infoOffset, infoText);
    _stprintf(infoText, _T("Hold:"));
    outtextxy(leftGridMargin + (gridCol + 1) * (gridSideLength + gridSpace), topInfoMargin + 4 * (gridSideLength + gridSpace) + infoOffset, infoText);
    _stprintf(infoText, _T("Next:"));
    outtextxy(leftGridMargin + (gridCol + 1) * (gridSideLength + gridSpace), topInfoMargin + (6 + displayGridSideLength) * (gridSideLength + gridSpace) + infoOffset, infoText);
    settextstyle(&Font_CN);
}