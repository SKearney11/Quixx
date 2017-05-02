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
    score = 0;
}

Player::~Player(){
}

void makeColorMove(Player& p, vector<int> diceResults, int number, char color)
{
    if(diceResults[0] + diceResults[2] == number || diceResults[1] + diceResults[2] == number || diceResults[0] + diceResults[3] == number || diceResults[1] + diceResults[3] == number || diceResults[0] + diceResults[4] == number || diceResults[1] + diceResults[4] == number || diceResults[0] + diceResults[5] == number || diceResults[1] + diceResults[5] == number)
    {
        if(color == 'r' && p.red[number - 2] != 0){
            p.red[number -2] = 0;
            p.score += 5;
        }else{
            p.forfeits ++;
        }
        if(color == 'y' && p.yellow[number - 2] != 0){
            p.yellow[number -2] = 0;
            p.score += 5;
        }else{
            p.forfeits ++;
        }
        if(color == 'g' && p.green[number - 2] != 0){
            p.green[number -2] = 0;
            p.score += 5;
        }else{
            p.forfeits ++;
        }
        if(color == 'b' && p.blue[number - 2] != 0){
            p.blue[number -2] = 0;
            p.score += 5;
        }else{
            p.forfeits ++;
        }
    }
}

void makeWhiteMove(Player& p, vector<int> diceResults, int number, char color){
    if(diceResults[0] + diceResults[1] == number)
    {
        if(color == 'r' && p.red[number - 2] != 0){
            p.red[number -2] = 0;
        }
        if(color == 'y' && p.yellow[number - 2] != 0){
            p.yellow[number -2] = 0;
        }
        if(color == 'g' && p.green[number - 2] != 0){
            p.green[number -2] = 0;
        }
        if(color == 'b' && p.blue[number - 2] != 0){
            p.blue[number -2] = 0;
        }
    }
}
