#include <iostream>
#include <fstream>
#include <string>
#include "MarkovWord.h"
#include "MarkovGenerator.h"

using namespace std;

const string FILE_NAME = "fish.txt";//change your file here

int main(){

    MarkovGenerator testGenerator;
    ifstream file;
    file.open(FILE_NAME);
    if(file.is_open()){
        testGenerator.readFile(file);
    }
    else{
        cout << "Couldn't open file!" << endl;
        return 0;
    }
    
    file.close();
    testGenerator.printArray();
    //cout << testGenerator.generateText(500) << endl;
    return 0;
}