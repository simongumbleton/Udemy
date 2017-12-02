#pragma once
#include <string>

using Fstring = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:	//Interface for the game

	FBullCowGame();		//Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	

	EGuessStatus CheckGuessValidity(Fstring Guess);

	FBullCowCount SubmitValidGuess(Fstring Guess);

	int32 GetHiddenWordLength() const;


private:	//variables internal to the class

	int32 MyCurrentTry;	//initialisation in constructor
	int32 MyMaxTries;
	Fstring MyHiddenWord;

};

