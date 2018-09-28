
class Mob {
	//might include move class as member
	private:
		int mob_location = 0;
		int life = 100;
		string name;
		string dialogue;
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
		string get_name() {
			return name;
		}
		string get_dialogue() {
			return dialogue;
		}
		Mob() {
			life = 100;
			mob_location = -1;
			name = "Empty";
			dialogue = "Empty";
		}
		Mob(int location, string newName, string newDialogue) {
			life = 100;
			mob_location = location;
			name = newName;
			dialogue = newDialogue;
		}
//		void move() {
//			vector<int> coord = get_coordinate(mob_location);
//			int new_x = x + rand()%3 -1;
//			int new_y = y + rand()%3 -1;
//		}
};
class Move {
	public:
		char row = '@';
		int column = 0;
};
