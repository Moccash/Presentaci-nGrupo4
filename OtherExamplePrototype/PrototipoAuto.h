//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef OTHEREXAMPLEPROTOTYPE_PROTOTIPOAUTO_H
#define OTHEREXAMPLEPROTOTYPE_PROTOTIPOAUTO_H

#include <iostream>
#include <string>
using namespace std;

// Interfaz Prototype
class PrototipoAuto {
public:
    virtual PrototipoAuto* clonarProfundo() const = 0; // Clonación profunda
    virtual PrototipoAuto* clonarSimple() const = 0;   // Clonación simple
    virtual void mostrarInfo() const = 0;
    virtual ~PrototipoAuto() {}
};
#endif //OTHEREXAMPLEPROTOTYPE_PROTOTIPOAUTO_H
