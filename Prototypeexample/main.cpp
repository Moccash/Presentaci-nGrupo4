#include "DocumentoPDF.h"
#include "DocumentoWord.h"
#include "DocumentoExcel.h"
#include "RegistroDeDocumentos.h"

int main() {
    // Crear el registro de documentos
    RegistroDeDocumentos registro;

    // Crear documentos prototípicos y agregarlos al registro
    Documento* pdf = new DocumentoPDF("Manual de Usuario");
    Documento* word = new DocumentoWord("Informe de Proyecto", 25);
    Documento* excel = new DocumentoExcel("Presupuesto", 100);

    registro.agregarPrototipo("pdf", pdf);
    registro.agregarPrototipo("word", word);
    registro.agregarPrototipo("excel", excel);

    // Obtener clones a partir del registro
    Documento* pdfClonado = registro.obtenerPrototipo("pdf");
    Documento* wordClonado = registro.obtenerPrototipo("word");
    Documento* excelClonado = registro.obtenerPrototipo("excel");

    // Mostrar información de los clones
    pdfClonado->mostrarInfo();
    wordClonado->mostrarInfo();
    excelClonado->mostrarInfo();

    // Liberar memoria
    delete pdf;
    delete word;
    delete excel;
    delete pdfClonado;
    delete wordClonado;
    delete excelClonado;

    return 0;
}
