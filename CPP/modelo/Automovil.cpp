#ifndef AUTOMOVIL_CPP
#define AUTOMOVIL_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Vehiculo.cpp"

class Automovil : public Vehiculo {
private:
    int numeroPuertas;
    bool electrico;

public:
    Automovil(std::string placa, std::string marca, std::string modelo, int anio, double precio, bool disponible,
              int numeroPuertas, bool electrico)
        : Vehiculo(placa, marca, modelo, anio, precio, disponible) {
        if (numeroPuertas < 2 || numeroPuertas > 6) {
            throw std::invalid_argument("Un automovil debe tener entre 2 y 6 puertas");
        }
        this->numeroPuertas = numeroPuertas;
        this->electrico = electrico;
    }

    void mostrarInformacion() const override {
        std::cout << "| AUTOMOVIL | " << datosComunes()
                  << " | PUERTAS : " << numeroPuertas
                  << " | ELECTRICO : " << (electrico ? "true" : "false") << " |" << std::endl;
    }
};

#endif
