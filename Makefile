.PHONY = all clean bin

all : bin

bin : shsup

clean:
	rm -rf shsup

shsup: shortest_superstring.cc
	clang++ -std=c++11 -pg -Wall -O3 -fopenmp shortest_superstring.cc -o shsup

shsupparallel: shortest_superstring_parallel.cc
	clang++ -std=c++11 -pg -Wall -O3 -fopenmp shortest_superstring_parallel.cc -o shsupparallel

shsupparallelblock: shortest_superstring_parallel_block.cc
	clang++ -std=c++11 -pg -Wall -O3 -fopenmp shortest_superstring_parallel_block.cc -o shsupparallelblock