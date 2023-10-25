#ifndef SIMILARITY_MEASURE_HPP_
#define SIMILARITY_MEASURE_HPP_
#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
using namespace std;

/***************************************************************
  Student Name: Ari Le
  File Name: similarityMeasure.hpp
  Assignment number: 5

  A class to do part two of the project.
***************************************************************/

const int POSLEN = 20;
const int LINELEN = 120;

class SimilarityMeasure
{
    private:
        ifstream inFS;
        int totStrings = 0;
        int positions[POSLEN];
    public:
        void computeLength();
        int computeLCSLength(char str1[], char str2[]);
        int percentShorterStrToLongerStr(char str1[], char str2[]);
        int percentLCSToShorterStr(int lcsLength, char str1[], char str2[]);
        string determineSimilarity(int percentStr, int percentLCS);
        void directAccess();
};

#endif