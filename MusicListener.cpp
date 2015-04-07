#include "MusicListener.h"
#include <iostream>
#include <windows.h>

using namespace std;

int getScanCode(int virtualCode){
	return	MapVirtualKey(virtualCode, 0);
}

int getOctaveUpKey(){ return 34; };

int getOctaveDownKey(){ return 18; };

int getNoteHotkey(NoteTyp n){ 
	switch (n){
		case C:
			return 2;
			break;
		case D:
			return 3;
			break;
		case E:
			return 4;
			break;
		case F:
			return 5;
			break;
		case G:
			return 6;
			break;
		case A:
			return 7;
			break;
		case H:
			return 8;
			break;
		default:
			return -1;
			break;
	}
};

int getWholeNoteDuration(){ return 2000; };


void pressKey(int key, int sleepTime){
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = key; // hardware scan code for key
	ip.ki.time = sleepTime;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0; // virtual-key code for the "a" key
	ip.ki.dwFlags = KEYEVENTF_SCANCODE; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));
}

void releaseKey(int key){
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = key; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0; // virtual-key code for the "a" key
	ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));

}

int getNoteDuration(NoteDuration nd, int zeitdauer, bool dotted){
	int result;
	switch (nd){
		case Whole:
			result = zeitdauer;
			break;
		case Half:
			result = (zeitdauer + (2 / 2)) / 2;
			break;
		case Quarter:
			result = (zeitdauer + (4 / 2)) / 4;
			break;
		case Eighth:
			result = (zeitdauer + (8 / 2)) / 8;
			break;
		case Sixteenth:
			result = (zeitdauer + (16 / 2)) / 16;
			break;
		case Thirtysecond:
			result = (zeitdauer + (32 / 2)) / 32;
			break;
		default:
			return 0;
			break;
	}
	if (dotted){
		return (int)(result * 1.5);
	}
	else{
		return result;
	}
};

	//for (int i = 0; i < (sizeof(key) / sizeof(key[0])); i++){
	//	INPUT ip;
	//	ip.type = INPUT_KEYBOARD;
	//	ip.ki.wScan = key[i]; // hardware scan code for key
	//	ip.ki.time = 0;
	//	ip.ki.dwExtraInfo = 0;
	//	ip.ki.wVk = 0; // virtual-key code for the "a" key
	//	ip.ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_SCANCODE; // KEYEVENTF_KEYUP for key release
	//	SendInput(1, &ip, sizeof(INPUT));
	//}

