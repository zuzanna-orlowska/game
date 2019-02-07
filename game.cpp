//POP_2017_12_21_projekt_1_Or³owska_Zuzanna_EiT_2_171835
//Code::Blocks, TDM-GCC Compiler Suite for Windows, GCC 4.9 Series, Standard MinGW 32-bit Edition

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;
//rozmiar tablicy
const int MAX_X = 10; //x to wiersze
const int MAX_Y = 10; //y to kolumny

struct nazwa {  //pojedyncza struktura
	char pionek;
	bool flaga;
};

struct gra {
	nazwa **G;  //tablica dwuwymiarowa struktur
};

int main()
{//deklaracja zmiennych
	nazwa G[MAX_X][MAX_Y];
	char lis = 'L';
	char chart = 'C';
	char spacja = ' ';
	int x = 0, y = 0, v, z, a, c, zmienna_1 = 0, zmienna_2 = 0, m, n, o , p;
	char b, d;
	srand(time(NULL)^ clock());

	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
	cout << "********                 ********" << endl;
	cout << "********  Witaj w grze!  ********" << endl;
	cout << "********                 ********" << endl;
	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
	cout << "*********************************" << endl << endl;

	system("PAUSE");
	system("CLS");
    //tworzenie tablicy
	for (int i = 0; i<MAX_X; i++) {
		for (int j = 0; j<MAX_Y; j++){
			if (i == 0 && (j == 3 || j == 5))
				G[i][j].pionek = 'L';
			else if (j % 2 == 0 && (i == 7 || i == 9))
				G[i][j].pionek = 'C';
			else if (j % 2 == 1 && (i == 6 || i == 8))
				G[i][j].pionek = 'C';
			else G[i][j].pionek = ' ';
		}
	}
    //glowna petla programu
    do {
    //czyszczenie planszy
        system("CLS");
	//petla okreslajaca ruch lisow
		do {
        zmienna_2 = 0;
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                if (G[i][j].pionek == lis){
                    if (( G[i+1][j+1].pionek == chart && G[i-1][j+1].pionek == chart && G[i+1][j-1].pionek == chart && G[i-1][j-1].pionek == chart ) || (G[9][0].pionek == lis && G[8][1].pionek == chart)||
                    G[0][j].pionek == lis && (G[1][j+1].pionek == chart && G[1][j-1].pionek == chart)||
                    G[i][0].pionek == lis && (G[i+1][1].pionek == chart && G[i-1][1].pionek == chart)||
                    G[i][9].pionek == lis && (G[i+1][8].pionek == chart && G[i-1][8].pionek == chart)){
                        zmienna_2++;
                    }
                }
            }
        }
        if (zmienna_2 == 2 ){
            for (int i = 0; i<10; i++) {
                if (i == 0) {
                    cout << 10 << "|";
                }
                else {
                    cout << 10 - i << " |";
                }
                for (int j = 0; j<10; j++) {
                    cout << G[i][j].pionek << "|";
                }
                cout << endl;
            }
		cout << "   A B C D E F G H I J" << endl << endl;
		cout << "Gracz 1. wykonal ruch" << endl;
		cout << "Gra skonczona" << endl;
        cout << "Wygrywasz" << endl;
        system("pause");
        return 0;
        }
			do {
                //generowanie losowych wspolrzednych
				m = (rand() % 10);
				n = (rand() % 10);
			} while (G[m][n].pionek != lis || (G[m][n].pionek == lis && G[m+1][n+1].pionek != spacja && G[m+1][n-1].pionek != spacja && G[m-1][n+1].pionek != spacja && G[m-1][n-1].pionek != spacja) ||
                (G[0][n].pionek == lis && G[m + 1][n + 1].pionek != spacja && G[m + 1][n - 1].pionek != spacja) ||
                (G[m][0].pionek == lis && G[m + 1][n + 1].pionek != spacja && G[m - 1][n + 1].pionek != spacja) ||
                (G[m][9].pionek == lis && G[m + 1][n - 1].pionek != spacja && G[m - 1][n - 1].pionek != spacja));

            zmienna_2 = 0;

            o = (rand() % 10);
			p = (rand() % 10);

            //L daza do przeciwnego konca planszy
            if (o < m){
                if (G[m+1][n+1].pionek == spacja || G[m+1][n-1].pionek == spacja){
                    zmienna_2 = 1;
                }
            }
			//L nie moga zamienic sie polami ze soba lub z C
			if (G[o][p].pionek != spacja) {
				zmienna_2 = 1;
			}
            //L poruszaja sie po skosie
			if ((o % 2 == 0 && p % 2 == 0) || (o % 2 == 1 && p % 2 == 1)) {
				zmienna_2 = 1;
			}
            //L poruszaja sie po skosie
			if (m == o || n == p) {
				zmienna_2 = 1;
			}
            //L poruszaja sie po skosie
			if (abs(m-o) != abs(n-p))  {
				zmienna_2 = 1;
			}
            //L nie moga przeskakiwac przez C
			if (o > m && p > n) {
				for (int i = m + 1; i<o; i++) {
					for (int j = n + 1; j<p; j++) {
						if (G[i][j].pionek == chart) {
							zmienna_2 = 1;
						}
					}
				}
			}
            //L nie moga przeskakiwac przez C
			else if (o < m && p > n) {
				for (int i = m; i>o; i--) {
					for (int j = n + 1; j<p; j++) {
						if (G[i][j].pionek == chart) {
							zmienna_2 = 1;
						}
					}
				}
			}
            //L nie moga przeskakiwac przez C
			else if (o < m && p < n) {
				for (int i = m; i>o; i--) {
					for (int j = n; j>p; j--) {
						if (G[i][j].pionek == chart) {
							zmienna_2 = 1;
						}
					}
				}
			}
            //L nie moga przeskakiwac przez C
			else if (o > m && p < n) {
				for (int i = m + 1; i<o; i++) {
					for (int j = n; j>p; j--) {
						if (G[i][j].pionek == chart) {
							zmienna_2 = 1;
						}
					}
				}
			}

    } while (zmienna_2 == 1);
        //zamiana pol
		swap(G[m][n].pionek, G[o][p].pionek);
        //warunek konca gry
		for (int i = 0; i<10; i++) {
			if (G[9][i].pionek == lis) {
                for (int i = 0; i<10; i++) {
                    if (i == 0) {
                        cout << 10 << "|";
                    }
                    else {
                        cout << 10 - i << " |";
                    }
                for (int j = 0; j<10; j++) {
                    cout << G[i][j].pionek << "|";
                }
                cout << endl;
                }
                cout << "   A B C D E F G H I J" << endl << endl;
                cout << "Przegrywasz" << endl;
                system("PAUSE");
                return 0;
			}
		}
		//wyswietlanie stanu planszy
		for (int i = 0; i<10; i++) {
			if (i == 0) {
				cout << 10 << "|";
			}
			else {
				cout << 10 - i << " |";
			}
			for (int j = 0; j<10; j++) {
				cout << G[i][j].pionek << "|";
			}
			cout << endl;
		}
		cout << "   A B C D E F G H I J" << endl << endl;
		cout << "Gracz 1. wykonal ruch" << endl;
		cout << "Teraz gra gracz 2. (ty)" << endl << endl;
        //petla okreslajaca ruch uzytkownika programu
		do {
            cout << "Podaj wspolrzedne pola twojego pionka (cyfra litera): " << endl;
			cin >> a >> b;
			//uzycie tablicy ASCII do zamiany podanych wspolrzednych na faktyczne wspolrzedne utworzonej na poczatku tablicy
			switch (a) {
			case 10: x = 0; break;
			case 9: x = 1; break;
			case 8: x = 2; break;
			case 7: x = 3; break;
			case 6: x = 4; break;
			case 5: x = 5; break;
			case 4: x = 6; break;
			case 3: x = 7; break;
			case 2: x = 8; break;
			case 1: x = 9; break;
			}

			switch (b) {
			case 'A': y = b - 65; break;
			case 'B': y = b - 65; break;
			case 'C': y = b - 65; break;
			case 'D': y = b - 65; break;
			case 'E': y = b - 65; break;
			case 'F': y = b - 65; break;
			case 'G': y = b - 65; break;
			case 'H': y = b - 65; break;
			case 'I': y = b - 65; break;
			case 'J': y = b - 65; break;
			}

			if (x>9 || x<0 || G[x][y].pionek != chart || y>9 || y<0 ||
            (G[x+1][y+1].pionek != spacja && G[x+1][y-1].pionek != spacja && G[x-1][y+1].pionek != spacja && G[x-1][y-1].pionek != spacja)) {
				cout << "Nie mozesz wybrac takiego pola" << endl;
			}
		} while (x>9 || x<0 || G[x][y].pionek != chart || y>9 || y<0 ||
            (G[x+1][y+1].pionek != spacja && G[x+1][y-1].pionek != spacja && G[x-1][y+1].pionek != spacja && G[x-1][y-1].pionek != spacja));

		do {
			zmienna_1 = 1; //zmienna potrzebna do wyjscia z petli i rozpoznawania konca gry
			cout << "Podaj wspolrzedne pola na ktore chcesz przeniesc pionek (cyfra litera): " << endl;
			cin >> c >> d;

			switch (c) {
			case 10: v = 0; break;
			case 9: v = 1; break;
			case 8: v = 2; break;
			case 7: v = 3; break;
			case 6: v = 4; break;
			case 5: v = 5; break;
			case 4: v = 6; break;
			case 3: v = 7; break;
			case 2: v = 8; break;
			case 1: v = 9; break;
			}
			switch (d) {
			case 'A': z = d - 65; break;
			case 'B': z = d - 65; break;
			case 'C': z = d - 65; break;
			case 'D': z = d - 65; break;
			case 'E': z = d - 65; break;
			case 'F': z = d - 65; break;
			case 'G': z = d - 65; break;
			case 'H': z = d - 65; break;
			case 'I': z = d - 65; break;
			case 'J': z = d - 65; break;
			}
            //uzycie flagi do zaznaczenia momentu, w ktorym pionek C dotarl do konca planszy
			if (G[x][y].pionek == chart && x == 0) {
				G[x][y].flaga = true;
			}

			if (G[x][y].flaga == false) {
				if (v>x || v>9 || v<0 || G[v][z].pionek != spacja || z>9 || z<0 || v>x + 1 || z>y + 1 || z<y - 1 || v<x - 1 || c == a || d == b){
					cout << "Nie mozesz wybrac takiego pola" << endl;
					zmienna_1 = 0;
				}
			}
			else if (G[x][y].flaga == true) {
				if (v<x || v>9 || v<0 || G[v][z].pionek != spacja || z>9 || z<0 || v>x + 1 || z>y + 1 || z<y - 1 || v<x - 1 || c == a || d == b){
					cout << "Nie mozesz wybrac takiego pola" << endl;
					zmienna_1 = 0;
				}
			}
		} while (zmienna_1 == 0);
        //zamiana pol
		swap(G[x][y].pionek, G[v][z].pionek);
		swap(G[x][y].flaga, G[v][z].flaga);

	} while (zmienna_2 != 3);
	return 0;
}
