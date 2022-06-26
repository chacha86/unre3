// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#define LOG(s, ...) UE_LOG(LogTemp, Warning, TEXT(s), __VA_ARGS__)
/**
 * 
 */
class COLLISION_API MyUtil
{
public:
	MyUtil();
	~MyUtil();
};
