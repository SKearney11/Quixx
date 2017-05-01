//
//  Player.cpp
//  Quixx
//
//  Created by Sean Kearney on 01/05/2017.
//  Copyright © 2017 Sean Kearney. All rights reserved.
//

#include "Player.hpp"
#include <vector>
using namespace std;

Player::Player()
{
    for(int i = 2; i < 13; ++i)
    {
        red.push_back(i);
        yellow.push_back(i);
    }
    for(int i = 12; i > 1; --i)
    {
        green.push_back(i);
        blue.push_back(i);
    }
    
    forfeits = 0;
}

Player::~Player(){
}

void makeMove(Player& p, vector<int> diceResults, int number)
{
    
    
    //todo Switch statement for what color row to edit.
    //todo make if statement for colordice+whitedice
    //todo implement rule to reject move if it is to the left a previus picked number (quixx rule)
    
    //bool validMove = true;
    if(diceResults[0] + diceResults[1] == number && p.red[number - 2] != 0)
    {
        p.red[number -2] = 0;
    }
}
