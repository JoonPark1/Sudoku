#include <iostream>
#include <vector>
using namespace std;

void print_board(int array[9][9])
{
    cout << "------------------" << endl;
    for(int row; row < 9; row++)
    {
        for(int col; col < 9; col++)
        {
            cout << " " << array[row][col] << " ";
        }
        cout << "\n";
    }

    cout << "------------------" << endl;
}
//Checks whether particular n from 1-9 can be placed in certain cell, based on row, column, and the 3*3 subgrid.
bool can_place(int array[9][9], int row, int col, int n)
{   
    int sub_grid_row = row - (row%3);
    int sub_grid_col = col - (col%3);
    //Base Case: If the cell is already filled, can't place the number.
    if(array[row][col] != 0){return false;}
    for(int i = 0; i < 9; i++)
    {   if(array[row][i] == n) {return false; break;}//checking particular row
        if(array[i][col] == n) {return false; break;} //checking particular column
    }
    //checking particular 3*3 subgrid that a particular row or column is part of
    for(int z = 0; z < 3; z++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(array[z + sub_grid_row][j + sub_grid_col] == n){return false; break;}
            }
        }
    return true;
}

bool did_win(int array[9][9])
{
    //check each row
    int row;
    bool counter1;
    for(row = 0; row < 9; row++)
    {
        if (not (array[row][0] != array[row][1] != array[row][2] != array[row][3]!= array[row][4] != array[row][5] != array[row][6] != array[row][7] != array[row][8] != 0))
        {
            counter1 = false;
            break;
        }
    }
    //check each column
    int col;
    bool counter2;
    for(col = 0; col < 9; col++)
    {
        if (not (array[0][col] != array[1][col] != array[2][col] != array[3][col] != array[4][col] != array[5][col] != array[6][col] != array[7][col] != array[8][col] != 0))
        {
            counter2 = false;
            break;
        }

    }
    //check each 3*3 subgrid(if there is even a single cell with zero, that means sudoku isn't solved yet.)
    bool counter3;
    int sub_grid_row;
    int sub_grid_col;
    for(sub_grid_row = 0; sub_grid_row < 9; sub_grid_row += 3)
    {
        for(sub_grid_col = 0; sub_grid_col < 9; sub_grid_col += 3)
        {
            if (not (array[sub_grid_row][sub_grid_col]!=array[sub_grid_row][sub_grid_col + 1] != array[sub_grid_row][sub_grid_col + 2] != array[sub_grid_row+1][sub_grid_col] != array[sub_grid_row + 1][sub_grid_col + 1] != array[sub_grid_row+1][sub_grid_col+2] != array[sub_grid_row + 2][sub_grid_col] != array[sub_grid_row +2][sub_grid_col + 1] != array[sub_grid_row + 2][sub_grid_col + 2] != 0))
            {
                counter3 = false;
                break;
            }
        }
    }
    return counter1 && counter2 && counter3;
}

int main()
{
    // Initializing zeros to all empty cells.
    int game_board[9][9] = {
                    {0, 0, 2, 4, 3, 7, 0, 0, 0},
                    {0, 0, 3, 5, 9, 2, 0, 0, 0},
                    {1, 0, 6, 0, 0, 0, 3, 0, 2},
                    {2, 3, 5, 1, 0, 0, 4, 0, 0},
                    {0, 0, 0, 2, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {6, 9, 1, 0, 0, 3, 8, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {5, 2, 4, 9, 6, 0, 0, 0, 0}
        
                            };
    print_board(game_board);
    int num, row, col;
    cout << "What number do you want to use?\n" << endl;
    cin >>  num;
    cout << "What row are you considering?\n" << endl;
    cin >> row;
    cout << "What column are you considering?\n" << endl;
    cin >> col;
    /*As long as game is not won, the game will continue. If a certain number
    violated one of the Sudoku rules at a particular cell, the player must
    pick a different number. */
    while(did_win(game_board) != true)
    {
        if(can_place(game_board, row, col, num))
        {
            game_board[row][col] = num;
            cout << "What is the next row you want?\n" << endl;
            cin >> row;
            cout << "What is the next column you want?\n" << endl;
            cin >> col;
            cout << "What next number do you want to choose?\n" << endl;
        }
        else
        {
            cout << "Consider other potential numbers...\n" << endl;
            cout << "Type in a new number.\n" << endl;
            cin >> num;
            

        }
    }

}