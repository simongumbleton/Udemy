/*
This is the console executable that makes use of the Bullcow class.
This acts as the view in a MVC pattern and is responsible for all user interaction. 
For game logic see the FBullCowGame class
*/



#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"
#pragma once

//to make syntax Unreal friendly
using Ftext = std::string;
using int32 = int;

// prototype functions because we are outside a class
void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
void DisplayGuessToUser(Ftext);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;	//instance of a new game(class)

//Entry point for the game
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		PrintGameSummary();
		bPlayAgain = AskToPlayAgain();
	}
	while(bPlayAgain);
	return 0;
}

//Plays a single game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	int32 HiddenWordLength = BCGame.GetHiddenWordLength();

	std::cout << "Can you guess the " << HiddenWordLength << " letter isogram I'm thinking of?\n";

	//Loop for the number of turns asking for guesses
	//while game is NOT won
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		Ftext Guess = GetValidGuess();

		// submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		DisplayGuessToUser(Guess);
		std::cout << std::endl;

	}
	return;
}

void PrintIntro()
{
	//Introduce the game
	
	std::cout << std::endl << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";

	std::cout << "Would you like a 3,4,5,6 or 7 letter hidden word?\n";
	int32 lengthForNewWord;
	std::cin >> lengthForNewWord;
	// Because input stream is in a failed state, cin will be evaluated to false
	while (!std::cin)
	{
		std::cin.clear();    // Restore input stream to working state
		std::cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered
		std::cout << "I said enter an integer, Dumbass. Try again: \n";
		std::cin >> lengthForNewWord;    // After cin is restored and any garbage in the stream has been cleared, store user input in number again
	}

	if (!BCGame.SetLengthOfHiddenWord(lengthForNewWord))
	{
		std::cout << "That length is not supported. Defaulting to hidden word length of " << BCGame.GetHiddenWordLength() << ".\n\n";
	}

	std::cin.clear();    // Restore input stream to working state
	std::cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered

	return;
}

Ftext GetValidGuess()	//Loop until user gives valid guess
{
	//Get a guess from the user

	Ftext Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() <<". Make a guess...";
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
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? y / n ";
	Ftext Response = "";
	getline(std::cin, Response);
	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		std::cout << "Playing again!!\n";
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
	}
	
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You win!\n" ;
	}
	else
	{
		std::cout << "Sorry, you didn't win. Better luck next time.\n";
	}
	std::cout << std::endl;
	
	return;
}

