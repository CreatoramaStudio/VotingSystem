#include "LogVotingSystem.h"

DEFINE_LOG_CATEGORY(LogVotingSystem);

void FLogVotingSystem::Info(const FString& String)
{
	UE_LOG(LogVotingSystem, Display, TEXT("%s"), *String);
}

void FLogVotingSystem::Warning(const FString& String)
{
	UE_LOG(LogVotingSystem, Warning, TEXT("%s"), *String);
}

void FLogVotingSystem::Error(const FString& String)
{
	UE_LOG(LogVotingSystem, Error, TEXT("%s"), *String);
}