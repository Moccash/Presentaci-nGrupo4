//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLE_DOCUMENTO_H
#define PROTOTYPEEXAMPLE_DOCUMENTO_H
#include <string>
#include <iostream>

class Documento {
public:
    virtual Documento* clonar() const = 0; // Método de clonación
    virtual void mostrarInfo() const = 0;  // Mostrar información
    virtual ~Documento() {}
};

#endif //PROTOTYPEEXAMPLE_DOCUMENTO_H
