//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLE_DOCUMENTOPDF_H
#define PROTOTYPEEXAMPLE_DOCUMENTOPDF_H


#include "Documento.h"

class DocumentoPDF : public Documento {
private:
    std::string contenido;
public:
    DocumentoPDF(const std::string& contenido) : contenido(contenido) {}

    // Constructor de copia
    DocumentoPDF(const DocumentoPDF& otroPDF) : contenido(otroPDF.contenido) {}

    Documento* clonar() const override {
        return new DocumentoPDF(*this);  // Clonación del PDF
    }

    void mostrarInfo() const override {
        std::cout << "Documento PDF - Contenido: " << contenido << std::endl;
    }
};


#endif //PROTOTYPEEXAMPLE_DOCUMENTOPDF_H
