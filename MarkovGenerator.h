#pragma once 
#include <iostream>
#include "MarkovWord.h"
#include <string>

class MarkovGenerator
{
 private:
  MarkovWord *foundWords;
  int arraySize;
  int itemUsed;

 public:
  //constructor
  MarkovGenerator();

  //accessors
  int getArraySize(){return arraySize;}
  int getItemUsed(){return itemUsed;}
  MarkovWord *getFoundWords(){ return foundWords;}
  void printArray();
  bool findWord(std::string word);
  int getMarkovWord(std::string word);

  //mutators
  MarkovWord addWord(std::string word);
  void resizeArray();
  std::string generateText(int numberOfWords);
  void readFile(std::ifstream &file);
};