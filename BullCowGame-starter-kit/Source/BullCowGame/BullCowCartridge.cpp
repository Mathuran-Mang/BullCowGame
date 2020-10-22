// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cows!"));
    PrintLine(TEXT("Guess the 4 letter word!"));  //Magic Number Remove
    PrintLine(TEXT("Press enter to continue..."));
    
    // Setting Up Game
    HiddenWord = TEXT("cake"); // Set the HiddenWord
    // Set Lives

    // Prompt Player For Guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
     
    // Checking Player Guess

    PrintLine(Input);
    if (Input == HiddenWord) 
    {
        PrintLine("You Won!");
    }
    else
    {
        PrintLine("You Lost!");

        
    }
    // Check if isogram
    // Prompt To Guess Again
    // Check if right number of characters
    // Prompt To Guess Again

    // Remove Life

    // Check if Lives > 0
    // If Yes GuessAgain
    // Show Lives Left
    // If No Show GameOver and HiddenWord
    // Prompt to Play Again, Press Enter To Play Again 
    // Check User Input
    

}