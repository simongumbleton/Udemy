#pragma once
#include <string>

class FBullCowGame
{
public:	//Interface for the game

	FBullCowGame();		//Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	//TO DO make a more rich return value
	bool CheckGuessValidity(std::string);

private:	//variables internal to the class

	int MyCurrentTry;	//initialisation in constructor
	int MyMaxTries;

};

