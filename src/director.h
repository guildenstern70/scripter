//
// Created by Alessio Saltarin on 18/04/16.
//

#ifndef SCRIPTER_DIRECTOR_H
#define SCRIPTER_DIRECTOR_H

#define MAX_PHRASE_WORDS 10
#define MAX_WAIT_MSECS 1800
#define MIN_WAIT_MSECS 100

#include "lyricist.h"

enum PauseKind
{
    SMALL,
    LONG,
    RANDOM
};


class Director
{
private:
    Lyricist* lyrics;
public:
    Director();
    virtual ~Director();
    void makePause(PauseKind pauseKind);
    void printPhrase();
    void addFinalPunctuation();
    void addPunctuation();

};


#endif //SCRIPTER_DIRECTOR_H
