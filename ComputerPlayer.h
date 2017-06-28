#define ROW 6
#define COLUMN 7

class ComputerPlayer{
	public:
		explicit ComputerPlayer(int playerInput);
		int choosePosition(int (&board)[ROW][COLUMN]);
	private:
		void setPlayer(int playerInput);
		int player;
};