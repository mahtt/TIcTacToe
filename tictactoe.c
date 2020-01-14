#include <stdio.h>

#define MAX_RUNDEN 9
#define RUNDE_AB_DER_GEWONNEN_WERDEN_KANN 5


struct spieler {
	char zeichen;
	int nummer;
} spieler1, spieler2;

void fuelleSpielbrett();
void printBrett();
void spielerAmZug();
void setzteSymbol(int reihe, int spalte);
int ueberpruefeObSpielerGewonnenHat();

char spielbrett[3][3];
int runde;
struct spieler aktuellerSpieler;

int main() {
	fuelleSpielbrett();
	spieler1.zeichen = 'X';
	spieler2.zeichen = 'Y';
	spieler1.nummer = 1;
	spieler2.nummer = 2;
	runde = 0;

	while (runde <= MAX_RUNDEN) {
		int reiheAktuellerZug;
		int spalteAktuellerZug;
		runde++;
		spielerAmZug();
		printf("Spieler %d geben Sie die Koordinaten Ihres Zuges im Format REIHE,SPALTE ein: ", aktuellerSpieler.nummer);
		scanf("%d,%d", &reiheAktuellerZug, &spalteAktuellerZug);
		setzteSymbol(reiheAktuellerZug, spalteAktuellerZug);
		printBrett();

		if (runde >= RUNDE_AB_DER_GEWONNEN_WERDEN_KANN) {
			if (ueberpruefeObSpielerGewonnenHat()) {
				printf("Spieler %d hat gewonnen!", aktuellerSpieler.nummer);
				break;
			}
			if (runde == MAX_RUNDEN) {
				printf("Das Spiel ist unentschieden ausgegangen.");
				break;
			}
		}
	}
	return 0;
}

void fuelleSpielbrett() {
	for (int i = 0; i < 3; i++) {
		for (int m = 0; m < 3; m++) {
			spielbrett[i][m] = '.';
		}
	}
}

void printBrett() {
	for (int i = 0; i < 3; i++) {
		for (int m = 0; m < 3; m++) {
			printf("%c", spielbrett[i][m]);
		}
		printf("\n");
	}
}

void spielerAmZug() {
	if (runde % 2 == 0) {
		aktuellerSpieler = spieler2;
	}
	else {
		aktuellerSpieler = spieler1;
	}
}

void setzteSymbol(int reihe, int spalte) {
	spielbrett[reihe][spalte] = aktuellerSpieler.zeichen;
}

int ueberpruefeObSpielerGewonnenHat() {
	int reihe0 = (spielbrett[0][0] == spielbrett[0][1]) && (spielbrett[0][1] == spielbrett[0][2]) && (spielbrett[0][0] != '.');
	int reihe1 = (spielbrett[1][0] == spielbrett[1][1]) && (spielbrett[1][1] == spielbrett[1][2]) && (spielbrett[1][0] != '.');
	int reihe2 = (spielbrett[2][0] == spielbrett[2][1]) && (spielbrett[2][1] == spielbrett[2][2]) && (spielbrett[2][0] != '.');

	int spalte0 = (spielbrett[0][0] == spielbrett[1][0]) && (spielbrett[1][0] == spielbrett[2][0]) && (spielbrett[0][0] != '.');
	int spalte1 = (spielbrett[0][1] == spielbrett[1][1]) && (spielbrett[1][1] == spielbrett[2][1]) && (spielbrett[2][1] != '.');
	int spalte2 = (spielbrett[0][2] == spielbrett[1][2]) && (spielbrett[1][2] == spielbrett[2][2]) && (spielbrett[2][2] != '.');

	int diagonal1 = (spielbrett[2][0] == spielbrett[1][1]) && (spielbrett[1][1] == spielbrett[0][2]) && (spielbrett[0][2] != '.');
	int diagonal2 = (spielbrett[0][0] == spielbrett[1][1]) && (spielbrett[1][1] == spielbrett[2][2]) && (spielbrett[2][2] != '.');

	if (reihe0 | reihe1 | reihe2 | spalte0 | spalte1 | spalte2 | diagonal1 | diagonal2) {
		return 1;
	}
	else {
		return 0;
	}
}