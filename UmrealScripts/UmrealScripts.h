﻿#pragma once
#include "UmScriptsFramework.h"

#ifdef UMREALSCRIPTS_EXPORT
#define UMREALSCRIPTS_DECLSPEC __declspec(dllexport)
#else
#define UMREALSCRIPTS_DECLSPEC __declspec(dllimport)
#endif

/// <summary>
/// 엔진 코어를 스크립트와 동기화합니다.
/// 모든 스크립트는 코어 사용시 UmrealEngine에 접근해 사용해야 합니다.
/// </summary>
/// <param name="engineCores :">엔진 코어 모음</param>
/// <returns></returns>
extern "C" UMREALSCRIPTS_DECLSPEC void InitalizeUmrealScript(const EngineCores& engineCores);


extern "C" UMREALSCRIPTS_DECLSPEC Component* NewTestScript();