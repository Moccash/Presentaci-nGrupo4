//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef OTHEREXAMPLEPROTOTYPE_AUTODEPORTIVO_H
#define OTHEREXAMPLEPROTOTYPE_AUTODEPORTIVO_H

#include "PrototipoAuto.h"

// Clase concreta AutoDeportivo
class AutoDeportivo : public PrototipoAuto {
private:
    string* color;
    string modelo;
public:
    AutoDeportivo(const string& modelo, const string& color) : modelo(modelo) {
        this->color = new string(color);
    }

    // Clonación profunda (nueva instancia de todos los datos)
    PrototipoAuto* clonarProfundo() const override {
        return new AutoDeportivo(modelo, *color);  // Crea una copia independiente
    }

    // Clonación simple (comparte la referencia de color)
    PrototipoAuto* clonarSimple() const override {
        AutoDeportivo* clonSimple = new AutoDeportivo(modelo, *color);
        clonSimple->color = this->color;  // Comparte la referencia al color
        return clonSimple;
    }

    // Mostrar información del auto
    void mostrarInfo() const override {
        cout << "Auto Deportivo - Modelo: " << modelo << ", Color: " << *color
             << ", Direccion de color: " << color << endl;
    }

    // Destructor
    ~AutoDeportivo() {
        delete color;
    }
};


#endif //OTHEREXAMPLEPROTOTYPE_AUTODEPORTIVO_H
