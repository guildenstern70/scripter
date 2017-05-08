//
// Created by Alessio Saltarin on 18/04/16.
//

#include "director.h"

#include <iostream>
#include <thread>

Director::Director()
{
    this->lyrics = new Lyricist();
    ulong wordsNum = this->lyrics->loadWords();
    std::cout << "Loaded " << wordsNum << " words." << std::endl << std::endl;
}

Director::~Director()
{
    delete this->lyrics;
}

void Director::makePause(PauseKind pauseKind)
{
    int msecs = rand() % MAX_WAIT_MSECS + MIN_WAIT_MSECS;

    if (pauseKind==PauseKind::SMALL)
    {
        msecs = MIN_WAIT_MSECS;
    }
    else if (pauseKind==PauseKind::LONG)
    {
        msecs = MAX_WAIT_MSECS;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(msecs));
}

void Director::printPhrase()
{
    int phraseSize = rand() % MAX_PHRASE_WORDS + 4;
    std::string ss = "";

    for (int j=0; j<phraseSize; j++)
    {
        std::string rndString = this->lyrics->getRandomWord();
        if (j==0) rndString[0] = static_cast <char>(toupper(rndString[0]));
        std::cout << " ";
        std::cout << rndString;
        if (j != phraseSize - 1)
        {
            this->addPunctuation();
            this->makePause(PauseKind::SMALL);
        }
        std::cout << std::flush;
    }

    this->addFinalPunctuation();

    int kindOfPause = rand() % 6;

    if (kindOfPause % 2 == 0)
    {
        this->makePause(PauseKind::SMALL);
    }
    else if (kindOfPause == 3)
    {
        this->makePause(PauseKind::LONG);
    }
    else
    {
        this->makePause(PauseKind::RANDOM);
    }

}

void Director::addFinalPunctuation()
{
    int punctuationIdx = rand() % 5;

    if (punctuationIdx == 0)
    {
        std::cout << "..." << std::endl;
    }
    else if (punctuationIdx == 1)
    {
        std::cout << "?" << std::endl;
    }
    else
    {
        std::cout << "." << std::endl;
    }

}

void Director::addPunctuation()
{
    int punctuationIdx = rand() % 20;

    if (punctuationIdx <= 3)
    {
        std::cout << ",";
    }
    else if (punctuationIdx == 4)
    {
        std::cout << ";";
    }
    else if (punctuationIdx == 5)
    {
        std::cout << " - ";
    }
    // else do nothing
}







