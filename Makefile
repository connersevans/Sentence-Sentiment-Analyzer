all: main

main:
	c++ -std=c++11 Main.cpp Analyzer.cpp -I ./boost_1_60_0


clean: 
	rm -rf main