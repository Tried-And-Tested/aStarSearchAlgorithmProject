#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "aStarProject.h"

using namespace std;

//PROBLEM: How to represent the coordinate plane to travese
//SOLUTION: Create a 2d array of boolean values to represent a valid and invalid space. Doing so will
//          allow constant time access to each coordinate

//PROBLEM: arrays are statically defined
//SOLUTION: dynamically allocate each array and the array within the array

aStarProject::aStarProject(int x, int y){
    xValue = x;
    yValue = y;

    arrToSearch = new int *[yValue];
    for(int i=0;i<yValue;i++){
        arrToSearch[i] = new int[xValue];
    }
}

aStarProject::~aStarProject(){
    //first delete all of the arrays within arrToSearch
    for(int i=0; i<yValue; i++)
        delete[] arrToSearch[i];
    //then delete arrToSearch
    delete[] arrToSearch;
}

bool aStarProject::build(){
    //for now, plan is to have this method take a text file of bool vals to populate the coordinate plane
    //we need a check if there are not enough bool values to completely populate the coordinate plane
    return false;
}

string aStarProject::search(string start, string end){
    //if the start and end coords are valid coordinates (IE exist and have val true)
    //if(){
        //return "start and end coordinates are not valid coordinates";
    //}
    //here if start and end coords are valid

    //we want to use a priority queue in a similar fashion to Djistraks single shortest path algorithm
    //where we pop the current smallest route and add the step with the smallest heuristic + totDist
    //we will calculate the heuristic using pythagorean theorem to get the shortest(direct) path to the end

    return "false";
}

void aStarProject::showMap(){
    return;
}
