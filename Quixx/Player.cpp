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
    bool validMove = false;
    if(diceResults[0] + diceResults[2] == number || diceResults[1] + diceResults[2] == number || diceResults[0] + diceResults[3] == number || diceResults[1] + diceResults[3] == number || diceResults[0] + diceResults[4] == number || diceResults[1] + diceResults[4] == number || diceResults[0] + diceResults[5] == number || diceResults[1] + diceResults[5] == number)
    {
        if(color == 'r' && p.red[number - 2] != 0){
            if(canPlaceMove(p.red, number) == true)
            {
                p.red[number -2] = 0;
                validMove = true;
            }
        }
        if(color == 'y' && p.yellow[number - 2] != 0){
            if(canPlaceMove(p.yellow, number) == true)
            {
                p.yellow[number -2] = 0;
                validMove = true;
            }
        }
        if(color == 'g' && p.green[number - 2] != 0){
            if(canPlaceMove(p.green, number) == true)
            {
                p.green[number -2] = 0;
                validMove = true;
            }
        }
        if(color == 'b' && p.blue[number - 2] != 0){
            if(canPlaceMove(p.blue, number)==true)
            {
                p.blue[number -2] = 0;
                validMove = true;
            }
        }
    }
    if (validMove == false){
        p.forfeits ++;
    }
}

void makeWhiteMove(Player& p, vector<int> diceResults, int number, char color){
    bool validMove = false;
    if(diceResults[0] + diceResults[1] == number)
    {
        if(color == 'r' && p.red[number - 2] != 0){
            if(canPlaceMove(p.red, number) == true)
            {
                p.red[number -2] = 0;
                validMove = true;
            }
        }
        if(color == 'y' && p.yellow[number - 2] != 0){
            if(canPlaceMove(p.yellow, number) == true)
            {
                p.yellow[number -2] = 0;
                validMove = true;
            }
        }
        if(color == 'g' && p.green[number - 2] != 0){
            if(canPlaceMove(p.green, number) == true)
            {
                p.green[number -2] = 0;
                validMove = true;
            }
        }
        if(color == 'b' && p.blue[number - 2] != 0){
            if(canPlaceMove(p.blue, number)==true)
            {
                p.blue[number -2] = 0;
                validMove = true;
            }
        }
    }
    if (validMove == false){
        p.forfeits ++;
    }
}

int calculateScore(Player p){
    int rCounter = 0, rScore = 0;
    int yCounter = 0, yScore = 0;
    int gCounter = 0, gScore = 0;
    int bCounter = 0, bScore = 0;
    vector<int> scores = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78};
    
    for(int i = 0; i < p.red.size(); i++)
    {
        if(p.red[i] == 0){
            rCounter ++;
        }
        if(p.yellow[i] == 0)
        {
            yCounter ++;
        }
        if(p.green[i] == 0){
            gCounter ++;
        }
        if(p.blue[i] == 0)
        {
            bCounter ++;
        }
    }
    if(rCounter > 0){
        rScore = scores[rCounter -1];
    }
    if(yCounter > 0){
        yScore = scores[yCounter -1];
    }
    if(gCounter > 0){
        gScore = scores[gCounter -1];
    }
    if(bCounter > 0){
        bScore = scores[bCounter -1];
    }

    int playerScore = rScore + yScore + gScore + bScore;
    return playerScore;
}

bool canPlaceMove(vector<int> vec, int number){
    for(int i = (number -1); i < vec.size(); i++){
        if(vec[i] == 0){
            return false;
        }
    }
    return true;
}
