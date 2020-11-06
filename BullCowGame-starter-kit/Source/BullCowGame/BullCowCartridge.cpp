// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{   
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);

    Super::BeginPlay();

    

    Isograms = GetValidWords(Words);

    SetupGame();

}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{

    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
     
    // Checking Player Guess

    else
    {
        ProcessGuess(PlayerInput);
       
    }

    

}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to the Bull Cows!"));

    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() -1)];
    Lives = HiddenWord.Len() * 2; 
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("you have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess \nPress enter to continue..."));
    //PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); //Debug Line 
    
}   

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("Press enter to play again..."));
    
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == HiddenWord) 
        {
            PrintLine("You Won!");
            EndGame();
            return;
        }
    
    if (HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        return;
    }
    
        // Check if isogram
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

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
    
    
    
    FBullCowCount Score = GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);
    PrintLine(TEXT("You have %i lives left"), Lives);



}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{   
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for(int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison ++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }

    return true;
} 

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {   
        if (Word.Len() >=4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }

    }
    return ValidWords;

}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;

    for (int32 Index = 0; Index < Guess.Len(); Index++)
    {
        if (Guess[Index] == HiddenWord[Index] )
        {
            Count.Bulls++;
            continue;
        }

        for  (int32 CowIndex = 0; CowIndex < HiddenWord.Len(); CowIndex++)
        {
            if (Guess[Index] == HiddenWord[CowIndex])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}