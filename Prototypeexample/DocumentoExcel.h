//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLE_DOCUMENTOEXCEL_H
#define PROTOTYPEEXAMPLE_DOCUMENTOEXCEL_H

#include "Documento.h"

class DocumentoExcel : public Documento {
private:
    std::string hojaActual;
    int numeroDeFilas;
public:
    DocumentoExcel(const std::string& hojaActual, int numeroDeFilas)
            : hojaActual(hojaActual), numeroDeFilas(numeroDeFilas) {}

    DocumentoExcel(const DocumentoExcel& otroExcel)
            : hojaActual(otroExcel.hojaActual), numeroDeFilas(otroExcel.numeroDeFilas) {}

    Documento* clonar() const override {
        return new DocumentoExcel(*this);  // Clonación de Excel
    }

    void mostrarInfo() const override {
        std::cout << "Documento Excel - Hoja: " << hojaActual << ", Filas: " << numeroDeFilas << std::endl;
    }
};


#endif //PROTOTYPEEXAMPLE_DOCUMENTOEXCEL_H
