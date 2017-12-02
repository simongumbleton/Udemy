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
	const Fstring HIDDEN_WORD = "plant";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess)
{
	if (false)	//if guess not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)	//if not lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) //if length wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else //otherwise
	{
		return EGuessStatus::OK;
	}

	
}

//Recievs a valid guess. Increments turn and returns count
//a method for counting bulls and cows and increasing try number - Assuming valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(Fstring Guess)
{
	MyCurrentTry++;
	//setup return variabls
	FBullCowCount BullCowCount;
	int32 GuessWordLength = Guess.length();
	int32 HiddenWordLength = MyHiddenWord.length();

	//loop through letters in hidden word
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		//compare letters against guess
		for (int32 GChar = 0; GChar < GuessWordLength; GChar++)
		{	//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{	// if they're in the same place
				if (MHWChar == GChar) 
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}			
			}
		}
	}
	return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}
