#include <iostream>
#include <fstream>

using namespace std;

bool czyZlozona(int liczba) {
    if (liczba <= 1) return false;
    for (int n = 2; n * n <= liczba; n++) {
        if (liczba % n == 0) return true;
    }
    return false;
}

int main() {
    ofstream plik1("liczby.txt");
    ofstream wynik("wynik.txt");

    if (!plik1.is_open()) {
        cerr << "plik nie zostal otwarty" << endl;
        return 1;
    }

    plik1 << "7 16 9 15 20 18 " << endl;
    plik1.close();

    int wybor;

    do {
        cout << "1.parzyste" << endl;
        cout << "2.nieparzyste" << endl;
        cout << "3.zlozone" << endl;
        cin >> wybor;

        switch (wybor) {
            case 1: {
                cout << "" << endl;
                cout << "parzyste" << endl;
                cout << "" << endl;

                ifstream plik1("liczby.txt");
                int liczba;
                while (plik1 >> liczba) {
                    if (liczba % 2 == 0) {
                        wynik << liczba << endl;
                    }
                }
                plik1.close();
                break;
            }
            case 2: {
                cout << "" << endl;
                cout << "nieparzyste" << endl;
                cout << "" << endl;

                ifstream plik1("liczby.txt");
                int liczba2;
                while (plik1 >> liczba2) {
                    if (liczba2 % 2 == 1) {
                        wynik << liczba2 << endl;
                    }
                }
                plik1.close();
                break;
            }
            case 3: {
                cout << "" << endl;
                cout << "zlozone" << endl;
                cout << "" << endl;

                ifstream plik1("liczby.txt");
                int liczba3;
                while (plik1 >> liczba3) {
                    if (czyZlozona(liczba3)) {
                        wynik << liczba3 << endl;
                    }
                }
                break;
            }
            default:
                cout << "" << endl;
                cout << "zly wybor" << endl;
                cout << "" << endl;
                break;
        }
    } while (wybor < 4);

    plik1.close();
    wynik.close();

    return 0;
}
