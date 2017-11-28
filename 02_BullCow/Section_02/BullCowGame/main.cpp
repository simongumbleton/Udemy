#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
void DisplayGuessToUser(string);
bool AskToPlayAgain();

//Entry point for the game
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while(bPlayAgain);
	return 0;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;	// constant expression defines the number of turns
										//Loop for the number of turns asking for guesses
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		string Guess = GetGuess();
		DisplayGuessToUser(Guess);
		cout << endl;
	}
}

void PrintIntro()
{
	//Introduce the game
	constexpr int WORD_LENGTH = 5;	// constant expression defines the length of the word to guess
	cout << "Welcome to Bulls and Cows, a fun word game!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

string GetGuess()
{
	//Get a guess from the user
	cout << "Make a guess...";
	string Guess = "";
	getline(cin, Guess);	//std::getline (std::cin,name);
	return Guess;
}

void DisplayGuessToUser(string guess)
{
	//Repeat the gues back to the user
	cout << "You guessed.." << guess << endl;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? y / n ";
	string Response = "";
	getline(cin, Response);
	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		cout << "Play Again!\n";
		return true;
	}
	else if ((Response[0] == 'n') || (Response[0] == 'N'))
	{
		cout << "Do not play again\n";
		return false;
	}
	else
	{
		cout << "Did not understand input\n";
		return false;
	}
	
}

