#include "similarityMeasure.hpp"

/***************************************************************
  Student Name: Ari Le
  File Name: similarityMeasure.cpp
  Assignment number: 5

  A class to do part two of the project.
***************************************************************/

//A method to compute the length of each lines in the file
void SimilarityMeasure::computeLength()
{
    inFS.open("multiStrings.txt");
    if(!inFS.is_open())
    {
        cout << "Could not open multiStrings.txt!" << endl;
        exit(1);
    }
    char line[LINELEN];
    positions[0] = 0;

    while(inFS.getline(line, LINELEN))
    {
        positions[totStrings] = strlen(line) + 1;
        totStrings++;
        line[strlen(line)] = '\0';
    }
    inFS.close();
}

//A method to compute the LCS length of the two provided character arrays
int SimilarityMeasure::computeLCSLength(char str1[], char str2[])
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    int * arr1 = new int[length2 + 1];
    int * arr2 = new int[length2 + 1];

    for(int i = 0; i < length2 + 1; i++)
        arr1[i] = 0;
    arr2[0] = 0;

    for(int i = 1; i < length1 + 1; i++)
    {
        if(i > 1)
            swap(arr1, arr2);
        for(int j = 1; j < length2 + 1; j++)
        {
            if(str1[i - 1] == str2[j - 1])
                arr2[j] = arr1[j - 1] + 1;   
            else
            {
                if (arr1[j] >= arr2[j - 1])
                    arr2[j] = arr1[j];
                else
                    arr2[j] = arr2[j - 1];  
            }
        }
    }
    delete [] arr1;
    delete [] arr2;
    return arr2[length2];
}

//A method to calculate the percentage of the shorter string compared to the longer string
int SimilarityMeasure::percentShorterStrToLongerStr(char str1[], char str2[])
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    
    int percentLength = 0;

    if(length1 <= length2)
        percentLength = (length1 * 100) / length2;   
    else
        percentLength = (length2 * 100) / length1; 

    return percentLength;  
}

//A method to calculate the percentage of the LCS string compared to the shorter string
int SimilarityMeasure::percentLCSToShorterStr(int lcsLength, char str1[], char str2[])
{
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    int percentLength = 0;

    if(length1 <= length2)
        percentLength = (lcsLength * 100) / length1;
    else
        percentLength = (lcsLength * 100) / length2;

    return percentLength;
}

//A method to determine the level of similarity
string SimilarityMeasure::determineSimilarity(int percentStr, int percentLCS)
{
    string similarityLevel = "";

    if(percentStr >= 90 && percentLCS >= 90)
        similarityLevel = "H";
    else if(percentStr >= 80 && percentLCS >= 80)
        similarityLevel = "M";
    else if(percentStr >= 60 && percentLCS >= 50)
        similarityLevel = "L";
    else
        similarityLevel = "D";
    
    return similarityLevel;
}

//A method to direct access the file and do the calculating
void SimilarityMeasure::directAccess()
{
    int i, j, currentPos = positions[0];
    char line1[LINELEN];
    char line2[LINELEN];
    inFS.open("multiStrings.txt");
    if(!inFS.is_open())
    {
        cout << "Could not open file multiStrings.txt!" << endl;
        exit(1);
    }
    cout << "\t01\t02\t03\t04\t05\t06\t07\t08\t\n";

    inFS.seekg(currentPos);
    for(i = 1; i < totStrings - 1; i++)
    {
        cout << "0" << i << "\t";
        inFS.getline(line1, LINELEN);
        line1[strlen(line1)] = '\0';
        for(int v = i; v > 0; v--)
            cout << "-\t";
        for(j = i + 1; j < totStrings; j++)
        {
            inFS.getline(line2, LINELEN);
            line2[strlen(line2)] = '\0';
            //int lcsLength = computeLCSLength(line1, line2);
            int percentLength = percentShorterStrToLongerStr(line1, line2);
            int percentLCS = percentLCSToShorterStr(computeLCSLength(line1, line2), line1, line2);
            cout << determineSimilarity(percentLength, percentLCS) << "\t";
        }
        cout << endl;
        currentPos += positions[i];
        inFS.seekg(currentPos);
    }
}