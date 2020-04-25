#pragma once
#include "Memory.h"
#include <Windows.h>
#include <thread>

class Hacks
{
public:
	void godMode();
	void maxAmmo();
	void speed();
	void setPlrOffset();
	void fly();
	void norecoil();

	Hacks(Memory);
private:
	Memory mem;
	//To get to the Address do: BaseAddress + OffsetLocalPlayer + Offsets frome the list below.
	//Like for rapidfire: ReadProcessMemory(hproc,(LPCVOID=(Base+OffsetSpeed),&EndAddress_Speed, 4,NULL);
	//Base = BaseAddress + OffsetLocalPlayer (local player)

	__int32 BaseAddress;
	__int32 OffsetLocalPlayer;
	__int32 LocalPlayer;

	//offsets from local player
	__int32 m_XPos;
	__int32 m_YPos;
	__int32 m_ZPos;

	__int32 m_gravity;
	__int32	m_noclip;

	__int32 m_isPosMoving;
	__int32 m_Speed;
	__int32 m_Health;
	__int32 m_Vest;
	__int32 m_AmmoMags;
	__int32 m_Ammo;
	__int32 m_SecAmmo;
	__int32 m_Flashbangs;
	__int32 m_WeaponTimer;
	__int32 m_ShotsFired;

	//visuals & other stuff
	__int32 sv_GetMode;
	__int32 sv_ClientNumber;
	__int32 sv_name;
	__int32 p_MaxRoll;
	__int32 p_AutoReload;
	__int32 o_Paused;
	__int32 o_GameSpeed;
	__int32 m_MouseShotSensitivity; //CHANGE THIS TO 0 FOR NO RECOIL
	__int32 m_InvertMouse;
	__int32 h_ToggleConsole;
	__int32 h_ShowTarget;
	__int32 h_ShowSpeed;
	__int32 h_ShowScoreOnDeath;
	__int32 h_ShowRadarValues;
	__int32 h_ShowMap;
	__int32 h_Righthanded;
	__int32 h_RadarHeight;
	__int32 h_RadarEntSize;
	__int32 h_OldAmmoHUD;
	__int32 h_HideRadar;
	__int32 h_HideHudMessages;
	__int32 h_HideHudEquipment;
	__int32 h_HideDamageIndicator;
	__int32 h_HideCompass;
	__int32 h_DrawGun;
	__int32 h_DrawFPS;
	__int32 h_DbgPos;
	__int32 h_DamageScreenFade;
	__int32 h_DamageScreenFactor;
	__int32 h_DamageScreenAlpha;
	__int32 h_DamageScreen;
	__int32 h_CrosshairSize;
	__int32 g_GameVersion;
	__int32 dbg_FlySpeed;
	__int32 EngineState_Test;
};

