#pragma once
#ifndef BULLCOWGAME_H
#define BULLCOWGAME_H
#include<string>
#include<map>
#define TMap std::map
using int32 = int;
using FString = std::string;
struct BullCowCount
{
	int32 bullCount = 0;
	int32 cowCount =0;
};

enum EWordStatus
{
	OK, Not_Isogram, Wrong_Length, Not_LowerCase
};
class BullCowGame
{
  public:
	BullCowGame();
	void Reset();
	int32 GetMaxTries();
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	void SetWord(int32 length);
	int32 GetWordLength();
	EWordStatus IsGuessValid(FString guess);
	void SetCurrentTry(int32 curr);
	BullCowCount SubmitGuess(FString g);

  private:
	int32 myCurrentTry;
	int32 myWordLength;
	FString HiddenWord = "";
	bool bGameWon = false;
	bool IsIsogram(FString word) const;
	bool IsLowerCase(FString word) const;
};

#endif