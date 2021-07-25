// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VotingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVote);
/**
 * 
 */
UCLASS()
class VOTINGSYSTEM_API UVotingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintAssignable, Category = "Voting Subsystem")
	FVote OnAddOption;

	UPROPERTY(BlueprintAssignable, Category = "Voting Subsystem")
	FVote OnRemoveOption;

	UPROPERTY(BlueprintAssignable, Category = "Voting Subsystem")
	FVote OnVote;

	protected:

	UPROPERTY()
	TMap<FString,int32> Votes;

	private:

	public:

	UVotingSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure,Category= "Voting Subsystem")
	TMap<FString,int32> GetVotes() const;

	UFUNCTION(BlueprintCallable,Category= "Voting Subsystem")
	void ClearOptions();

	UFUNCTION(BlueprintCallable,Category= "Voting Subsystem")
	bool AddOption(const FString Option);

	UFUNCTION(BlueprintCallable,Category= "Voting Subsystem")
	bool RemoveOption(const FString Option);

	UFUNCTION(BlueprintCallable,Category= "Voting Subsystem")
	bool Vote(const FString Option, const int32 NumberOfVotes);

	UFUNCTION(BlueprintPure,Category= "Voting Subsystem")
	FString GetMostVotedOption();

	UFUNCTION(BlueprintPure,Category= "Voting Subsystem")
	TArray<FString> GetOptions() const;

	protected:

	private:
	
};
