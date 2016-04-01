//============================================================================
// Name        : Worder.h
// Author      : Alessio Saltarin
// Version     :
// Copyright   : (C) Alessio Saltarin 2016
// Description : Worder
//============================================================================

#ifndef WORDER_H
#define WORDER_H

#include <string>
#include <vector>
#include <random>

class Worder
{
public:
	Worder();
	int loadWords();
	const std::string& getRandomWord() const;
	virtual ~Worder();
private:
    std::vector<std::string>* wordsContainer;
};

#endif /* WORDER_H */
