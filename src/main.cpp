#include "bruteForce.hpp"
#include "similarityMeasure.hpp"
using namespace std;

/***************************************************************
  Student Name: Ari Le
  File Name: main.cpp
  Assignment number: 5

  Main method
***************************************************************/

void runProject5();

int main() 
{
    runProject5();
    return 0;
}

void runProject5()
{
    cout << "\n--------PART ONE---------\n" << endl;
    BruteForce bf("twoStrings.txt");
    bf.readFile();
    bf.calLengthOfTwoStrings();
    cout << "String 1: \n" << bf.getStr1() << endl;
    cout << "String 2: \n" << bf.getStr2() << endl;
    bf.constructC();
    cout << "LCS: \n";
    bf.printLCS(bf.getLength1(), bf.getLength2());
    cout << endl;

    cout << "\n--------PART TWO---------\n" << endl;
    SimilarityMeasure sm;
    sm.computeLength();
    sm.directAccess();
}
