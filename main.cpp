#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "FileOutput.h"
#include <bits/stdc++.h> 

using namespace std;

#define NUMVALUES 26

vector<string> validChars = {
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
};


void nextRow(list<string>* theList){
  int startSize = theList->size();
  string workingString;
  for (int i = 0; i < startSize; i++) {
    auto it = theList->begin();
    advance(it, i);
    workingString = *it;
    *it = workingString + validChars[0];
//    cout << "workingstring: " << workingString << "\n";
    for(int j = 1; j < NUMVALUES; j++){
      theList->push_back(workingString + validChars[j]);
    }
  }
}

void nextRowFile(FileOutput* file){
  int startSize = file->getSize();
  string workingString;
  for (int i = 0; i < startSize; i++) {
    workingString = file->readLine(i);
    file->changeLine(i, workingString + validChars[0]);
    
    for(int j = 1; j < NUMVALUES; j++){
      file->addLine(workingString + validChars[j]);
    }
  }
}

void permuteForCapitals(string input) 
{ 
    int n = input.length(); 
  
    // Number of permutations is 2^n 
    int max = 1 << n; 
  
    // Converting string to lower case 
        transform(input.begin(), input.end(), input.begin(),  
                                                ::tolower); 
    // Using all subsequences and permuting them 
    for (int i = 0; i < max; i++) { 
          
        // If j-th bit is set, we convert it to upper case 
        string combination = input; 
        for (int j = 0; j < n; j++)  
            if (((i >> j) & 1) == 1) 
                combination[j] = toupper(input.at(j));      
  
        // Printing current combination 
        cout << combination << " "; //check here
    } 
} 


int main() {
  int wordLen = 5;

  FileOutput fileResults("Results.txt");
  //for (int i = 0; i < NUMVALUES; i++) {
  for (int i = 0; i < 1; i++) {
    fileResults.wipeFile();
  //for (int i = 0; i < i+1; i++) {
    for (int j = 0; j < NUMVALUES; j++) {
      fileResults.addLine(validChars[i] + validChars[j]);
    }

    for(int j = 0; j < wordLen-2; j++) {
      nextRowFile(&fileResults);
    }
  


    //test here
  }
  






/*
  int wordLen = 5;
  for (int i = 0; i < NUMVALUES; i++) {
    list<string> theList;
    for (int j = 0; j < NUMVALUES; j++) {
      theList.push_back(validChars[i] + validChars[j]);
    }

    for(int j = 0; j < wordLen-2; j++) {
      nextRow(&theList);
    }


    for(auto i : theList){
      cout << i << " ";
    }
    delete (&theList);
  }

*/

//use FileOutput.h

//FileOutput testfile("test.txt"); //object of FileOutput
//testfile.addLine("five");
//testfile.changeLine(1, "hi"); //this does run
//testfile.changeLine(3, "yo"); //this doesn't run

//cout << testfile.readLine(3);
//cout << testfile.readLine(4);
//testfile.renameFile("renamed.txt");
//testfile.changeLine(3, "it worked");
}