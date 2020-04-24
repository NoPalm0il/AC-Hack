#include <iostream>
#include <Windows.h>
#include <thread>

#include "Memory.h";
#include "Hacks.h";

using namespace std;
int main()
{
	Memory mem;
	while (!mem.genPID());

	mem.genHandle();

	Hacks hck = Hacks(mem);
	

	cout << "Memory ready, hacks loaded.\n";

	thread flythread([mem] {
		Hacks ss = Hacks(mem);

		ss.fly();
		});

	while (1) {
		//cout << "main thread;\n";
		hck.godMode();
		hck.maxAmmo();
		//hck.sanic();

		Sleep(200);
	}

	return 0;
}
