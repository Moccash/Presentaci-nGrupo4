//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLE_REGISTRODEDOCUMENTOS_H
#define PROTOTYPEEXAMPLE_REGISTRODEDOCUMENTOS_H

#include "Documento.h"
#include <unordered_map>
#include <string>

class RegistroDeDocumentos {
private:
    std::unordered_map<std::string, Documento*> catalogo;

public:
    void agregarPrototipo(const std::string& clave, Documento* documento) {
        catalogo[clave] = documento;
    }

    Documento* obtenerPrototipo(const std::string& clave) {
        if (catalogo.find(clave) != catalogo.end()) {
            return catalogo[clave]->clonar();  // Clonar y devolver el prototipo
        }
        return nullptr;
    }

    ~RegistroDeDocumentos() {
        for (auto& par : catalogo) {
            delete par.second;  // Liberar memoria de los prototipos
        }
    }
};



#endif //PROTOTYPEEXAMPLE_REGISTRODEDOCUMENTOS_H
