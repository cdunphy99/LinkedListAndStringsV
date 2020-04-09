#include <iostream>
#include <list>
#include <vector>
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

int main() {
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
  }

  

}