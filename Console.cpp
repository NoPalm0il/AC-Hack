#include "Console.h"


Console::Console()
{
	command = "";
	canHack = false;

	mem = Memory();

	cmds.push_back("help");
	cmds.push_back("hacks");
	cmds.push_back("hack");
	cmds.push_back("START");
	cmds.push_back("restart");
	cmds.push_back("EXIT");
	cmds.push_back("clear");

	hacks.push_back("godMode");
	hacks.push_back("maxAmmo");
	hacks.push_back("speed");
	//hacks.push_back("");
}


bool Console::commandChk(string str)
{
	for (string strchk : cmds) {
		if (strchk == str)
			return true;
	}

	return false;
}

bool Console::hackChk(string str)
{
	for (string strchk : hacks) {
		if (strchk == str)
			return true;
	}

	return false;
}

void Console::startcli()
{
	while (true)
	{
		//\033 esc mode to print color [0;32 is formated for [background; text color/foreground add m in the final
		//\033[0;32m
		cout << "\033[0;32mAChack\033[0;35m32\033[0;33m > \033[0m";
		cin >> command;
		if (command == "")
			cout << "AChack32 > ";
		if (commandChk(command)) {
			if (command == "help") {
				cout << "Showing avaiable commands: \n";
				cout << "First thing is to execute START or is not possible to hack\n";
				cout << endl;

				for (string str : cmds) {
					if (str == "hacks") {
						string comp = " \"shows avaiable hacks\"";
						cout << str << comp << endl;
					}
					else if (str == "hack") {
						string comp = " \"enters hack cli\"";
						cout << str << comp << endl;
					}
					else if (str == "START") {
						string comp = " \"Type this command when game is open or no hacking\"";
						cout << str << comp << endl;
					}
					else if (str == "restart") {
						string comp = " \"restarts the program if something goes wrong\"";
						cout << str << comp << endl;
					}
					else if (str == "EXIT") {
						string comp = " \"kills process, exits program\"";
						cout << str << comp << endl;
					}
					else if (str == "clear") {
						string comp = " \"clears screen\"";
						cout << str << comp << endl;
					}
				}
				cout << endl;
			}
			else if (command == "hacks") {
				cout << "Showing avaiable hacks:\n\n";
				for (string str : hacks)
					cout << str << endl;
			}
			else if (command == "hack") {
				if (canHack)
					hackcli();
				else
					cout << "cannot start hacking.\n";
			}
			else if (command == "restart") {
				startMem();
			}
			else if (command == "START") {
				startMem();
			}
			else if (command == "EXIT") {
				exit(0);
			}
			else if (command == "clear") {
				startMem();
			}
		}
		else {
			cerr << "command not found\n\n";
		}
	}
}

void Console::startMem() {
	//while game is not open
	if (mem.genPID()) {
		cout << "pid retrieved.\n";
		//creates process Handle
		if (mem.genHandle() != NULL) {
			canHack = true;
			cout << "handle created\n";
		}
		else
			cout << "failed to create handle\n";
	}

	cout << "failed to retrieve pid.\n";
}


void Console::hackcli() {
	cout << "Hack cli started type exit to leave hackcli\n";
	while (true) {
		cout << "\033[0;31mAChackCLI\033[0;35m > \033[0m";
		cin >> command;

		if (hackChk(command)) {

		}
		else
			cout << "enter a correct hack\n";
	}
}


void Console::printLogo() 
{
	cout << endl;
	cout << "   ########################################" << endl;
	cout << "   #                                      #" << endl;
	cout << "   #   ############      ############     #" << endl;
	cout << "   #   ##         ##     ##         ##    #" << endl;
	cout << "   #   ##          ##    ##          ##   #" << endl;
	cout << "   #   ##           #    ##           #   #" << endl;
	cout << "   #   ##       ####     ##       ####    #" << endl;
	cout << "   #   ##    ######      ##    ######     #" << endl;
	cout << "   #   ##      ##        ##      ##       #" << endl;
	cout << "   #   ##       ##       ##       ##      #" << endl;
	cout << "   #   ##        ##      ##        ##     #" << endl;
	cout << "   #   ##         ##     ##         ##    #" << endl;
	cout << "   #                                      #" << endl;
	cout << "   ########################################" << endl;
}

void Console::printWlcm()
{
	cout << endl;
	cout << "   #-----------------------------------------------------------#" << endl;
	cout << "   |  &       &  &&&&&&  &      &&&&   &&&&   &     &  &&&&&&  |" << endl;
	cout << "   |  &   &   &  &&&     &     &      &    &  & & & &  &&&     |" << endl;
	cout << "   |   & & & &   &&&&    &     &      &    &  &  &  &  &&&&    |" << endl;
	cout << "   |    &   &    &&&&&&  &&&&   &&&&   &&&&   &     &  &&&&&&  |" << endl;
	cout << "   #-----------------------------------------------------------#" << endl << endl;
}

void Console::presentation() {
	mem.ShowConsoleCursor(false);
	printLogo();
	Sleep(1500);
	system("CLS");
	printWlcm();
	Sleep(1000);


	cout << "SUPA HACKA MAN COPY RIGHT NIGGER WATCHA MAN WAKANDA\n";
	cout << "Type help to see avaiable commands.\n\n";

	mem.ShowConsoleCursor(true);
}
