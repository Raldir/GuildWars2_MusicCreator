#include <iostream>
#include <windows.h>
#include "Glocke.h"

using namespace std;

int main()
{
	int abfrage;
	cout << "Wollen Sie starten? " << endl;
	cout << "<1> ja oder <2> nein(zum beenden)" << endl;
	Glocke g;
	cin >> abfrage;
	cin.get();
	switch (abfrage){
	case 1:
		Sleep(5000);
		g.play(G, Half, 1);

		g.play(C, Half, 1);

		g.play(E, Eighth, 0);
		g.play(F, Eighth, 0);
		g.play(G, Half, 0);

		g.play(C, Half, 0);
		g.play(E, Eighth, 0);
		g.play(F, Eighth, 0);

		g.play(D, Half, 1);
		g.play(D, Half, 1);
		g.play(D, Half, 1);
		g.play(D, Half, 1);

		g.play(F, Half, 1);

		g.octaveDown();
		g.play(H, Half, 1);
		g.octaveUp();
		g.play(D, Eighth, 0);
		g.play(E, Eighth, 0);
		g.play(F, Half, 0);

		g.octaveDown();
		g.play(H, Half, 1);
		g.octaveUp();
		g.play(E, Eighth, 0);
		g.play(D, Eighth, 0);

		g.play(C, Half, 1);
		g.play(C, Half, 1);
		g.play(C, Half, 1);
		g.play(C, Half, 1);

		g.octaveUp();

		g.play(G, Half, 1);
		g.play(C, Half, 1);

		g.play(E, Eighth, 0);
		g.play(F, Eighth, 0);
		g.play(G, Eighth, 0);

		g.play(C, Half, 0);
		break;
	default:
		return 0;
		break;
	}
	main();
}