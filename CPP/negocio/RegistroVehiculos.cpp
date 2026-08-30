#ifndef REGISTROVEHICULOS_CPP
#define REGISTROVEHICULOS_CPP

#include <iostream>
#include <string>
#include "../modelo/Automovil.cpp"
#include "../modelo/Motocicleta.cpp"

class RegistroVehiculos {
private:
    static const int CAPACIDAD = 10;
    Vehiculo* vehiculos[CAPACIDAD];
    int cantidad;

public:
    RegistroVehiculos() {
        this->cantidad = 0;
        for (int i = 0; i < CAPACIDAD; i++) {
            vehiculos[i] = nullptr;
        }
    }

    ~RegistroVehiculos() {
        for (int i = 0; i < cantidad; i++) {
            delete vehiculos[i];
        }
    }

    bool estaLleno() const {
        return cantidad >= CAPACIDAD;
    }

    bool existePlaca(std::string placa) const {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i]->getPlaca() == placa) {
                return true;
            }
        }
        return false;
    }

    bool registrar(Vehiculo* nuevoVehiculo) {
        if (nuevoVehiculo == nullptr || estaLleno()) {
            return false;
        }
        if (existePlaca(nuevoVehiculo->getPlaca())) {
            return false;
        }
        vehiculos[cantidad] = nuevoVehiculo;
        cantidad++;
        return true;
    }

    void mostrarTodos() const {
        for (int i = 0; i < cantidad; i++) {
            vehiculos[i]->mostrarInformacion();
        }
    }

    int getCantidad() const {
        return cantidad;
    }
};

#endif
