#include "Hacks.h"

void Hacks::godMode()
{
	int hp = 1337;
	mem.targetWrite32(LPVOID(LocalPlayer + m_Health), (LPCVOID)&hp);
}

void Hacks::maxAmmo()
{
	int grenade = 69;
	mem.targetWrite32(LPVOID(LocalPlayer + m_Flashbangs), (LPCVOID)&grenade);
}

void Hacks::speed()
{
	int speed = 0;
	
	while (1) {
		if (GetAsyncKeyState('W') & 0x80000000) {
			speed = 5;
			mem.targetWrite32(LPVOID(LocalPlayer + m_Speed), (LPCVOID)&speed);
		}
	}

}

//not working, WIP
void Hacks::norecoil()
{
	bool norecoil = 0;
	mem.targetWrite32(LPVOID(LocalPlayer + m_MouseShotSensitivity), (LPCVOID)&norecoil);
}

//not working, WIP
void Hacks::fly()
{
	float zpos = 0;
	float ypos = 0;
	float xpos = 0;
	int speed = 0;
	int nclip = 0;

	mem.targetWrite32(LPVOID(LocalPlayer + m_noclip), (LPCVOID)&nclip);
	//while (1) {
	//	if (GetAsyncKeyState(VK_SPACE) & 0x80000000) {
	//		mem.targetRead32(LPCVOID(LocalPlayer + m_ZPos), &zpos);

	//		zpos += (float)0.001;

	//		mem.targetWrite32(LPVOID(LocalPlayer + m_ZPos), (LPCVOID)&zpos);
	//		//mem.targetWrite32(LPVOID(LocalPlayer + m_gravity), (LPCVOID)&gravity);
	//		

	//	}
	//	else if (GetAsyncKeyState(VK_LSHIFT) & 0x80000000) {
	//		mem.targetRead32(LPCVOID(LocalPlayer + m_ZPos), &zpos);

	//		zpos -= (float)0.001;

	//		mem.targetWrite32(LPVOID(LocalPlayer + m_ZPos), (LPCVOID)&zpos);

	//	}
	//}
}

void Hacks::setPlrOffset()
{
	mem.targetRead32((LPCVOID)(BaseAddress + OffsetLocalPlayer), &LocalPlayer);
}

Hacks::Hacks(Memory mem) {
	this->mem = mem;
	BaseAddress = 0x400000;
	OffsetLocalPlayer = 0x10F4F4;
	LocalPlayer = 0;

	m_XPos = 0x34;
	m_YPos = 0x38;
	m_ZPos = 0x3c;

	m_gravity = 0x54;//1 fast fall?
	m_noclip = 0x58;//-1 active

	m_isPosMoving = 0x0070;
	m_Speed = 0x80;
	m_Health = 0x00F8;
	m_Vest = 0x00FC;
	m_AmmoMags = 0x0128;
	m_Ammo = 0x0150;
	m_SecAmmo = 0x013C;
	m_Flashbangs = 0x0158;
	m_WeaponTimer = 0x0178;
	m_ShotsFired = 0x01A0;

	sv_GetMode = 0x50F49C;
	sv_ClientNumber = 0x510198;
	sv_name = 0x51019C;
	p_MaxRoll = 0x510144;
	p_AutoReload = 0x5101D0;
	o_Paused = 0x510CE0;
	o_GameSpeed = 0x510CDC;
	m_MouseShotSensitivity = 0x4EE444; //CHANGE THIS TO 0 FOR NO RECOIL
	m_InvertMouse = 0x51016C;
	h_ToggleConsole = 0x4FEC10;
	h_ShowTarget = 0x50F284;
	h_ShowSpeed = 0x50F288;
	h_ShowScoreOnDeath = 0x50F514;
	h_ShowRadarValues = 0x50F268;
	h_ShowMap = 0x50F240;
	h_Righthanded = 0x510A4C;
	h_RadarHeight = 0x50F264;
	h_RadarEntSize = 0x50F208;
	h_OldAmmoHUD = 0x510A48;
	h_HideRadar = 0x50F21C;
	h_HideHudMessages = 0x50F230;
	h_HideHudEquipment = 0x50F234;
	h_HideDamageIndicator = 0x50F248;
	h_HideCompass = 0x50F220;
	h_DrawGun = 0x50F200;
	h_DrawFPS = 0x50F210;
	h_DbgPos = 0x50F280;
	h_DamageScreenFade = 0x50F278;
	h_DamageScreenFactor = 0x50F270;
	h_DamageScreenAlpha = 0x50F274;
	h_DamageScreen = 0x50F26C;
	h_CrosshairSize = 0x50F20C;
	g_GameVersion = 0x510CF4;
	dbg_FlySpeed = 0x510148;
	EngineState_Test = 0x509BD8;

	setPlrOffset();
}
