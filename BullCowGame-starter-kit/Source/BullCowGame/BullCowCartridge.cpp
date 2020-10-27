// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); //Debug Line

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
     
    // Checking Player Guess

    else
    {
        ProcessGuess(Input);
       
    }

    

}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to the Bull Cows!"));

    HiddenWord = TEXT("cake"); 
    Lives = HiddenWord.Len(); 
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("you have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess \nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("Press enter to play again..."));
    
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord) 
        {
            PrintLine("You Won!");
            EndGame();
            return;
        }
    
    // Check if isogram
    // if (!isIsogram)
    // {
    //     PrintLine(TEXT("No repeating letters, guess again"));
    // }
    // Prompt To Guess Again
    // Check if right number of characters
    if (HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        return;
    }
    // Prompt To Guess Again

    // Remove Life
    --Lives;
    PrintLine(TEXT("You have lost a life"));

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
    
    // Show Bulls and Cows
    PrintLine(TEXT("You have %i lives left"), HiddenWord.Len());
    // Check if Lives > 0
    // If Yes GuessAgain
    // Show Lives Left
    // If No Show GameOver and HiddenWord
    // Prompt to Play Again, Press Enter To Play Again 
    // Check User Input


}