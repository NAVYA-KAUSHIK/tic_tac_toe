#include<iostream>
#include<string.h>

	char board[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

    void Instructions() 
    {
        std::cout << "Choose a cell numbered from 1 to 9 enter row and column as instructed " << std::endl;
        std::cout << "    |    |   " << std::endl;

        std::cout << "    |    |   " << std::endl;
        std::cout << " 1  |  2 |  3   "<< std::endl;
        std::cout << "____|____|____" << std::endl;
        std::cout << "  4 | 5  |  6   "  << std::endl;
        std::cout << "____|____|____" << std::endl;

        std::cout << "  7 |  8 |  9   " << std::endl;
        std::cout << "    |    |   " << std::endl;
        std::cout << " For cell 1 enter 0 0.similarly for cell 2  enter 0 1, cell 3 = 0 2,cell 4 = 1 0,cell 5 = 1 1,cell 6 = 1 2,cell 7 = 2 0,cell 8 = 2 1,cell 9 = 2 2" << std::endl;
        

        std::cout << "------------------------" << std::endl;



    }

	void Display_Board()
	{
		std::cout << "  TIC TAC TOE     " << std::endl;
		std::cout << "    |    |   " << std::endl;
		std::cout << " " << board[0][0] << "  |  " << board[0][1] << " |  " << board[0][2] << std::endl;
		std::cout << "____|____|____" << std::endl;
		std::cout << " " << board[1][0] << "  |  " << board[1][1] << " |  " << board[1][2] << std::endl;
		std::cout << "____|____|____" << std::endl;

		std::cout << " " << board[2][0] << "  |  " << board[2][1] << " |  " << board[2][2] << std::endl;
		std::cout << "    |    |   " << std::endl;
	}
    
	

bool Move(int row, int col, char mark) {
    //Moves which are invalid
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false; // Invalid move
    }
    board[row][col] = mark;
    return 1;
}

bool Win(char mark) {
    //cases of Winning
    for (int i = 0; i < 3; ++i) {
        //Row Win
        if (board[i][0] == mark && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1; 
        }
        //Column Win
        if (board[0][i] == mark && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1; 
        }
    }
    //Diagonal Wins
    if (board[0][0] == mark && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1; 
    }
    if (board[0][2] == mark && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1; 
    }
    return 0; // else there is no
}

bool Draw() {
    //case of Draw
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return 0; //Empty spaces left in game
            }
        }
    }
    return 1; // No empty space left
    // the game is declared draw 
}
int main()

{
    Instructions();
    bool p1turn = true;
    int count = 0;
    while (true) {
        Display_Board();
        int row;
        int col;
        char MyMark = (p1turn) ? 'X' : 'O';

        std::cout << "Player" << ((p1turn) ? "1" : "2") << ", enter the position(R&C) you want to put your mark in:  " << std::endl << "[Give a space between row and column]" << std::endl;
        //position entered as row and column 
        std::cin >> row >>col;

        if (Move(row, col, MyMark))
        {
            count++;

            if (Win(MyMark)) {
                Display_Board();
                std::cout << " Yahoo! Player " << ((p1turn) ? "1" : "2") << " WINS THE GAME  !" << std::endl;
                break;
            }
            else if (count == 9) {
                Display_Board();
                std::cout << "  THE GAME'S A DRAW  " << std::endl;
                break;
            }
            p1turn = !(p1turn);
        }
        else
        {
            std::cout << "INVALID CHOICE " << std::endl;
            // the loop starts again
        }
    }
    return 0;
    std::cout << std::endl;
    std::cout << std::endl;
}



