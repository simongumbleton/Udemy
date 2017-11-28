#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void DisplayGuessToUser(std::string);
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
	FBullCowGame BCGame;	//instance of a new game(class)

	constexpr int NUMBER_OF_TURNS = 5;	// constant expression defines the number of turns
										//Loop for the number of turns asking for guesses
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		std::string Guess = GetGuess();
		DisplayGuessToUser(Guess);
		std::cout << std::endl;
	}
}

void PrintIntro()
{
	//Introduce the game
	constexpr int WORD_LENGTH = 5;	// constant expression defines the length of the word to guess
	std::cout << "Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

std::string GetGuess()
{
	//Get a guess from the user
	std::cout << "Make a guess...";
	std::string Guess = "";
	getline(std::cin, Guess);	//std::getline (std::std::cin,name);
	return Guess;
}

void DisplayGuessToUser(std::string guess)
{
	//Repeat the gues back to the user
	std::cout << "You guessed.." << guess << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? y / n ";
	std::string Response = "";
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

