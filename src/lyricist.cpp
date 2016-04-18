//============================================================================
// Name        : Lyricist.cpp
// Author      : Alessio Saltarin
// Version     :
// Copyright   : (C) Alessio Saltarin 2016
// Description : Lyricist
//============================================================================

#include <iostream>
#include <fstream>

#include "lyricist.h"

Lyricist::Lyricist()
{
    std::srand((unsigned int) std::time(0));
    this->wordsContainer = new std::vector<std::string>();
}

Lyricist::~Lyricist()
{
    delete wordsContainer;
}

const std::string& Lyricist::getRandomWord() const
{
    ulong nrWords = this->wordsContainer->size();
    ulong index = rand() % nrWords + 1;
    return this->wordsContainer->at(index);
}

ulong Lyricist::loadWords()
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
