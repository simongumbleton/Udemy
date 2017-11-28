#pragma once
#include <string>

class FBullCowGame
{
public:	//Interface for the game

	void Reset();	//TO DO make a more rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:	//variables internal to the class

	int MyCurrentTry = 1;
	int MyMaxTries = 5;

};

