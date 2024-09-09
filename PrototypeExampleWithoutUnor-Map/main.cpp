#include "RegistroDePrototipos.h"

int main() {
    // Crear el registro de prototipos
    RegistroDePrototipos registro;

    // Clonar un auto deportivo y una moto
    PrototipoVehiculo* autoClonado = registro.obtenerAutoPrototipo();
    PrototipoVehiculo* motoClonada = registro.obtenerMotoPrototipo();

    // Mostrar la información de los clones
    autoClonado->mostrarInfo();
    motoClonada->mostrarInfo();

    // Liberar memoria
    delete autoClonado;
    delete motoClonada;

    return 0;
}
