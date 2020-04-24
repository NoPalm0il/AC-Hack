#pragma once
class Offsets
{
public:
	__int32 BaseAddress;
	__int32 OffsetLocalPlayer;


	//local offsets
	//To get to the Address do: BaseAddress + OffsetLocalPlayer + Offsets frome the list below.
	//Like for rapidfire: ReadProcessMemory(hproc,(LPCVOID=(Base+OffsetSpeed),&EndAddress_Speed, 4,NULL);
	//Base = BaseAddress + OffsetLocalPlayer (local player)
};
