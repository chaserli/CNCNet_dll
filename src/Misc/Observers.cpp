/**
*  yrpp-spawner
*
*  Copyright(C) 2022-present CnCNet
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.If not, see <http://www.gnu.org/licenses/>.
*/

#include <Helpers/Macro.h>
#include <SessionClass.h>
#include <Unsorted.h>

// Allow observer in skirmish
DEFINE_HOOK_AGAIN(0x4FCBD0, HouseClass_FlagToWinLose_SpectatorPatch, 0x6)
DEFINE_HOOK(0x4FC9E0, HouseClass_FlagToWinLose_SpectatorPatch, 0x6)
{
	return (SessionClass::IsSkirmish() && Game::ObserverMode)
		? 0x4FCDBC
		: 0;
}

// Allow skirmish observer to control gamespeed
DEFINE_HOOK(0x4E20BA, GameControlsClass__SomeDialog, 0x5)
{
	return (SessionClass::IsSkirmish() && Game::ObserverMode)
		? 0x4E211A
		: 0;
}

// Use correct flag icon for observer
DEFINE_HOOK(0x6439F4, ProgressScreenClass__643720, 0x6)
{
	enum { AllowObserver = 0x643A04, NotAllowObserver = 0x643A18 };

	return !SessionClass::IsCampaign()
		? AllowObserver
		: NotAllowObserver;
}

// Use correct loading screen colors for observer
DEFINE_HOOK(0x642B60, ProgressScreenClass__LoadTextColor3, 0x5)
{
	enum { AllowObserver = 0x642B6F, NotAllowObserver = 0x642B8B };

	return !SessionClass::IsCampaign()
		? AllowObserver
		: NotAllowObserver;
}

DEFINE_HOOK(0x5533E0, LoadProgressMgr__Draw_SetBackground, 0x5)
{
	return Game::ObserverMode
		? 0x5533EF
		: 0;
}

DEFINE_HOOK(0x5539E4, LoadProgressMgr__Draw_LoadBriefing, 0x5)
{
	return Game::ObserverMode
		? 0x5539F3
		: 0;
}

DEFINE_HOOK(0x5536A0, LoadProgressMgr__Draw_CountryName, 0x5)
{
	return Game::ObserverMode
		? 0x5536AF
		: 0;
}