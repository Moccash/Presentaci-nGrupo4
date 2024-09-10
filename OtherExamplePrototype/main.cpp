#include "AutoDeportivo.h"

int main() {
    // Crear el prototipo original
    AutoDeportivo* autoDeportivoOriginal = new AutoDeportivo("Ferrari", "Rojo");

    // Clonar profundamente el auto deportivo
    AutoDeportivo* autoDeportivoClonadoProfundo = dynamic_cast<AutoDeportivo*>(autoDeportivoOriginal->clonarProfundo());

    // Clonar de manera simple (comparten el color)
    AutoDeportivo* autoDeportivoClonadoSimple = dynamic_cast<AutoDeportivo*>(autoDeportivoOriginal->clonarSimple());

    // Mostrar información de los objetos y sus direcciones de memoria
    cout << "Original:" << endl;
    autoDeportivoOriginal->mostrarInfo();

    cout << "\nClonado profundamente:" << endl;
    autoDeportivoClonadoProfundo->mostrarInfo();

    cout << "\nClonado simple (comparten color):" << endl;
    autoDeportivoClonadoSimple->mostrarInfo();

    // Liberar memoria
    delete autoDeportivoOriginal;
    delete autoDeportivoClonadoProfundo;
    delete autoDeportivoClonadoSimple;

    return 0;
}
