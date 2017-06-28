#define ROW 6
#define COLUMN 7
#include "ComputerPlayer.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

ComputerPlayer::ComputerPlayer(int playerInput){
	setPlayer(playerInput);
}

void ComputerPlayer::setPlayer(int playerInput){
	player = playerInput;
}

int ComputerPlayer::choosePosition(int (&board)[ROW][COLUMN]){
	cout << "Generating random drop" << endl;
	srand(time(NULL));
	return (rand() % 7 + 1);
}