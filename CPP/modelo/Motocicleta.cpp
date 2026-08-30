#ifndef MOTOCICLETA_CPP
#define MOTOCICLETA_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Vehiculo.cpp"

class Motocicleta : public Vehiculo {
private:
    int cilindrada;
    bool tieneMaletero;

public:
    Motocicleta(std::string placa, std::string marca, std::string modelo, int anio, double precio, bool disponible,
                int cilindrada, bool tieneMaletero)
        : Vehiculo(placa, marca, modelo, anio, precio, disponible) {
        if (cilindrada < 50 || cilindrada > 2500) {
            throw std::invalid_argument("La cilindrada debe estar entre 50 y 2500 cc");
        }
        this->cilindrada = cilindrada;
        this->tieneMaletero = tieneMaletero;
    }

    void mostrarInformacion() const override {
        std::cout << "| MOTOCICLETA | " << datosComunes()
                  << " | CILINDRADA : " << cilindrada << " cc"
                  << " | MALETERO : " << (tieneMaletero ? "true" : "false") << " |" << std::endl;
    }
};

#endif
