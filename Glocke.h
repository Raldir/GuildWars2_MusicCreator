#pragma once
#include "MusicListener.h"

class Glocke : public Instrument{

public:
	void play(NoteTyp, NoteDuration, bool);
	void playN(int, NoteTyp*, NoteDuration, bool);
	void pause(NoteDuration);
	void octaveUp();
	void octaveDown();
	void nTole(NoteTyp*, int, NoteDuration);
	Glocke();
	~Glocke();
};

