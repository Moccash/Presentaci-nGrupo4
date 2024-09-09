//
// Created by LenovoE450 on 9/9/2024.
//

#ifndef PROTOTYPEEXAMPLE_DOCUMENTOWORD_H
#define PROTOTYPEEXAMPLE_DOCUMENTOWORD_H

#include "Documento.h"

class DocumentoWord : public Documento {
private:
    std::string titulo;
    int numeroDePaginas;
public:
    DocumentoWord(const std::string& titulo, int numeroDePaginas)
            : titulo(titulo), numeroDePaginas(numeroDePaginas) {}

    DocumentoWord(const DocumentoWord& otroWord)
            : titulo(otroWord.titulo), numeroDePaginas(otroWord.numeroDePaginas) {}

    Documento* clonar() const override {
        return new DocumentoWord(*this);  // Clonación de Word
    }

    void mostrarInfo() const override {
        std::cout << "Documento Word - Titulo: " << titulo << ", Paginas: " << numeroDePaginas << std::endl;
    }
};


#endif //PROTOTYPEEXAMPLE_DOCUMENTOWORD_H
