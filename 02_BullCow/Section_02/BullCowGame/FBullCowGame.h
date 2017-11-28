#pragma once

class FBullCowGame
{
public:	//Interface for the game

	void Reset();	//TO DO make a more rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(string);

private:	//variables internal to the class

	int MyCurrentTry;
	int MyMaxTries;

};

