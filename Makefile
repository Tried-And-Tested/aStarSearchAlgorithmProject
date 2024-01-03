# Specifiy the target
all: aShiningStar

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable

run: aShiningStar
	./aShiningStar

aShiningStar: aStarProject.o execute.o
	g++ aStarProject.o execute.o -o aShiningStar

gdb: aShiningStar
	gdb aShiningStar

# Specify how the object files should be created from source files
aStarProject.o: aStarProject.cpp
	g++ -c -g aStarProject.cpp

execute.o: execute.cpp
	g++ -c -g execute.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o aShiningStar
