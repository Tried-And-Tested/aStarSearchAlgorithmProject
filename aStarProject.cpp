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
    int counter = 1;

    for(int i=0;i<input.size();i++){
        //Might want to use a switch statement if this gets dumb
        if( (isdigit(input[i])) && counter < 3){
            //in here if we found a number and counter has been incremented 0 or 1 time
            //add to subStr
            subStr.append(input[i]);
        }
        else if( input[i] == "," ){
            //in here if we found a comma
            //we want to account for the 3rd edge case here aswell
            if(counter == 1){
                //in here if we did not increment counter
                //we input what ever we have for subStr and put it into toRet. first
                toRet.first = atoi(subStr);
                //we reset subStr to get ready for the next number
                subStr = "";
                counter++;
            }
            else{
                cout<<"ERROR: Duplicate comma found"<<endl;
                exit(0);
            }
        }
        else if(isalpha(input[i]){
            //in here if we found a letter that is not a comma
            //we want to print an error here and exit
            cout<<"ERROR: Found letter while parsing"<<endl;
            exit(0);
        }
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
