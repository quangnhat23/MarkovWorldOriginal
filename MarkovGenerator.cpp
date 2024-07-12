#include <iostream>
#include "MarkovGenerator.h"
#include "MarkovWord.h"
#include <string>
#include <fstream>

const int ARRAY_SIZE = 512;

MarkovGenerator::MarkovGenerator()
{
  foundWords = new MarkovWord[ARRAY_SIZE];
  arraySize = ARRAY_SIZE;
  itemUsed = 0;
}

MarkovWord MarkovGenerator::addWord(std::string word)
{
  MarkovWord *addObject = new MarkovWord(word);
  foundWords[itemUsed] = *addObject;
  itemUsed++;
  return *addObject;
}

void MarkovGenerator::resizeArray()
{
  MarkovWord *temporarryArray = new MarkovWord[arraySize * 2];
  for(int i = 0; i < arraySize; i++){
    temporarryArray[i] = foundWords[i];
  }
  arraySize *=2;
  delete[] foundWords;
  foundWords = temporarryArray;
}

void MarkovGenerator::readFile(std::ifstream &file)
{
  bool cantRead = false;
  bool first = true;
  std::string nextWord;
  std::string firstWord;
  MarkovWord currentObject;
  while(!file.eof()){
    if(itemUsed == arraySize){
      resizeArray();
    }if(cantRead){
      cantRead = false;
    }else{
      file >>nextWord;
    }
    if(first){
      firstWord = nextWord;
      first = false;
    }
    if(!findWord(nextWord)){
      MarkovWord toAdd = MarkovWord(nextWord);
      foundWords[itemUsed] = toAdd;
      itemUsed++;
      if(file >>nextWord){
         foundWords[itemUsed - 1].addSuccessors(nextWord);
         cantRead = true;
      }
    }
  }
  foundWords[getMarkovWord(nextWord)].addSuccessors(firstWord);
}

bool MarkovGenerator::findWord(std::string word){
  for(int i = 0; i < itemUsed; i++){
      if(foundWords[i].getWord() == word){
        return true;
      }
  }
  return false;
}

int MarkovGenerator::getMarkovWord(std::string word){
    if(!findWord(word)){
        std::cout << "This word don't work with Markov table" <<std::endl;
    }
    for(int i = 0; i < itemUsed; i++){
        if(foundWords[i].getWord() == word){
            return i;
        }
    }
    exit(1);
}

std::string MarkovGenerator::generateText(int numberOfWords){
    std::string outputString = foundWords[0].getWord();
    int counter = 1;
    int successorCapacity;
    int randomSuccessorIndex;
    std::string randomWord;
    int markovIndex = 0; // started at first MarkovWord
    while(counter < numberOfWords){
        successorCapacity = foundWords[markovIndex].getItemUsed();
        randomSuccessorIndex = rand() % successorCapacity;
        randomWord = foundWords[markovIndex].getSuccessors()[randomSuccessorIndex];
        outputString  = outputString + " " + randomWord;
        markovIndex = getMarkovWord(randomWord);
        counter++;
    }
    return outputString;
}

void MarkovGenerator::printArray(){
    for(int i = 0; i < itemUsed; i++){
        std::cout << "Word: " << foundWords[i].getWord() << std::endl;
        std::cout << "Successors: " << std::endl;
        foundWords[i].printSuccessors();
    }
}