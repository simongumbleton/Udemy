#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrint();

//Entry point for the game
int main() {


	PrintIntro();


	constexpr int NUMBER_OF_TURNS = 5;	// constant expression defines the number of turns
	//Loop for the number of turns asking for guesses
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrint();
		cout << endl;
	}


	//Evaluate Guess
	cout << "\nLets see how you did!..";

	cout << endl;
	return 0;
}

void PrintIntro()
{
	//Introduce the game
	constexpr int WORD_LENGTH = 5;	// constant expression defines the length of the word to guess
	cout << "Welcome to Bulls and Cows, a fun word game!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

string GetGuessAndPrint()
{
	//Get a guess from the user
	cout << "Make a guess...";
	string Guess = "";
	getline(cin, Guess);	//std::getline (std::cin,name);

	//Repeat the gues back to the user
	cout << "\nYou guessed.." << Guess << endl;

	return Guess;
}