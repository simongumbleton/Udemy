#pragma once
#include <string>

using Fstring = std::string;
using int32 = int;

class FBullCowGame
{
public:	//Interface for the game

	FBullCowGame();		//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	//TO DO make a more rich return value
	bool CheckGuessValidity(Fstring);

	//provdie a method for counting bulls and cows and increasing try number

private:	//variables internal to the class

	int32 MyCurrentTry;	//initialisation in constructor
	int32 MyMaxTries;

};

