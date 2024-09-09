//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_REGISTRODEPROTOTIPOS_H
#define PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_REGISTRODEPROTOTIPOS_H


#include "PrototipoVehiculo.h"
#include "AutoDeportivo.h"
#include "Moto.h"

class RegistroDePrototipos {
private:
    PrototipoVehiculo* autoPrototipo;
    PrototipoVehiculo* motoPrototipo;

public:
    RegistroDePrototipos() {
        // Inicializar prototipos
        autoPrototipo = new AutoDeportivo("Ferrari", "Rojo");
        motoPrototipo = new Moto("Yamaha", 600);
    }

    ~RegistroDePrototipos() {
        delete autoPrototipo;
        delete motoPrototipo;
    }

    PrototipoVehiculo* obtenerAutoPrototipo() const {
        return autoPrototipo->clonar();
    }

    PrototipoVehiculo* obtenerMotoPrototipo() const {
        return motoPrototipo->clonar();
    }
};


#endif //PROTOTYPEEXAMPLEWITHOUTUNOR_MAP_REGISTRODEPROTOTIPOS_H
