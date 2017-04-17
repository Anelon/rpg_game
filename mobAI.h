class Mob {
	//might include move class as member
	public:
		int get_location() {
			return mob_location;
		}
		void set_location(int newlocation) {
			mob_location = newlocation;
		}
		int getlife() {
			return life;
		}
		void setlife(int newlife) {
			life = newlife;
		}
	private:
		int mob_location = 0;
		int life = 100;
		char mobType = 'm';
};
class Move {
	public:
		char row = '@';
		int column = 0;
};
