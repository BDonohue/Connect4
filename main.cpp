#include <iostream>
#include <string>
#include <stdexcept>  
#define ROW 6
#define COLUMN 7
using namespace std;

void printBoard(int (&board)[ROW][COLUMN]);
bool checkWin(int (&board)[ROW][COLUMN]);
int updateBoard(int (&board)[ROW][COLUMN], int rowPos, int player);
//Empty = 0
//Red = player 1
//Black = player 2

main(){
	//initialize board
	int board[ROW][COLUMN];
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COLUMN; j++){
			board[i][j] = 0; //j+i*COLUMN;
		}
	}

	string inputStr;
	int inputNum;
	int player = 1;
	while(!checkWin(board)){
		printBoard(board);
		cout << "choose a position" << endl;
		cin >> inputStr;
		if(inputStr == "quit"){
			break;
		}
		//check if input is valid
		try{
			inputNum = stoi(inputStr);
		}
		catch(const invalid_argument& ia){
			inputNum = -1;
			cout << "Input just numbers please" << endl;
			continue;
		}
		if(inputNum < 1 || inputNum > 7){
			cout << "Enter a real option" << endl;
			continue;
		}	
		//update board
		if(!updateBoard(board,inputNum,player)){
			cout << "That column is full" << endl;
		} else {
			if(player == 1){
				player = 2;
			} else {
				player = 1;
			}
		}
	}
	if(player == 1){
		player = 2;
	} else {
		player = 1;
	}
	printBoard(board);
	cout << "We have a winner: " << player << endl;
	return 0;
}

void printBoard(int (&board)[ROW][COLUMN]){
	cout << "  1 2 3 4 5 6 7" << endl;
	for(int i = 0; i < ROW; i++){
		cout << i+1 << " ";
		for(int j = 0; j < COLUMN; j++){
			switch(board[i][j]){
				case 0: cout << "_ ";
					break;
				case 1: cout << "B ";
					break;
				case 2: cout << "W ";
					break;
			}
		}
		cout << endl;
	}
}

bool checkWin(int (&board)[ROW][COLUMN]){
	int player, countA, countB;
	for(int i = 0; i < COLUMN; i++){
		for(int j = ROW - 1; j > -1; j--){
			if(board[j][i] == 0){
				break;
			}
			cout << j+1 << " " << i+1 << endl;
			player = board[j][i];
			countB = player * player * player * player;
			//up
			if(j > 2){
				countA = player;
				countA = countA * board[j-1][i] * board[j-2][i] * board[j-3][i];
				if(countA == countB){
					return true;
				}
			}
			//condition for next 3
			if(i > COLUMN - 4){
				break;
			}
			//right
			if(1){
				countA = player;
				countA = countA * board[j][i+1] * board[j][i+2] * board[j][i+3];
				if(countA == countB){
					return true;
				}
			}
			//up and right
			if(j > 2){
				countA = player;
				countA = countA * board[j-1][i+1] * board[j-2][i+1] * board[j-3][i+1];
				if(countA == countB){
					return true;
				}
			}
			//down and right
			if(j < ROW - 3){
				countA = player;
				countA = countA * board[j+1][i+1] * board[j+2][i+1] * board[j+3][i+1];
				if(countA == countB){
					return true;
				}
			}
		}
	}
	return false;
}

int updateBoard(int (&board)[ROW][COLUMN], int rowPos, int player){
	if(board[0][rowPos-1] != 0){
		return 0;
	}
	int i = 0;
	while(i < ROW-1){
		if(board[i+1][rowPos-1] != 0){
			board[i][rowPos-1] = player;
			return 1;
		}
		i++;
	}
	board[ROW-1][rowPos-1] = player;
	return 1;
}