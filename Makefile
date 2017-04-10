a.out: main.cc splash.h constants.h map.h mobAI.h startup.h
	g++ -std=c++11 main.cc -lncurses
clean:
	rm a.out
