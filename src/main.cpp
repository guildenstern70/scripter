//============================================================================
// Name        : main.cpp
// Author      : Alessio Saltarin
// Version     :
// Copyright   : (C) Alessio Saltarin 2016
// Description : Worder
//============================================================================

#include <iostream>
#include <memory>
#include <sstream>

#include "worder.h"

using namespace std;

int main()
{
    cout << "Worder v.0.2" << endl;
    auto worder = std::make_shared<Worder>();
    int wordsNum = worder->loadWords();
    cout << "Loaded " << wordsNum << " words." << endl;
    cout << endl;

    string ss = ">";

    for (int j=0; j<100; j++)
    {
        ss += " ";
        ss += worder->getRandomWord();
    }

    cout << ss << endl;

    return 0;
}
