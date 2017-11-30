/*
This is the console executable that makes use of the Bullcow class.
This acts as the view in a MVC pattern and is responsible for all user interaction. 
For game logic see the FBullCowGame class
*/



#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetGuess();
void DisplayGuessToUser(Ftext);
bool AskToPlayAgain();

FBullCowGame BCGame;	//instance of a new game(class)

//Entry point for the game
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		//TODO add game summary
		bPlayAgain = AskToPlayAgain();
	}
	while(bPlayAgain);
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//std::cout << MaxTries << std::endl;

	//Loop for the number of turns asking for guesses
	//TODO change to while loop once guess validation is live
	for (int32 i = 1; i <= MaxTries; i++)
	{
		Ftext Guess = GetGuess();	//TODO check for valid guesses

		// submit valid guess to game
		// Print number of bulls and cows

		DisplayGuessToUser(Guess);
		std::cout << std::endl;
	}
}

void PrintIntro()
{
	//Introduce the game
	constexpr int32 WORD_LENGTH = 5;	// constant expression defines the length of the word to guess
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

Ftext GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	//std::cout << CurrentTry << std::endl;

	//Get a guess from the user
	std::cout << "Try "	<< CurrentTry << ". Make a guess...";
	Ftext Guess = "";
	getline(std::cin, Guess);	//std::getline (std::std::cin,name);
	return Guess;
}

void DisplayGuessToUser(Ftext guess)
{
	//Repeat the gues back to the user
	std::cout << "You guessed.." << guess << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? y / n ";
	Ftext Response = "";
	getline(std::cin, Response);
	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		std::cout << "Play Again!\n";
		return true;
	}
	else if ((Response[0] == 'n') || (Response[0] == 'N'))
	{
		std::cout << "Do not play again\n";
		return false;
	}
	else
	{
		std::cout << "Did not understand input\n";
		AskToPlayAgain();
		return false;
	}
	
}

