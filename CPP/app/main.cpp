#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

// ==========================================
// 1. CLASES MODELO Y NEGOCIO
// ==========================================

class Vehiculo {
protected:
    std::string placa;
    std::string marca;
    std::string modelo;
    int anio;
    double precio;
    bool disponible;

public:
    Vehiculo(std::string p, std::string m, std::string mod, int a, double prec, bool disp)
        : placa(p), marca(m), modelo(mod), anio(a), precio(prec), disponible(disp) {}

    virtual ~Vehiculo() {}

    // Método virtual puro para demostrar Polimorfismo
    virtual void mostrar() const = 0;

    std::string getPlaca() const {
        return placa;
    }
};

class Automovil : public Vehiculo {
private:
    int numeroPuertas;
    bool electrico;

public:
    Automovil(std::string p, std::string m, std::string mod, int a, double prec, bool disp, int puertas, bool elec)
        : Vehiculo(p, m, mod, a, prec, disp), numeroPuertas(puertas), electrico(elec) {
        if (puertas <= 0) {
            throw std::invalid_argument("El numero de puertas debe ser mayor a 0.");
        }
    }

    void mostrar() const override {
        std::cout << "[Automovil] Placa: " << placa 
                  << " | Marca: " << marca 
                  << " | Modelo: " << modelo 
                  << " | Anio: " << anio 
                  << " | Precio: $" << precio 
                  << " | Disponible: " << (disponible ? "Si" : "No") 
                  << " | Puertas: " << numeroPuertas 
                  << " | Electrico: " << (electrico ? "Si" : "No") << std::endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;
    bool tieneMaletero;

public:
    Motocicleta(std::string p, std::string m, std::string mod, int a, double prec, bool disp, int cil, bool maletero)
        : Vehiculo(p, m, mod, a, prec, disp), cilindrada(cil), tieneMaletero(maletero) {
        if (cil <= 0) {
            throw std::invalid_argument("La cilindrada debe ser mayor a 0.");
        }
    }

    void mostrar() const override {
        std::cout << "[Motocicleta] Placa: " << placa 
                  << " | Marca: " << marca 
                  << " | Modelo: " << modelo 
                  << " | Anio: " << anio 
                  << " | Precio: $" << precio 
                  << " | Disponible: " << (disponible ? "Si" : "No") 
                  << " | Cilindrada: " << cilindrada << "cc" 
                  << " | Maletero: " << (tieneMaletero ? "Si" : "No") << std::endl;
    }
};

class RegistroVehiculos {
private:
    std::vector<std::unique_ptr<Vehiculo>> vehiculos;
    const size_t MAX_VEHICULOS = 20; // Límite máximo similar al de los ejercicios anteriores

public:
    bool registrar(std::unique_ptr<Vehiculo> nuevoVehiculo) {
        // Validar si ya existe la placa
        for (const auto& v : vehiculos) {
            if (v->getPlaca() == nuevoVehiculo->getPlaca()) {
                return false; // Placa repetida
            }
        }
        // Validar límite del arreglo/vector
        if (vehiculos.size() >= MAX_VEHICULOS) {
            return false; // Contenedor lleno
        }

        vehiculos.push_back(std::move(nuevoVehiculo));
        return true;
    }

    void mostrarTodos() const {
        if (vehiculos.empty()) {
            std::cout << "No hay vehiculos registrados.\n";
            return;
        }
        for (const auto& v : vehiculos) {
            v->mostrar(); // Aquí se aplica el polimorfismo
        }
    }
};

// ==========================================
// 2. FUNCIONES DE REGISTRO DESDE CONSOLA
// ==========================================

void registrarAutomovil(RegistroVehiculos& registro) {
    std::string placa, marca, modelo;
    int anio, numeroPuertas;
    double precio;
    std::string dispStr, elecStr;
    bool disponible, electrico;

    std::cout << "Placa: ";
    std::getline(std::cin, placa);
    std::cout << "Marca: ";
    std::getline(std::cin, marca);
    std::cout << "Modelo: ";
    std::getline(std::cin, modelo);
    
    std::cout << "Anio: ";
    std::string temp;
    std::getline(std::cin, temp);
    anio = std::stoi(temp);

    std::cout << "Precio: ";
    std::getline(std::cin, temp);
    precio = std::stod(temp);

    std::cout << "Disponible (true/false): ";
    std::getline(std::cin, dispStr);
    disponible = (dispStr == "true" || dispStr == "1" || dispStr == "verdadero");

    std::cout << "Numero de puertas: ";
    std::getline(std::cin, temp);
    numeroPuertas = std::stoi(temp);

    std::cout << "Electrico (true/false): ";
    std::getline(std::cin, elecStr);
    electrico = (elecStr == "true" || elecStr == "1" || elecStr == "verdadero");

    try {
        auto nuevoVehiculo = std::make_unique<Automovil>(placa, marca, modelo, anio, precio, disponible, numeroPuertas, electrico);
        bool exito = registro.registrar(std::move(nuevoVehiculo));
        std::cout << (exito ? "Automovil registrado.\n" : "No se pudo registrar (arreglo lleno o placa repetida).\n");
    } catch (const std::exception& e) {
        std::cout << "Datos invalidos: " << e.what() << "\n";
    }
}

void registrarMotocicleta(RegistroVehiculos& registro) {
    std::string placa, marca, modelo;
    int anio, cilindrada;
    double precio;
    std::string dispStr, maleteroStr;
    bool disponible, tieneMaletero;

    std::cout << "Placa: ";
    std::getline(std::cin, placa);
    std::cout << "Marca: ";
    std::getline(std::cin, marca);
    std::cout << "Modelo: ";
    std::getline(std::cin, modelo);
    
    std::string temp;
    std::cout << "Anio: ";
    std::getline(std::cin, temp);
    anio = std::stoi(temp);

    std::cout << "Precio: ";
    std::getline(std::cin, temp);
    precio = std::stod(temp);

    std::cout << "Disponible (true/false): ";
    std::getline(std::cin, dispStr);
    disponible = (dispStr == "true" || dispStr == "1" || dispStr == "verdadero");

    std::cout << "Cilindrada: ";
    std::getline(std::cin, temp);
    cilindrada = std::stoi(temp);

    std::cout << "Tiene maletero (true/false): ";
    std::getline(std::cin, maleteroStr);
    tieneMaletero = (maleteroStr == "true" || maleteroStr == "1" || maleteroStr == "verdadero");

    try {
        auto nuevoVehiculo = std::make_unique<Motocicleta>(placa, marca, modelo, anio, precio, disponible, cilindrada, tieneMaletero);
        bool exito = registro.registrar(std::move(nuevoVehiculo));
        std::cout << (exito ? "Motocicleta registrada.\n" : "No se pudo registrar (arreglo lleno o placa repetida).\n");
    } catch (const std::exception& e) {
        std::cout << "Datos invalidos: " << e.what() << "\n";
    }
}

// ==========================================
// 3. FUNCIÓN PRINCIPAL (MAIN)
// ==========================================

int main() {
    // Configurar consola para caracteres latinos si es necesario
    RegistroVehiculos registro;
    int opcion = 0;

    do {
        std::cout << "\n===== MENU REGISTRO DE VEHICULOS =====\n";
        std::cout << "1. Registrar Automovil\n";
        std::cout << "2. Registrar Motocicleta\n";
        std::cout << "3. Mostrar todos los vehiculos\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        
        std::string inputOp;
        std::getline(std::cin, inputOp);
        
        try {
            opcion = std::stoi(inputOp);
        } catch (...) {
            opcion = 0; // Opción inválida si ingresan letras
        }

        switch (opcion) {
            case 1:
                registrarAutomovil(registro);
                break;
            case 2:
                registrarMotocicleta(registro);
                break;
            case 3:
                // Aquí se ve el Polimorfismo, cada vehículo se imprime con su propio formato
                registro.mostrarTodos();
                break;
            case 4:
                std::cout << "Fin del programa.\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 4);

    return 0;
}