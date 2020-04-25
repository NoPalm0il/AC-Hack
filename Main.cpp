#include <iostream>
#include <Windows.h>
#include <thread>

#include "Memory.h"
#include "Hacks.h"
#include "Console.h"

using namespace std;
int main()
{
	

	/*thread thread1([mem] {
		Hacks ss = Hacks(mem);

		ss.speed();
		});

	thread1.join();
	
	while (1) {
		//cout << "main thread;\n";
		hck.godMode();
		hck.maxAmmo();

		Sleep(200);
	}
	*/

	Console cli;

	cli.startcli();

	return 0;
}
