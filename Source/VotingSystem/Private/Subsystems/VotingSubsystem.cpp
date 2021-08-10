// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/VotingSubsystem.h"
#include "LogVotingSystem.h"

UVotingSubsystem::UVotingSubsystem()
{
	
}

void UVotingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
}

void UVotingSubsystem::Deinitialize()
{
	ClearOptions();
}

TMap<FString, int32> UVotingSubsystem::GetVotes() const
{
	return Votes;
}

void UVotingSubsystem::ClearOptions()
{
	Votes.Empty();
}

bool UVotingSubsystem::AddOption(const FString Option)
{
	if (!Votes.Contains(Option))
	{
		Votes.Add(Option,0);
		OnAddOption.IsBound() ? OnAddOption.Broadcast() : FLogVotingSystem::Info("UVotingSubsystem::AddOption OnAddOption.IsBound is false");
		return true;
	}
	return false;
}

bool UVotingSubsystem::RemoveOption(const FString Option)
{
	if (Votes.Contains(Option))
	{
		Votes.Remove(Option);
		OnRemoveOption.IsBound() ? OnRemoveOption.Broadcast() : FLogVotingSystem::Info("UVotingSubsystem::RemoveOption OnRemoveOption.IsBound is false");
		return true;
	}
	return false;
}

bool UVotingSubsystem::Vote(const FString Option, const int32 NumberOfVotes, const bool bAddOption)
{
	if (bAddOption)
	{
		AddOption(Option);
	}
	
	if (Votes.Contains(Option))
	{
		Votes[Option] += NumberOfVotes;
		OnVote.IsBound() ? OnVote.Broadcast() : FLogVotingSystem::Info("UVotingSubsystem::Vote OnVote.IsBound is false");
		return true;
	}
	return false;
}

FString UVotingSubsystem::GetMostVotedOption()
{
	Votes.ValueSort([](const int32& A, const int32& B)
	{
		return A > B;
	});
	
	return GetOptions().Num() > 0 ? GetOptions()[0] : "";
}

TArray<FString> UVotingSubsystem::GetOptions() const
{
	TArray<FString> Options;
	Votes.GetKeys(Options);
	return Options;
}
