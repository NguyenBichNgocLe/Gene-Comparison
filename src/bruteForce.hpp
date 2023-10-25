#ifndef BRUTE_FORCE_HPP_
#define BRUTE_FORCE_HPP_
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

/***************************************************************
  Student Name: Ari Le
  File Name: bruteForce.hpp
  Assignment number: 5

  A class to do part one of the project.
***************************************************************/

class BruteForce
{
    private:
        string str1;
        string str2;
        ifstream inFS;
        int length1;
        int length2;
        int ** c;
    public:
        BruteForce(string fileName);
        ~BruteForce();
        void readFile();
        void calLengthOfTwoStrings();
        void constructC();
        void printLCS(int i, int j);
        string getStr1();
        string getStr2();
        int getLength1();
        int getLength2();
};

#endif