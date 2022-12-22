#include <iostream>
#include <string>
using namespace std;

void berechne(int n) {
    cout << "Teiler von " << n << " sind:\n";
    for (int teiler = 1; teiler <= n; ++teiler) {
        if (n % teiler == 0) {
            cout << teiler << ", ";
        }
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    int wert = 0;
    if (argc <= 1) {
        cout << "Geben Sie eine Zahl ein: ";
        cin >> wert;
        if (!cin) {
            return 1;
        }
    } else {
        wert = stoi(argv[1]);
    }
    berechne(wert);
    return 0;
}