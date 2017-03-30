#pragma once
#include "BullCowGame.h"
#include <iostream>
using int32 = int;
BullCowGame::BullCowGame()
{
	Reset();
}
void BullCowGame::Reset()
{
	//std::cout<<"Game Reset"<<std::endl;
//	myMaxTries = 5;
	myCurrentTry = 1;
	HiddenWord = "planet";
	bGameWon = false;
}

void BullCowGame::SetWord(int32 length)
{
	switch(length)
	{
		case 3:
		HiddenWord = "win";
		break;
	
		case 4:
		HiddenWord = "fire";
		break;
		
		case 5:
		HiddenWord = "metal";
		break;
		
		case 6:
		HiddenWord = "planet";
		break;
		
		case 7:
		HiddenWord = "salmons";
		break;
		
		case 8:
		HiddenWord = "salesman";
		break;
		
		default:
		HiddenWord = "planet";
	}
}

int32 BullCowGame::GetMaxTries()
{
	TMap<int32, int32> wordLengthToTries = {{3,5}, {4,5}, {5,6}, {6,6}, {7,9},{8,10}};
	return wordLengthToTries[HiddenWord.length()];
}

int32 BullCowGame::GetCurrentTry() const
{
	return myCurrentTry;
}

bool BullCowGame::IsGameWon() const
{
	return bGameWon;
}

EWordStatus BullCowGame::IsGuessValid(FString guess)
{
	std::cout<<"Entering GuessValid. Guess: "<<guess<<std::endl;
	int32 gLength = (int32)guess.length();
	int32 wLength = (int32)HiddenWord.length();
	if(wLength != gLength)
	{
		return EWordStatus::Wrong_Length;
	}
	else if(!IsLowerCase(guess))
	{
		return EWordStatus::Not_LowerCase;
	}
	else if(!IsIsogram(guess))
	{
		return EWordStatus::Not_Isogram;
	}
	else
	{
		return EWordStatus::OK;
	}
}

void BullCowGame::SetCurrentTry(int32 curr)
{
	myCurrentTry = curr;
	if(myCurrentTry > GetMaxTries())
	{
		std::cout<<"Oops! Ran outta tries!"<<std::endl;
	}
}

BullCowCount BullCowGame::SubmitGuess(FString g)
{
//	myCurrentTry++;
	
	BullCowCount bcCount;
	
	int32 wordLength = (int32)HiddenWord.length();
	for(int32 i=0; i<wordLength; i++)
	{
			for(int32 j=0; j<g.length(); j++)
			{
				if(g[j] == HiddenWord[i])
				{
					if(j == i)
					bcCount.bullCount++;
					else
					bcCount.cowCount++;
				}
			}
		}
		if(bcCount.bullCount == HiddenWord.length())
		{
			bGameWon = true;
		}
	return bcCount;
}

int32 BullCowGame::GetWordLength()
{
	return HiddenWord.length();
}

bool BullCowGame::IsIsogram(FString word) const
{
	if(word.length()<=1){return true;}
	
	TMap<char, bool> letterSeen;
	for(auto letter : word)
	{
		letter = tolower(letter);
		if(letterSeen[letter])
		{
			return false;
		}
		else
		{
			letterSeen[letter] = true;
		}
	}
	return true;
}

bool BullCowGame::IsLowerCase(FString word) const
{
	for(auto letter : word)
	{
		if(!islower(letter))
		{
			return false;
		}
	}
	return true;
}