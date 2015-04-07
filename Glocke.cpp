#include "Glocke.h"
#include <windows.h>

Glocke::Glocke()
{
}

Glocke::~Glocke()
{
}

void Glocke::play(NoteTyp ntyp, NoteDuration ndur, bool dooted){
	pressKey(getNoteHotkey(ntyp), 0);
	releaseKey(getNoteHotkey(ntyp));
	Sleep(getNoteDuration(ndur, getWholeNoteDuration(), dooted));
}

void Glocke::playN(int size, NoteTyp ntyp[], NoteDuration ndur, bool dooted){
	for (int i = 0; i < size / sizeof(ntyp[0]); i++){
		pressKey(getNoteHotkey(ntyp[i]), 0);
		releaseKey(getNoteHotkey(ntyp[i]));
	}
	Sleep(getNoteDuration(ndur, getWholeNoteDuration(), dooted));
}

void Glocke::nTole(NoteTyp ntyp[], int size, NoteDuration ndur){
	int dauer = ((size - 1) * getNoteDuration(ndur, getWholeNoteDuration(), 0)) / getNoteDuration(ndur, getWholeNoteDuration(), 0);
	for (int i = 0; i < size / sizeof(ntyp[0]); i++){
		pressKey(getNoteHotkey(ntyp[i]), 0);
		releaseKey(getNoteHotkey(ntyp[i]));
		Sleep(dauer);
	}
}

void Glocke::pause(NoteDuration ndur){
	Sleep(getNoteDuration(ndur, getWholeNoteDuration(), 0));
}

void Glocke::octaveUp(){
	pressKey(getOctaveUpKey(), 0);
	releaseKey(getOctaveUpKey());
}

void Glocke::octaveDown(){
	pressKey(getOctaveDownKey(), 0);
	releaseKey(getOctaveDownKey());

}
