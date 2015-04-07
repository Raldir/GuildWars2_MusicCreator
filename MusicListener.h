#define MUSICLISTENER_H

int main();

enum NoteDuration { Whole, Half, Quarter, Eighth, Sixteenth, Thirtysecond };
enum NoteTyp { C, D, E, F, G, A, H, CSharp };

int getNoteHotkey(NoteTyp);

int getScanCode(int);

int getNoteDuration(NoteDuration, int, bool);

int getWholeNoteDuration();

int getOctaveUpKey();

int getOctaveDownKey();

void pressKey(int, int);

void releaseKey(int);

class Instrument{

	public: 
		virtual void play(NoteTyp, NoteDuration){};
		virtual void playN(NoteTyp, NoteDuration){};
		virtual void pause(NoteDuration){};
		virtual void octaveUp(){};
		virtual void octaveDown(){};
		virtual void nTole(NoteTyp*, int, NoteDuration){};
		void stop(){};
};


class MusicListener{
public: MusicListener();

};