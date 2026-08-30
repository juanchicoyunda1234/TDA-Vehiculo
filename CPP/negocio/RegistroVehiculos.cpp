#include <iostream>
#include <string>
#include "Vehiculo.h" 

namespace vehiculo {
namespace negocio {

    class RegistroVehiculos {
    private:
        static const int CAPACIDAD = 10;
        
        vehiculo::modelo::Vehiculo* vehiculos[CAPACIDAD]; 
        int cantidad;

    public:
        RegistroVehiculos() {
            this->cantidad = 0;
            for (int i = 0; i < CAPACIDAD; i++) {
                vehiculos[i] = nullptr;
            }
        }
        // DESTRUCTOR: Como ahora usamos punteros, si alguien borra el RegistroVehiculos,
        // tenemos que asegurarnos de borrar los vehículos que guardamos para no dejar basura en la RAM.
        ~RegistroVehiculos() {
            for (int i = 0; i < cantidad; i++) {
                delete vehiculos[i]; 
            }
        }
        // El const al final indica que este método no modifica atributos de la clase
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

        // El método debe recibir un puntero (*) para no perder el polimorfismo
        bool registrar(vehiculo::modelo::Vehiculo* nuevoVehiculo) {
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

} 
} 