.PHONY = all clean bin

all : bin

bin : shsup

clean:
	rm -rf shsup

shsup: shortest_superstring.cc
	g++ -std=c++11 -Wall -O0 shortest_superstring.cc -o shsup

