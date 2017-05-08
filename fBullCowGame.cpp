#include "fBullCowGame.h"
using FString = std::string;
using int32 = int;

int32 fBullCowGame::GetHiddenWordLenght() const
{
	int32 HiddenWordLenght = MyHiddenWord.length();
	return HiddenWordLenght;
}

void fBullCowGame::Reset(){
	constexpr int32 MAX_TRIES = 8;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	return;}


int32 fBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 fBullCowGame::GetCurrentTry() const{ return MyCurrentTry;}

bool fBullCowGame::IsGameWon() const  {	return false;}


bool fBullCowGame::CheckGuessValidity(FString){	return false;}

FBullCowCount fBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 MyHiddenWordLenght = MyHiddenWord.length();
	if (Guess.length() == MyHiddenWordLenght) {
		for (int32 i = 0; i < MyHiddenWordLenght; i++) {
			for (int32 j = 0; j < MyHiddenWordLenght; j++) {
				if ((Guess[i] == MyHiddenWord[j]) && (j == i)) { BullCowCount.Bulls++; }
				else if (Guess[i] == MyHiddenWord[j]) { BullCowCount.Cows++; }
			}
		}
	} 



	//Recieves a VALID guess, increments return value
	return BullCowCount;
}
