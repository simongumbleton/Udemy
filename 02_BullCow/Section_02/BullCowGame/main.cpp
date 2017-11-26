#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	//Introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";

	//Get a guess from the user
	cout << "Make a guess...";
	string Guess = "";
	getline(cin, Guess);	//std::getline (std::cin,name);
	//Repeat the gues back to the user
	cout << "\nYou guessed.." << Guess << endl;

	//Get a guess from the user
	cout << "Make a guess...";
	getline(cin, Guess);	//std::getline (std::cin,name);
	//Repeat the gues back to the user
	cout << "\nYou guessed.." << Guess;


	//Evaluate Guess
	cout << "\nLets see how you did!..";

	cout << endl;
	return 0;
};