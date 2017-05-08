/*
This is the console executable, that makes use of the BullCow class.
This acts as a view in MVC pattern and is responsible or all user interaction.
For game logic see the fBullCowGame class.
*/

#include <iostream>
#include <string>	
#include "fBullCowGame.h"
//#include "fBullCowGame.cpp"
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

fBullCowGame BCGame; //Object








int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; 
}









void PrintIntro()
{
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLenght();
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << CurrentTry << std::endl;

		
	//constexpr int32 NUMBER_OF_TURNS = 5;
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses TODO while loop 4 validating tries
	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); 

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;


		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}


FText GetGuess()
{
	// get a guess from the player
	std::cout << "Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}