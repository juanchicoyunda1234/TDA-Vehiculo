#ifndef VEHICULO_CPP
#define VEHICULO_CPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class Vehiculo {
protected:
    std::string placa;
    std::string marca;
    std::string modelo;
    int anio;
    double precio;
    bool disponible;

    Vehiculo(std::string placa, std::string marca, std::string modelo, int anio, double precio, bool disponible) {
        if (placa.empty()) {
            throw std::invalid_argument("La placa es obligatoria");
        }
        if (marca.empty()) {
            throw std::invalid_argument("La marca es obligatoria");
        }
        if (modelo.empty()) {
            throw std::invalid_argument("El modelo es obligatorio");
        }
        if (anio < 1886 || anio > 2100) {
            throw std::invalid_argument("El anio debe estar entre 1886 y 2100");
        }
        if (precio < 0) {
            throw std::invalid_argument("El precio no puede ser negativo");
        }

        this->placa = placa;
        this->marca = marca;
        this->modelo = modelo;
        this->anio = anio;
        this->precio = precio;
        this->disponible = disponible;
    }

    std::string datosComunes() const {
        std::ostringstream formato;
        formato << "PLACA : " << placa
                << " | MARCA : " << marca
                << " | MODELO : " << modelo
                << " | AÑO : " << std::setfill('0') << std::setw(4) << anio
                << " | PRECIO : " << std::fixed << std::setprecision(2) << precio << "$"
                << " | DISPONIBLE : " << (disponible ? "true" : "false");
        return formato.str();
    }

public:
    virtual ~Vehiculo() = default;

    std::string getPlaca() const {
        return placa;
    }

    virtual void mostrarInformacion() const = 0;
};

#endif
