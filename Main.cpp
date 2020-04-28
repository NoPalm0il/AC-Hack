#include <iostream>
#include <Windows.h>
#include <thread>

#include "Memory.h"
#include "Hacks.h"
#include "Console.h"

using namespace std;
int main()
{
	
	Console cli;

	while (true) {
		cli.startcli();


		Hacks hks = Hacks(cli.mem);
		std::thread godtd([&hks]() {
			hks.godMode();
			});
	}

	return 0;
}
