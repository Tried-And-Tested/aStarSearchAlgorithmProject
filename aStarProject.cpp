#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "aStarProject.h"

using namespace std;

//PROBLEM: How to represent the coordinate plane to travese
//SOLUTION: Create a 2d array of boolean values to represent a valid and invalid space. Doing so will allow constant time access to each coordinate

//PROBLEM: arrays are statically defined
//SOLUTION: dynamically allocate each array and the array within the array

//TO FUTURE THOMAS: Might want to start creating a library of DSAs that I commonly use

aStarProject::aStarProject(int x, int y){
    xValue = x;
    yValue = y;

    arrToSearch = new int *[yValue];
    for(int i=0;i<yValue;i++){
        arrToSearch[i] = new int[xValue];
    }
}

pair<int, int> aStarProject::coordHelper(string input){
    //point of this method is to format each coordinate as a string to return a pair of ints

    //EDGECASE: (    x    ,    y   ) <- need to account for this
    //Also need to account for this (x   , y   z  ). (Should return an error)
    //Also need to account for this (x, y, z). (Should return an error)
    pair <int, int> toRet;
    string subStr = "";
    //counter for how many numbers we have
    int counter = 1;

    for(int i=0;i<input.size();i++){
        //CONDITIONS TO ACCOUNT FOR:
        // 1) we find multiple commas
        //      SOLUTION: have a counter that counts the number of resets. If exceed 1, then return error
        // 2) we have multiple numbers deliminated by spaces
        //      SOLUTION: we increment counter if after the 2nd number there are spaces (also solves the 1st edge casse). If we find another number but counter is greater than 2, return error
        // 3) we find letters while parsing
        //      SOLUTION: we return an error if we find a letter than isnt a comma or parenthesis

        // WE ALSO WANT TO SKIP OVER WHITESPACE

        //PROBLEM: Current iteration will NOT account for something like "(x,y " as an input
        if(isdigit(input[i]) && counter < 2){
            subStr.append(input[i]);
        }
        else if(input[i] == "," && counter == 1){
            //turn what ever was in subStr into digits
            toRet.first = atoi(subStr);
            //then reset and increment
            subStr == "";
            counter++;
        }
        else if(counter == 2 && ( isspace(input[i+1]) || input[i+1] == ")")) {
            toRet.second = atoi(subStr);
            subStr == "";
            break;
        }
    }
    return toRet;
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
