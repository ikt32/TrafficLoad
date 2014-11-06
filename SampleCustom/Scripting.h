#pragma once

#include "../ScriptHook/Scripting.h"

namespace Scripting
{
	static void SetCarDensityMultiplier(f32 p0) { NativeInvoke::Invoke<ScriptVoid>("SET_CAR_DENSITY_MULTIPLIER", p0); }
	static void SetRandomCarDensityMultiplier(f32 p0) { NativeInvoke::Invoke<ScriptVoid>("SET_RANDOM_CAR_DENSITY_MULTIPLIER", p0); }
	static void SetParkedCarDensityMultiplier(f32 p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PARKED_CAR_DENSITY_MULTIPLIER", p0); }
	static void SetPedDensityMultiplier(f32 p0) { NativeInvoke::Invoke<ScriptVoid>("SET_PED_DENSITY_MULTIPLIER", p0); }
	//static void RequestModelAdd(u32 nameHash) { NativeInvoke::Invoke<NATIVE_REQUEST_MODEL, ScriptVoid>(nameHash); }
	//static b8 IsGameKeyboardKeyJustPressed(u32 key) { return NativeInvoke::Invoke<NATIVE_IS_GAME_KEYBOARD_KEY_PRESSED, b8>(key); }
}