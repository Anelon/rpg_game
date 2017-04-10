a.out: main.cc constants.h map.h mobAI.h startup.h
	g++ -std=c++11 main.cc -lncurses
clean:
	rm a.out
