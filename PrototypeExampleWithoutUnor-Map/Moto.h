//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_MOTO_H
#define PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_MOTO_H


#include "PrototipoVehiculo.h"
#include <iostream>
#include <string>

class Moto : public PrototipoVehiculo {
private:
    std::string marca;
    int cilindrada;
public:
    // Constructor normal
    Moto(const std::string& marca, int cilindrada)
            : marca(marca), cilindrada(cilindrada) {}

    // Constructor de copia
    Moto(const Moto& otraMoto)
            : marca(otraMoto.marca), cilindrada(otraMoto.cilindrada) {}

    // Implementación del método clonar
    PrototipoVehiculo* clonar() const override {
        return new Moto(*this);  // Clonación
    }

    void mostrarInfo() const override {
        std::cout << "Moto - Marca: " << marca << ", Cilindrada: " << cilindrada << " cc" << std::endl;
    }
};


#endif //PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_MOTO_H
