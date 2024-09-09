//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_AUTODEPORTIVO_H
#define PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_AUTODEPORTIVO_H


#include "PrototipoVehiculo.h"
#include <iostream>
#include <string>

class AutoDeportivo : public PrototipoVehiculo {
private:
    std::string marca;
    std::string color;
public:
    // Constructor normal
    AutoDeportivo(const std::string& marca, const std::string& color)
            : marca(marca), color(color) {}

    // Constructor de copia
    AutoDeportivo(const AutoDeportivo& otroAuto)
            : marca(otroAuto.marca), color(otroAuto.color) {}

    // Implementación del método clonar
    PrototipoVehiculo* clonar() const override {
        return new AutoDeportivo(*this);  // Clonación
    }

    void mostrarInfo() const override {
        std::cout << "Auto Deportivo - Marca: " << marca << ", Color: " << color << std::endl;
    }
};


#endif //PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_AUTODEPORTIVO_H
