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

pair<int, int> aStarProject::coordHelper(string input){ //DONE
    //point of this method is to format each coordinate as a string to return a pair of ints

    //EDGECASE: (    x    ,    y   ) <- need to account for this
    //Also need to account for this (x   , y   z  ). (Should return an error)
    //Also need to account for this (x, y, z). (Should return an error)
    pair <int, int> toRet;
    string subStr = "";
    //counter for how many numbers we have
    int nomNoms = 1;

    //if the last char in input is not a parenthesis
    if(input[input.size()-1] != ')' || input[0] != '('){
        cout<<"ERROR: EXCESSIVE NUMBERS FOUND"<<endl;
        exit(0);
    }
    //we want check everything from the first parenthesis, stopping once we find
    //the end parenthesis
    for(char & c : input){
        //CONDITIONS TO ACCOUNT FOR:
        // 1) we find multiple commas
        //      SOLUTION: have a counter that counts the number of resets. If exceed 1, then return error
        // 2) we have multiple numbers deliminated by spaces
        //      SOLUTION: we increment counter if after the 2nd number there are spaces (also solves the 1st edge casse).
        //                If we find another number but counter is greater than 2, return error
        // 3) we find letters while parsing
        //      SOLUTION: we return an error if we find a letter than isnt a comma or parenthesis

        // WE ALSO WANT TO SKIP OVER WHITESPACE

        if(isdigit(c)){
            if(nomNoms < 3){
                subStr+=c;
            }
            else{
               cout<<"ERROR: EXCESSIVE NUMBERS FOUND"<<endl;
            }
        }
        else if( c != '(' && !isdigit(c) && !isspace(c)){
            //if we find a character that isnt a number or space
            if(c == ',' && nomNoms < 2){
                //if we find a comma, incremement counter and put subStr into toRet.first
                //if we already found a counter, we should also return an error
                toRet.first = stoi(subStr);
                subStr = "";
                nomNoms++;
            }
            else if(c == ')'){
                //when we find the end parenthesis
                toRet.second = stoi(subStr);
                subStr = "";
                nomNoms++;
                //we shouldnt need this break here but putting in here for
                //redundancy
                break;
            }
            else{
                //if not a comma
               cout<<"ERROR: IMPROPER COORDINATE FORMATTING"<<endl;
               exit(0);
            }
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

    //pair <int, int> test = coordHelper("(751,  87)");
    //cout<<test.first<<" "<<test.second<<endl;
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
