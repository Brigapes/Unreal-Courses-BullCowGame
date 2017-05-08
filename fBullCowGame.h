#pragma once
#include <string>

using FString = std::string;
using int32 = int;


struct FBullCowCount
{
	int32 Bulls = 0;
    int32 Cows = 0;
};




class fBullCowGame {
public:
	fBullCowGame() //consturctor
	{ Reset();	}

	int32 GetHiddenWordLenght() const;
	void Reset(); 
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString); // TODO make a more rich return value.

	//Method 4 counting bull&cows
	FBullCowCount SubmitGuess(FString);



										  // ^^ Please try and ignore this and focus on the interface above ^^
private: //defined in constrtuctor
	int32 MyCurrentTry ;
	int32 MyMaxTries ;
	FString MyHiddenWord;
};