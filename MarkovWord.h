#pragma once
#include <iostream>
#include <string>

class MarkovWord{
private:
  std::string word;
  std::string *successors;
  int itemUsed;
  int arraySize;

public:
  //constructor
  MarkovWord();
  MarkovWord(std::string word);

  //accessors
  std::string *getSuccessors(){ return successors; };
  std::string getWord(){ return word;};
  int getItemUsed() {return itemUsed;};

  //mutators
  void resizeArray();
  void addSuccessors(std::string word);
  void printSuccessors();
};