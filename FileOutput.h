#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class FileOutput {
  public:
    FileOutput(string NameOfFileIn);
    ~FileOutput() = default;

    void changeLine(int line, string newLine);
    void addLine(string newLine);
    string readLine(int line);
    void wipeFile();
    void print();

    void setSize(int newSize);
    int getSize();
  
  private:
    void renameFile(string newName);

    string NameOfFile;
    int size;
};


FileOutput::FileOutput(string NameOfFileIn){
  this->NameOfFile = NameOfFileIn;
  this->size = 0;
}


void FileOutput::changeLine(int line, string newLine){
  ofstream newFile;
  ifstream FileStreamIn;
  newFile.open("temp.txt", ofstream::out | ofstream::trunc);
  newFile.close();
  renameFile("temp.txt");
  newFile.open(this->NameOfFile);
  FileStreamIn.open("temp.txt", fstream::app);
  string tempLine;
  int lineCounter = 0;
  while(getline(FileStreamIn, tempLine)){
    if(lineCounter == line){
      newFile << newLine << '\n';
      lineCounter++;
    }
    else{
      newFile << tempLine << '\n';
      lineCounter++;
    }
  }
}


void FileOutput::addLine(string newLine){
  ofstream FileStreamOut;
  FileStreamOut.open(NameOfFile, fstream::app);
  FileStreamOut << newLine << '\n';
  FileStreamOut.close();
  this->size = this->size + 1;
}

string FileOutput::readLine(int line){
  string tempLine;
  ifstream tempFileStream;
  tempFileStream.open(NameOfFile);
  if(tempFileStream.is_open()){
    //cout << "file opened successfully.\n";
  }
  
  for (int i = -1; i < line; i++) {
    getline(tempFileStream, tempLine);
  }
  return tempLine;

  tempFileStream.close();
}


void FileOutput::renameFile(string newName){
  rename(this->NameOfFile.c_str(), newName.c_str());
}

void FileOutput::print(){

}

void FileOutput::setSize(int newSize){
  this->size = newSize;
}

int FileOutput::getSize(){
  return this->size;
}

void FileOutput::wipeFile(){
  ofstream FileStreamOut;
  FileStreamOut.open(this->NameOfFile, ofstream::out | ofstream::trunc);
  FileStreamOut.close();
  this->size = 0;
}