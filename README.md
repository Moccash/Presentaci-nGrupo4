<1> 

PrototypeExample - Explicación del código:
Prototipo Documento: Interfaz que declara el método clonar() para todos los documentos.
Clases concretas: Cada clase de documento (DocumentoPDF, DocumentoWord, DocumentoExcel) sobrescribe el método clonar() y utiliza un constructor alternativo para copiar los atributos del documento.
Registro de documentos: Gestiona el almacenamiento de prototipos y permite obtener copias clonadas de ellos.
Cliente: En el main(), se clonan los documentos a través del registro de prototipos y se muestran sus detalles.
Este ejemplo más complejo añade una mayor variedad de clases y un sistema centralizado de registro que puede ser reutilizado en diferentes situaciones.
____________________________________________________________________________________________________________________________________________________________________________________________

<2>

PrototypeExampleWithoutUnor-Map - Explicación del código:
Interfaz PrototipoVehiculo: Define la interfaz común para todos los vehículos, con el método clonar() y mostrarInfo().
Clases concretas AutoDeportivo y Moto: Implementan el método clonar() para permitir la clonación de vehículos específicos.
Clase RegistroDePrototipos: En lugar de usar un unordered_map, simplemente almacena punteros a los prototipos de AutoDeportivo y Moto. Los clientes pueden pedir un clon de estos prototipos directamente.
Cliente (main.cpp): Solicita clones de los prototipos y los utiliza como nuevos objetos.

Salida esperada:
Auto Deportivo - Marca: Ferrari, Color: Rojo
Moto - Marca: Yamaha, Cilindrada: 600 cc

Beneficios de este enfoque:
Simplicidad: En este ejemplo no se necesita una estructura compleja como unordered_map. Solo se usa un par de variables miembro para almacenar los prototipos.
Extensible: Si necesitas agregar más prototipos en el futuro, simplemente añades más miembros al registro.
Clonación eficiente: Cada clase concreta sabe cómo clonarse a sí misma, lo que hace que el patrón sea flexible y reutilizable.
____________________________________________________________________________________________________________________________________________________________________________________________

<3>

La razón por la se utilizó unordered_map en el código anterior, en lugar de map, es por las diferencias en rendimiento y uso de memoria entre ambas estructuras de datos:

Diferencias clave entre unordered_map y map:
Implementación interna:

unordered_map está implementado utilizando una tabla hash, lo que proporciona acceso promedio O(1) para operaciones como búsqueda, inserción y eliminación.
map está implementado como un árbol binario balanceado (normalmente un árbol rojo-negro), lo que proporciona acceso O(log n) para las mismas operaciones.
Orden de los elementos:

unordered_map no mantiene ningún orden de las claves. Los elementos se almacenan según la función hash.
map almacena los elementos en orden ascendente de las claves (según el operador operator< o un comparador personalizado).
Rendimiento:

unordered_map es más rápido en la mayoría de los casos, ya que las operaciones de acceso, búsqueda e inserción tienen una complejidad promedio de O(1), siempre que no haya muchas colisiones en la tabla hash.
map es más lento en comparación, con operaciones de O(log n), pero es ideal cuando necesitas mantener los elementos en orden.
Por qué usé unordered_map:
Velocidad: En el ejemplo de clonación de prototipos, el objetivo principal es buscar rápidamente un prototipo a partir de una clave (por ejemplo, "deportivo", "suv", etc.). unordered_map es generalmente más rápido para este tipo de búsquedas porque utiliza tablas hash, lo que reduce el tiempo de búsqueda a O(1) en promedio.

No necesitamos orden: Como no necesitamos que los prototipos se mantengan en un orden específico (alfabéticamente o según las claves), no hay beneficio en utilizar map, que garantiza orden pero con un costo de rendimiento en comparación con unordered_map.

¿Cuándo usar map?
Si el orden de las claves es importante en tu aplicación (por ejemplo, si necesitas iterar sobre las claves en orden ascendente o descendente), entonces map sería la elección correcta. También es útil cuando necesitas realizar rangos de búsqueda, ya que map facilita la búsqueda de claves menores o mayores que un valor específico.

Ejemplo usando map en lugar de unordered_map:
Si decidieras usar map en lugar de unordered_map, aquí te muestro cómo se vería el código modificado:

Modificación del código con map:

#include <map>
#include <string>
#include "PrototipoVehiculo.h"
#include "AutoDeportivo.h"
#include "Moto.h"

class RegistroDePrototipos {
private:
    std::map<std::string, PrototipoVehiculo*> catalogo;

public:
    RegistroDePrototipos() {
        // Agregar prototipos al catálogo
        catalogo["auto"] = new AutoDeportivo("Ferrari", "Rojo");
        catalogo["moto"] = new Moto("Yamaha", 600);
    }

    ~RegistroDePrototipos() {
        for (auto& par : catalogo) {
            delete par.second;  // Liberar la memoria
        }
    }

    PrototipoVehiculo* obtenerPrototipo(const std::string& clave) const {
        if (catalogo.find(clave) != catalogo.end()) {
            return catalogo.at(clave)->clonar();
        }
        return nullptr;
    }
};
Este código es funcionalmente equivalente al que usa unordered_map, pero aquí:

El catálogo de prototipos se almacena en un map, lo que garantiza que los elementos se ordenen alfabéticamente según las claves.
Las operaciones de búsqueda, inserción y eliminación ahora tienen una complejidad O(log n) en lugar de O(1).
Resumen:
Se utiliza unordered_map porque en ese ejemplo lo importante era la velocidad de acceso, y no necesitábamos mantener un orden específico de las claves.
Usar map es apropiado si necesitas mantener un orden entre las claves o realizar búsquedas basadas en el rango.
Ambos enfoques son válidos, pero la elección depende de las necesidades específicas de la aplicación en cuanto a rendimiento y orden.
___________________________________________________________________________________________________________________________________________________________________________________________

<4>

Una tabla hash (o hash table) es una estructura de datos que asocia claves con valores y está diseñada para proporcionar una búsqueda, inserción y eliminación de elementos extremadamente eficiente. Lo hace utilizando una técnica llamada hashing, donde una función especial (llamada función hash) convierte la clave en un número (el hash) que se utiliza para determinar dónde almacenar o encontrar el valor asociado en un array o vector subyacente.

Conceptos clave:
Función hash:

Es una función que toma una clave como entrada (por ejemplo, un string o un número) y devuelve un número entero, que se usa como un índice en un array.
El objetivo de la función hash es distribuir uniformemente las claves en el espacio de almacenamiento para minimizar las colisiones (cuando dos claves diferentes generan el mismo hash).
Colisiones:

Ocurren cuando dos claves distintas se transforman en el mismo índice de array.
Para manejar las colisiones, se utilizan técnicas como encadenamiento (donde múltiples valores pueden ocupar la misma ubicación en forma de una lista enlazada) o sondeo abierto (donde se busca otro espacio vacío en el array si ocurre una colisión).
Búsqueda, inserción y eliminación:

Estas operaciones tienen una complejidad promedio O(1), lo que significa que son muy rápidas, ya que dependen solo del cálculo del hash y de la manipulación del array, no de la longitud del array.
Ejemplo sencillo de una tabla hash:
Imagina que tienes una lista de estudiantes con sus identificaciones (claves) y quieres almacenar sus notas (valores). Usas una tabla hash para almacenar los datos, donde la clave es la identificación del estudiante y el valor es la nota.

Función hash: Convierte la identificación del estudiante (por ejemplo, "12345") en un número, digamos 5.
Almacenamiento: Almacenas la nota del estudiante en la posición 5 del array.
Búsqueda: Cuando necesitas buscar la nota de "12345", usas la misma función hash, obtienes el índice 5 y recuperas la nota almacenada en esa posición.
Ejemplo de código en C++ usando unordered_map (que internamente es una tabla hash):

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Crear una tabla hash para almacenar notas de estudiantes
    unordered_map<string, int> notas;

    // Insertar algunas notas usando el ID del estudiante como clave
    notas["12345"] = 85;
    notas["23456"] = 90;
    notas["34567"] = 78;

    // Acceder a las notas
    cout << "La nota del estudiante 12345 es: " << notas["12345"] << endl;
    cout << "La nota del estudiante 23456 es: " << notas["23456"] << endl;

    return 0;
}

Salida:

La nota del estudiante 12345 es: 85
La nota del estudiante 23456 es: 90

Ventajas de las tablas hash:
Velocidad: Las operaciones son muy rápidas, con una complejidad promedio de O(1) para inserción, búsqueda y eliminación.
Simplicidad: Una tabla hash proporciona una forma sencilla de asociar pares clave-valor.
Versatilidad: Pueden manejar datos con claves muy variadas (números, strings, etc.).

Desventajas de las tablas hash:
Colisiones: Aunque se pueden minimizar con buenas funciones hash, las colisiones siempre son una posibilidad y deben manejarse.
Uso de memoria: Las tablas hash pueden consumir más memoria que otras estructuras porque generalmente requieren más espacio del necesario para evitar colisiones.
Orden: Las tablas hash no almacenan los elementos en un orden específico. Si necesitas acceder a los elementos en un orden determinado, esta no es la estructura más adecuada.

Ejemplo de la vida real:
Un ejemplo cotidiano de una tabla hash es un índice de libros. Piensa en un libro que tiene una lista de palabras clave al final, y para cada palabra clave, tiene una lista de números de página donde esa palabra aparece. La palabra clave actúa como una clave, y la lista de páginas es el valor asociado a esa clave.
_________________________________________________________________________________________________________________________________________________________________________________________
