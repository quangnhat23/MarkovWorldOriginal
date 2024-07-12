#include <iostream>
#include "MarkovWord.h"
#include <string>

const int ARRAY_SIZE = 8;

MarkovWord::MarkovWord()
{
  successors = new std::string[ARRAY_SIZE];
  arraySize = ARRAY_SIZE;
  itemUsed = 0;
}

MarkovWord::MarkovWord(std::string word)
{
 this->word = word;
 successors = new std::string[ARRAY_SIZE];
 arraySize = ARRAY_SIZE;
 itemUsed = 0;
}

void MarkovWord::resizeArray()
{
  arraySize *=2;
  std::string *temporarryArray = new std::string[arraySize];
  for ( int i = 0; i < itemUsed; i++){
    temporarryArray[i] = successors[i];
  }
  delete[] successors;
  successors = temporarryArray;
}

void MarkovWord::addSuccessors(std::string word)
{
 if(arraySize == itemUsed)
 {
  resizeArray();
 }
 successors[itemUsed]= word;
 itemUsed++;
}

void MarkovWord::printSuccessors()
{
  for(int i = 0; i < itemUsed; i++)
  {
    std::cout <<successors[i]<<std::endl;
  }
}