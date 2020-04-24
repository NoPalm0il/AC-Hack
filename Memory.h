#pragma once
#include <Windows.h>
#include <iostream>

class Memory
{
private:
	SIZE_T bytesRead;
	HANDLE hProcess;
	DWORD PID;
public:
	BOOL genPID();
	void genHandle();
	void targetRead16(LPCVOID, LPVOID);
	void targetRead32(LPCVOID, LPVOID);
	void targetWrite16(LPVOID, LPCVOID);
	void targetWrite32(LPVOID, LPCVOID);

	Memory();

};

