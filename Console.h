#pragma once
#include <iostream>
#include <vector>

#include "Memory.h"
#include "Hacks.h"
#include "Hack.h"

using namespace std;

class Console
{
private:
	Memory mem;
	string command;
	vector<string> cmds;
	vector<Hack> hacksvtr;
	bool canHack;

	bool commandChk(string);
	bool hackChk(string);
	void printLogo();
	void printWlcm();
	void presentation();
	void hackcli();

	void godModeHck();

public:
	void startcli();
	void startMem();
	Console();
};

