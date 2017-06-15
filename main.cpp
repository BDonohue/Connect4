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
	cout << "We have a winner: " << player << endl;
	return 0;
}

void printBoard(int (&board)[ROW][COLUMN]){
	cout << "1 2 3 4 5 6 7" << endl;
	for(int i = 0; i < ROW; i++){
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
	int player = 0;
	for(int i = 0; i < COLUMN; i++){
		for(int j = ROW - 1; j > -1; j--){
			cout << i << " " << j << endl;
			if(board[i][j] == 0){
				break;
			}
			player = board[i][j];
			//straight up
			for(int k = 1; k < 4; k++){
				if(board[i][j+k] != player){
					break;
				}
				return true;
			}
			//bottom left to top right
			for(int k = 1; k < 4; k++){
				if(board[i+k][j+k] != player){
					break;
				}
				return true;
			}
			//straight right
			for(int k = 1; k < 4; k++){
				if(board[i+k][j] != player){
					break;
				}
				return true;
			}
			//top left to bottom right
			for(int k = 1; k < 4; k++){
				if(board[i+k][j-k] != player){
					break;
				}
				return true;
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