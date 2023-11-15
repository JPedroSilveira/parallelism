.PHONY = all clean bin

all : bin

bin : shsup

clean:
	rm -rf shsup

shsup: shortest_superstring.cc
	g++ -std=c++11 -Wall -O3 -fopenmp shortest_superstring.cc -o shsup

shsupopt: shortest_superstring_opt.cc
	g++ -std=c++11 -Wall -O3 -fopenmp shortest_superstring_opt.cc -o shsupopt

shsupparallel: shortest_superstring_parallel.cc
	g++ -std=c++11 -Wall -O3 -fopenmp shortest_superstring_parallel.cc -o shsupparallel

shsupparallelblock: shortest_superstring_parallel_block.cc
	g++ -std=c++11 -Wall -O3 -fopenmp shortest_superstring_parallel_block.cc -o shsupparallelblock
