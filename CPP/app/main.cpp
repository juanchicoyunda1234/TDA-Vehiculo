#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "../negocio/RegistroVehiculos.cpp"

static std::string leerLinea() {
    std::string linea;
    std::getline(std::cin, linea);
    return linea;
}

static std::string recortar(const std::string& texto) {
    size_t inicio = 0;
    while (inicio < texto.size() && std::isspace(static_cast<unsigned char>(texto[inicio]))) {
        inicio++;
    }
    size_t fin = texto.size();
    while (fin > inicio && std::isspace(static_cast<unsigned char>(texto[fin - 1]))) {
        fin--;
    }
    return texto.substr(inicio, fin - inicio);
}

static bool parseBoolean(const std::string& texto) {
    std::string valor = recortar(texto);
    for (size_t i = 0; i < valor.size(); i++) {
        valor[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(valor[i])));
    }
    return valor == "true";
}

static void registrarAutomovil(RegistroVehiculos& registro) {
    std::cout << "Placa: ";
    std::string placa = leerLinea();
    std::cout << "Marca: ";
    std::string marca = leerLinea();
    std::cout << "Modelo: ";
    std::string modelo = leerLinea();
    std::cout << "Anio: ";
    int anio = std::stoi(recortar(leerLinea()));
    std::cout << "Precio: ";
    double precio = std::stod(recortar(leerLinea()));
    std::cout << "Disponible (true/false): ";
    bool disponible = parseBoolean(leerLinea());
    std::cout << "Numero de puertas: ";
    int numeroPuertas = std::stoi(recortar(leerLinea()));
    std::cout << "Electrico (true/false): ";
    bool electrico = parseBoolean(leerLinea());

    try {
        Vehiculo* nuevoVehiculo = new Automovil(placa, marca, modelo, anio, precio, disponible, numeroPuertas, electrico);
        bool exito = registro.registrar(nuevoVehiculo);
        if (!exito) {
            delete nuevoVehiculo;
        }
        std::cout << (exito ? "Automovil registrado." : "No se pudo registrar (arreglo lleno o placa repetida).") << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Datos invalidos: " << e.what() << std::endl;
    }
}

static void registrarMotocicleta(RegistroVehiculos& registro) {
    std::cout << "Placa: ";
    std::string placa = leerLinea();
    std::cout << "Marca: ";
    std::string marca = leerLinea();
    std::cout << "Modelo: ";
    std::string modelo = leerLinea();
    std::cout << "Anio: ";
    int anio = std::stoi(recortar(leerLinea()));
    std::cout << "Precio: ";
    double precio = std::stod(recortar(leerLinea()));
    std::cout << "Disponible (true/false): ";
    bool disponible = parseBoolean(leerLinea());
    std::cout << "Cilindrada: ";
    int cilindrada = std::stoi(recortar(leerLinea()));
    std::cout << "Tiene maletero (true/false): ";
    bool tieneMaletero = parseBoolean(leerLinea());

    try {
        Vehiculo* nuevoVehiculo = new Motocicleta(placa, marca, modelo, anio, precio, disponible, cilindrada, tieneMaletero);
        bool exito = registro.registrar(nuevoVehiculo);
        if (!exito) {
            delete nuevoVehiculo;
        }
        std::cout << (exito ? "Motocicleta registrada." : "No se pudo registrar (arreglo lleno o placa repetida).") << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Datos invalidos: " << e.what() << std::endl;
    }
}

int main() {
    RegistroVehiculos registro;
    int opcion;

    do {
        std::cout << std::endl;
        std::cout << "===== MENU REGISTRO DE VEHICULOS =====" << std::endl;
        std::cout << "1. Registrar Automovil" << std::endl;
        std::cout << "2. Registrar Motocicleta" << std::endl;
        std::cout << "3. Mostrar todos los vehiculos" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        opcion = std::stoi(recortar(leerLinea()));

        switch (opcion) {
            case 1:
                registrarAutomovil(registro);
                break;
            case 2:
                registrarMotocicleta(registro);
                break;
            case 3:
                registro.mostrarTodos();
                break;
            case 4:
                std::cout << "Fin del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}
