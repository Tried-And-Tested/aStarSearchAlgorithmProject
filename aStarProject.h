#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;

class aStarProject{
private:
    int xVal = 0;
    int yVal = 0;

    //pointer to the dynamic array
    int** arrToSearch = nullptr;
public:
    //builds the dynamically allocated array
    aStarProject(int x, int y);

    //destroys the dynamically allocated array
    ~aStarProject();

    //populates the coordinate plane with boolean values. PS:might want this to take a text file to make building less painful
    bool build();

    //returns a string of the shortest path between start and end
    string search(string start, string end);

}
