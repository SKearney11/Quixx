//
//  main.cpp
//  Quixx
//
//  Created by Sean Kearney on 01/05/2017.
//  Copyright © 2017 Sean Kearney. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Dice.hpp"

using namespace std;


int main() {
    Player p1 = *new Player;
    //Player p2 = *new Player;
    printBoard(p1);
    vector<int> diceResults = rollDice();
    printDice(diceResults);
    askMove(p1, diceResults);
    printBoard(p1);

    return 0;
}

void printBoard(Player& p){
    cout << "Red: ";
    for(int i = 0; i < p.red.size(); i++)
    {
        cout << " " << p.red[i];
    }
    cout << "\nYellow: ";
    for(int i = 0; i < p.yellow.size(); i++)
    {
        cout << " " << p.yellow[i];
    }
    cout << "\nGreen: ";
    for(int i = 0; i < p.green.size(); i++)
    {
        cout << " " << p.green[i];
    }
    cout << "\nBlue: ";
    for(int i = 0; i < p.blue.size(); i++)
    {
        cout << " " << p.blue[i];
    }
    cout << endl;
}

void askMove(Player& p1, vector<int> diceResults){
    char color;
    cout << "enter color (r y g b): ";
    //cin >> color;
    int number;
    cout << "enter number 2 - 12: ";
    cin >> number;
    makeMove(p1, diceResults, number);
}


void printDice(vector<int> diceResults){
    cout <<"White 1: " << diceResults[0] <<"\n";
    cout <<"White 2: " << diceResults[1] <<"\n";
    cout <<"Red: " << diceResults[2] <<"\n";
    cout <<"Yellow: " << diceResults[3] <<"\n";
    cout <<"Green: " << diceResults[4] <<"\n";
    cout <<"Blue: " << diceResults[5] <<"\n";
}
