#pragma once
#include <string>

using Fstring = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:	//Interface for the game

	FBullCowGame();		//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	
	//TO DO make a more rich return value
	bool CheckGuessValidity(Fstring);

	BullCowCount SubmitGuess(Fstring);


private:	//variables internal to the class

	int32 MyCurrentTry;	//initialisation in constructor
	int32 MyMaxTries;
	Fstring MyHiddenWord;

};

