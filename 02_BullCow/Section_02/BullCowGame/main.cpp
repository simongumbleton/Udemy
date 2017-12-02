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
Ftext GetValidGuess();
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
		Ftext Guess = GetValidGuess();	

		// submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		DisplayGuessToUser(Guess);
		std::cout << std::endl;
	}
}

void PrintIntro()
{
	//Introduce the game
	int32 HiddenWordLength = BCGame.GetHiddenWordLength();	
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << HiddenWordLength << " letter isogram I'm thinking of?\n";
	return;
}

Ftext GetValidGuess()	//Loop until user gives valid guess
{
	//Get a guess from the user

	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Make a guess...";
		Guess = "";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Your guess is not an isogram. Isograms are words with no repeating letters\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Your guess is the wrong length.\nPlease enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Your guess must be lowercase\n";
			break;
		default:	
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping till no errors

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

