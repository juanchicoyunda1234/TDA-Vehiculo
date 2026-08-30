#include <iostream>
#include <string>
#include <stdexcept>
#include "Vehiculo.h"

// Aplico Herencia, Automovil hereda de Vehiculo con extends (en C++ es : public)
class Automovil : public Vehiculo {
private:
    // numeroPuertas y electrico son primitivos, propios de Automovil (Vehiculo no los tiene)
    int numeroPuertas;
    bool electrico;

public:
    Automovil(std::string placa, std::string marca, std::string modelo, int anio, double precio, bool disponible,
              int numeroPuertas, bool electrico) 
        // Uso super para que Vehiculo inicialice lo que ya es de el (en C++ mediante lista de inicializacion)
        : Vehiculo(placa, marca, modelo, anio, precio, disponible) {
        
        if (numeroPuertas < 2 || numeroPuertas > 6) {
            throw std::invalid_argument("Un automovil debe tener entre 2 y 6 puertas");
        }
        this->numeroPuertas = numeroPuertas;
        this->electrico = electrico;
    }

    // Se demuestra el Polimorfismo, Automovil sobreescribe mostrarInformacion con su propio formato
    // Uso std::cout para armar la salida, igual que datosComunes() de Vehiculo
    void mostrarInformacion() const override {
        std::cout << "| AUTOMOVIL | " << datosComunes() 
                  << " | PUERTAS : " << numeroPuertas 
                  << " | ELECTRICO : " << (electrico ? "true" : "false") << " |\n";
    }
};