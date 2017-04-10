class Mob {
	//might include move class as member
	public:
		char getrow() {
			return row;
		}
		void setrow(int newrow) {
			row = newrow;
		}
		int getcolumn() {
			return column;
		}
		void setcolumn(int newcolum) {
			column = newcolum;
		}
		int getlife() {
			return life;
		}
		void setlife(int newlife) {
			life = newlife;
		}
	private:
		char row = '@';
		int column = 0;
		int life = 10;
		char mobType = 'm';
};
class Move {
	public:
		char row = '@';
		int column = 0;
};
