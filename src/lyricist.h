//============================================================================
// Name        : Lyricist.h
// Author      : Alessio Saltarin
// Version     :
// Copyright   : (C) Alessio Saltarin 2016
// Description : Lyricist
//============================================================================

#ifndef LYRICIST_H
#define LYRICIST_H

#include <string>
#include <vector>
#include <random>

typedef unsigned long ulong;

class Lyricist
{
public:
	Lyricist();
	ulong loadWords();
	const std::string& getRandomWord() const;
	virtual ~Lyricist();
private:
    std::vector<std::string>* wordsContainer;
};

#endif /* LYRICIST_H */
