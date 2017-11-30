#include "stdafx.h"
#include "FBullCowGame.h"

using Fstring = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const Fstring HIDDEN_WORD = "plant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(Fstring)
{
	return false;
}

//Recievs a valid guess. Increments turn and returns count
//a method for counting bulls and cows and increasing try number - Assuming valid guess
BullCowCount FBullCowGame::SubmitGuess(Fstring)
{
	//increment turn number
	MyCurrentTry++;
	//setup return variabls
	BullCowCount BullCowCount;
	//loop through letters in guess
		//compare letters against hidden word
	return BullCowCount;
}
