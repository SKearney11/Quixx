//
//  Player.hpp
//  Quixx
//
//  Created by Sean Kearney on 01/05/2017.
//  Copyright © 2017 Sean Kearney. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Player
{
public:
    Player();
    ~Player();
    vector<int> red;
    vector<int> yellow;
    vector<int> green;
    vector<int> blue;
    int forfeits;
};

void printBoard(Player& p);
void makeMove(Player& p, vector<int> diceResults, int input);
void askMove(Player& p1, vector<int> diceResults);
void printDice(vector<int> diceResults);

#endif /* Player_hpp */
