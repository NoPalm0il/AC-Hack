#include "Memory.h"

using namespace std;
Memory::Memory() {
	bytesRead = 0;
	hProcess = NULL;
	PID = 0;
}

BOOL Memory::genPID()
{
	HWND acwindow = FindWindow(0, L"AssaultCube");
	GetWindowThreadProcessId(acwindow, &PID);
	if (PID != 0) {
		cout << PID << endl;
		return true;
	}
	else {
		cerr << "Failed to get PID. Open assault cube!\n";
		return false;
	}
}


void Memory::genHandle() {
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, PID);

	if (hProcess == NULL) {
		cout << "Failed to generate handle! error: " << GetLastError() <<endl;
	}
	cout << "Handle generated.\n";
}

//reads the source pointer to a target pointer (buffer), targetPtr is the data buffer
void Memory::targetRead16(LPCVOID srcptr, LPVOID targetPtr)
{
	if (!ReadProcessMemory(hProcess, srcptr, targetPtr, 2, &bytesRead)) {
		cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
	}
	//cout << "Read " << bytesRead << " Bytes.\n";
}

//reads the source pointer to a target pointer (buffer), targetPtr is the data buffer
void Memory::targetRead32(LPCVOID srcptr, LPVOID targetPtr)
{
	if (!ReadProcessMemory(hProcess, srcptr, targetPtr, 4, &bytesRead)) {
		cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
	}
	//cout << "Read " << bytesRead << " Bytes.\n";
}

//writes to the target pointer the data in the source pointer, srcptr is the data buffer
void Memory::targetWrite16(LPVOID targetPtr, LPCVOID srcptr)
{
	if (!WriteProcessMemory(hProcess, targetPtr, srcptr, 2, &bytesRead)) {
		cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
	}
	//cout << "Wrote " << bytesRead << " Bytes.\n";
}

//writes to the target pointer the data in the source pointer, srcptr is the data buffer
void Memory::targetWrite32(LPVOID targetPtr, LPCVOID srcptr)
{
	if (!WriteProcessMemory(hProcess, targetPtr, srcptr, 4, &bytesRead)) {
		cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
	}
	//cout << "Wrote " << bytesRead << " Bytes.\n";
}

void Memory::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}