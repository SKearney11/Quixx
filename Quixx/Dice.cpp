//
//  Dice.cpp
//  Quixx
//
//  Created by Sean Kearney on 01/05/2017.
//  Copyright © 2017 Sean Kearney. All rights reserved.
//

#include "Dice.hpp"
#include <iostream>
#include <vector>
using namespace std;

Dice::Dice(){
    
}

vector<int> rollDice(){
    srand(static_cast<int>(time(0)));
    vector<int> result;
    for(int i = 0; i < 6; i++)
    {
        int randomNumber = rand();
        int number = ((randomNumber % 6) + 1);
        result.push_back(number);
    }
    return result;
}

