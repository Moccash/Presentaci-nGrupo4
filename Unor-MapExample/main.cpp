#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> miMapa;

    // Insertar elementos
    miMapa["Juan"] = 25;
    miMapa["Maria"] = 30;
    miMapa["Pedro"] = 28;

    // Acceder a elementos
    cout << "La edad de Juan es: " << miMapa["Juan"] << endl;

    // Comprobar si una clave existe
    if (miMapa.find("Maria") != miMapa.end()) {
        cout << "Maria está en el mapa con edad " << miMapa["Maria"] << endl;
    }

    // Iterar sobre los elementos
    for (const auto& par : miMapa) {
        cout << par.first << " tiene " << par.second << " años." << endl;
    }

    return 0;
}
