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
    int score;
    int forfeits;
};

void printBoard(Player& p);
void makeColorMove(Player& p, vector<int> diceResults, int input, char color);
void makeWhiteMove(Player& p, vector<int> diceResults, int input, char color);
void askColorMove(Player& p1, vector<int> diceResults);
void askWhiteMove(Player& p1, vector<int> diceResults);
void printDice(vector<int> diceResults);
bool gameOver(Player p1, Player p2);

#endif /* Player_hpp */
