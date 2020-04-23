#include <iostream>
#include <Windows.h>
#include <string>

#define CHAR_ARRAY_SIZE 128

using namespace std;
int main()
{
	int varInt = 123456;
	int* ptr2int(&varInt);
	int** ptr2ptr(&ptr2int);
	int*** ptr2ptr2(&ptr2ptr);

	int intRead = 0;
	SIZE_T bytesRead = 0;
	int intWrite = 69;


	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
	if (hProcess == NULL) { // Failed to get a handle
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "Process opened, handle created!\n";

	//intRead = varInt
	if (!ReadProcessMemory(hProcess, (LPCVOID)&varInt, &intRead, sizeof(int), &bytesRead)) {
		cout << "ReadProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "Read successfull!\n" << "varInt = " << varInt << " | intRead = " << intRead << endl;

	//varInt = intWrite
	if (!WriteProcessMemory(hProcess, &varInt, (LPCVOID)&intWrite, sizeof(int), &bytesRead)) {
		cout << "WriteProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "varInt = " << varInt;

	return 0;
}

int startRead() {

	//HWND hwndAC_Client = FindWindow(0, "AssaultCube");

	return 0;
}

