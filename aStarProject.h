#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class aStarProject{
private:
    int xValue = 0;
    int yValue = 0;

    //pointer to the dynamic array
    int** arrToSearch = nullptr;

    pair<int, int> coordHelper(string input);

    string bool_caster(bool boolean);
public:
    //builds the dynamically allocated array
    aStarProject(int x, int y);

    //destroys the dynamically allocated array
    ~aStarProject();

    //populates the coordinate plane with boolean values. PS:might want this to take a text file to make building less painful
    bool build();

    //returns a string of the shortest path between start and end
    string search(string start, string end);

    //prints out to terminal the coordinate map created in arrToSearch
    void showMap();
};
