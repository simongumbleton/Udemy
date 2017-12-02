#include "stdafx.h"
#include "FBullCowGame.h"
#include <map>
#define TMap std::map
#pragma once

using Fstring = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()	//default constructor
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,3},{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}


void FBullCowGame::Reset()
{
	bGameIsWon = false;
	const Fstring HIDDEN_WORD = "plan";

	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess)
{
	if (!IsIsogram(Guess))	//if guess not isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))	//if not lowercase
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
	if (BullCowCount.Bulls == HiddenWordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsIsogram(Fstring Word) const
{
	//0 and 1 letter word are isograms
	if (Word.length() <= 1) { return true; }

	// create empty map
	TMap<char, bool> LetterSeen;

	//for each letter of guess
	for (auto Letter : Word)
	{	
		Letter = tolower(Letter);
		//if letter is in map
		if (LetterSeen[Letter])
		{		
			//break out word is not isogram!
			return false;
		}
		else
		{
			//add letter to map
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(Fstring Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return (true);
}
