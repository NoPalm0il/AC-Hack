#pragma once
#include <iostream>
#include <vector>

#include "Memory.h"
#include "Hacks.h"

using namespace std;

class Console
{
private:
	Memory mem;
	string command;
	vector<string> cmds;
	vector<string> hacks;
	bool canHack;

	bool commandChk(string);
	bool hackChk(string);
	void printLogo();
	void printWlcm();
	void presentation();
	void hackcli();

public:
	void startcli();
	void startMem();
	Console();
};

