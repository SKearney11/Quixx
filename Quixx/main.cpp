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
    Player p2 = *new Player;
    cout << "Welcome to quixx.\n";
    vector<int> diceResults = rollDice();
    
    while(gameOver(p1, p2) == false){
        //player 1s turn
        cout << "\n\nPLAYER 1" << endl;
        printBoard(p1);
        diceResults = rollDice();
        cout << "Dice Results:" << endl;
        printDice(diceResults);
        askColorMove(p1, diceResults);
        askWhiteMove(p1, diceResults);
        cout << "\nYour result." << endl;
        printBoard(p1);
        cout << endl;
        //player 2 picks from white dice
        cout << "\n\n\nPLAYER 2" << endl;
        printBoard(p2);
        cout << "Dice Results:" << endl;
        printDice(diceResults);
        askWhiteMove(p2, diceResults);
        cout << "\nYour result." << endl;
        printBoard(p2);
        cout << endl;
        
        //switch positions
        //player 2s turn
        cout << "\n\nPLAYER 2" << endl;
        printBoard(p2);
        diceResults = rollDice();
        cout << "Dice Results:" << endl;
        printDice(diceResults);
        askColorMove(p2, diceResults);
        askWhiteMove(p2, diceResults);
        cout << "\nYour result." << endl;
        printBoard(p2);
        cout << endl;
        //player 1 picks from white dice
        cout << "\n\n\nPLAYER 1" << endl;
        printBoard(p1);
        cout << "Dice Results:" << endl;
        printDice(diceResults);
        askWhiteMove(p1, diceResults);
        cout << "\nYour result." << endl;
        printBoard(p1);
        cout << endl;
    }
    cout << "Player 1 score: " << p1.score << "\nPlayer 2 score: " << p2.score << endl;
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
    cout << endl << endl;
}

void askColorMove(Player& p1, vector<int> diceResults){
    char color;
    cout << "Pick one COLORED dice and one WHITE dice and make a choice. \nEnter color (r y g b): ";
    cin >> color;
    int number;
    cout << "enter number 2 - 12: ";
    cin >> number;
    makeColorMove(p1, diceResults, number, color);
}

void askWhiteMove(Player& p1, vector<int> diceResults){
    char color;
    cout << "Add up both WHITE dice and make a choice. \nEnter color (r y g b): ";
    cin >> color;
    int number;
    cout << "enter number 2 - 12: ";
    cin >> number;
    makeWhiteMove(p1, diceResults, number, color);
}


void printDice(vector<int> diceResults){
    cout <<"White 1: " << diceResults[0] <<"\n";
    cout <<"White 2: " << diceResults[1] <<"\n";
    cout <<"Red: " << diceResults[2] <<"\n";
    cout <<"Yellow: " << diceResults[3] <<"\n";
    cout <<"Green: " << diceResults[4] <<"\n";
    cout <<"Blue: " << diceResults[5] <<"\n\n";
}

bool gameOver(Player p1, Player p2){
    if(p1.score >= 5)
    {
        return true;
    }
    if(p2.score >= 5)
    {
        return true;
    }
    return false;
}
