#pragma once
#include<iostream>
#include<string>
#include "BullCowGame"

//using namespace std;
using FText = std::string;
using int32 = int;

//const int32 Word_Length = 6;
BullCowGame bcg;
void DisplayIntro();
void AskWordLength();
void PlayGame();
FText GetGuess();
void PrintGuess(FText gs);
bool AskToPlayAgain();
void CheckGameWin();

int main()
{
	do
	{
		bcg.Reset();
		DisplayIntro();
		AskWordLength();
		PlayGame();
	} while(AskToPlayAgain());
}

void DisplayIntro()
{
	std::cout<<std::endl;
	std::cout<<"        \\m/\\m/ BULLS & COWS GAME \\m/\\m/"<<std::endl;
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>"<<std::endl;
}

void AskWordLength()
{
		int32 length = 0;
	bool bCheckVal = false;
	while(!bCheckVal){
	std::cout<<"Please Select Word Length in numerics.\n 3; 4; 5; 6 letter word? : ";

	std::cin>>length;
	if(std::cin.fail() || (length <3 || length> 6))
	{
		std::cout<<"Please give a valid value between 3 & 6"<<std::endl;
		std::cout<<std::endl;
	} else
	{
		bCheckVal = true;
	}
	}
	bcg.SetWord(length);
std::cout<<"Let's begin the Bulls & Cows Game. Word Length is: "<<bcg.GetWordLength()<<". No. of total guesses: "<<bcg.GetMaxTries()<<std::endl;
std::cout<<std::endl;
}

void PlayGame()
{
	int myTry = bcg.GetCurrentTry();
	while(!bcg.IsGameWon() && bcg.GetCurrentTry() <= bcg.GetMaxTries())
	{
		FText guess;
		guess = GetGuess();
		if(guess != "")
			PrintGuess(guess);
	}
}
FText GetGuess()
{
	std::cout<<"Guess "<<bcg.GetCurrentTry()<<" of "<<bcg.GetMaxTries()<<": Enter your guess: ";
	FText Guess;
	std::cin.ignore();
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(FText gs)
{
	EWordStatus status = bcg.IsGuessValid(gs);
	switch(status)
	{
		case EWordStatus::OK:
			std::cout<<"Your guess was: "<<gs<<std::endl;
			std::cout<<"BullCow Count: "<<bcg.SubmitGuess(gs).bullCount;
			std::cout<<", "<<bcg.SubmitGuess(gs).cowCount<<std::endl;
			bcg.SetCurrentTry(bcg.GetCurrentTry() + 1);
			break;
		
		case EWordStatus::Wrong_Length:
			std::cout<<"Wrong word length. Word is "<<bcg.GetWordLength()<<" letters long."<<std::endl;
			break;
			
		case EWordStatus::Not_LowerCase:
			std::cout<<"Word not lower case completely."<<std::endl;
			break;
			
		case EWordStatus::Not_Isogram:
		std::cout<<"Guess is not an Isogram."<<std::endl;
	}
	if(bcg.IsGameWon())
	{
		std::cout<<"Yay! You Win"<<std::endl;
	}
	std::cout<<std::endl;
}


bool AskToPlayAgain()
{
	std::cout<<"Play the game again?: ";
		FText resp;
	std::cin.ignore();
		std::getline(std::cin, resp);
	return (resp[0] == 'y' || resp[0] == 'Y');
}