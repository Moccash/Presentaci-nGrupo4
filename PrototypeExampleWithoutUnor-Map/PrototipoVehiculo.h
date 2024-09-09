//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_PROTOTIPOVEHICULO_H
#define PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_PROTOTIPOVEHICULO_H
class PrototipoVehiculo {
public:
    virtual PrototipoVehiculo* clonar() const = 0;  // Método de clonación
    virtual void mostrarInfo() const = 0;           // Mostrar información
    virtual ~PrototipoVehiculo() {}
};
#endif //PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_PROTOTIPOVEHICULO_H
