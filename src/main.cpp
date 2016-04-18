//============================================================================
// Name        : main.cpp
// Author      : Alessio Saltarin
// Version     :
// Copyright   : (C) Alessio Saltarin 2016
// Description : Lyricist
//============================================================================

#include <iostream>
#include "director.h"

using namespace std;

int main()
{
    cout << "Lyricist v.0.2" << endl;
    auto director = std::make_shared<Director>();

    cout << endl << "Press 'CTRL+C to exit" << endl;
    cout << endl;

    while (true)
    {
        director->printPhrase();
    }

    return 0;
}
