#include "bruteForce.hpp"

/***************************************************************
  Student Name: Ari Le
  File Name: bruteForce.cpp
  Assignment number: 5

  A class to do part one of the project.
***************************************************************/

//Constructor with a file name parameter
BruteForce::BruteForce(string fileName)
{
    inFS.open(fileName);
    if(!inFS.is_open())
    {
        cout << "Could not open file " + fileName << endl;
        exit(1);
    }
}

//Destructor
BruteForce::~BruteForce()
{
    for(int i = 0; i < (getLength1() + 1); ++i)
        delete [] c[i];
    delete [] c;
}

//A method to read the opened file
void BruteForce::readFile() 
{
    inFS >> str1;
    inFS >> str2;
}

//A method to calculate the size of the two strings
void BruteForce::calLengthOfTwoStrings()
{
    length1 = str1.size();
    length2 = str2.size();
}

//A method to construct 2D c array
void BruteForce::constructC()
{
    int m = getLength1();
    int n = getLength2();
    c = new int * [m + 1];
    for(int r = 0; r <= m; r++)
        c[r] = new int[n + 1];
    for(int i = 1; i <= m; i++)
        c[i][0] = 0;
    for(int j = 0; j <= n; j++)
        c[0][j] = 0;

    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(str1[i - 1] == str2[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
            {
                if(c[i - 1][j] >= c[i][j - 1])
                    c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }
        }
    }
}

//A method to find the longest common subsequence (LCS)
void BruteForce::printLCS(int i, int j)
{
    if(i == 0 || j == 0)
        return;   

    if(str1[i - 1] == str2[j - 1])
    {
        printLCS(i - 1, j - 1);
        cout << str1[i - 1];
    } 
    else if (c[i - 1][j] >= c[i][j - 1])
        printLCS(i - 1, j);  
    else
        printLCS(i, j - 1);  
}

//First string's getter
string BruteForce::getStr1()
{
    return str1;
}

//Second string's getter
string BruteForce::getStr2()
{
    return str2;
}

//Length1's getter
int BruteForce::getLength1()
{
    return length1;
}

//Length2's getter
int BruteForce::getLength2()
{
    return length2;
}