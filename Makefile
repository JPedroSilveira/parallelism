.PHONY = all clean bin

all : bin

bin : shsup

clean:
	rm -rf shsup

shsup: shortest_superstring.cc
	g++ -std=c++11 -pg -Wall -O3 shortest_superstring.cc -o shsup

shsupparallel_mac: shortest_superstring.cc
	clang++ -std=c++11 -Wall -O3 -fopenmp shortest_superstring_parallel.cc -o shsup_parallel

shsupparallel_lin: shortest_superstring.cc
	g++ -std=c++11 -pg -Wall -O3 -fopenmp shortest_superstring_parallel.cc -o shsup_parallel