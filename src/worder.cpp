//============================================================================
// Name        : Worder.cpp
// Author      : Alessio Saltarin
// Version     :
// Copyright   : (C) Alessio Saltarin 2016
// Description : Worder
//============================================================================

#include <iostream>
#include <fstream>
#include <memory>
#include <ctime>

#include "worder.h"

Worder::Worder()
{
    std::srand(std::time(0));
    this->wordsContainer = new std::vector<std::string>();
}

Worder::~Worder()
{
    delete wordsContainer;
}

const std::string& Worder::getRandomWord() const
{
    int nrWords = this->wordsContainer->size();
    int index = rand() % nrWords + 1;
    return this->wordsContainer->at(index);
}

int Worder::loadWords()
{
    std::cout << "Reading words..." << std::endl;
    std::string line;
    std::ifstream wordsFile("wordsEn.txt");
    if (wordsFile.is_open())
    {
        while ( getline (wordsFile,line) )
        {
            this->wordsContainer->push_back(line.substr(0, line.length() - 1));
        }
        wordsFile.close();
    }
    else std::cout << "Unable to open words file" << std::endl;

    std::cout << "Done." << std::endl;

    return this->wordsContainer->size();
}
