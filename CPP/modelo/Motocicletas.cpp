#include <iostream>
#include <string>
#include <stdexcept>
#include "Vehiculo.h" // Asumiendo que existe en tu proyecto

// Aplico Herencia, Motocicleta hereda de Vehiculo de forma publica (equivalente a extends)
class Motocicleta : public Vehiculo {
private:
    // cilindrada y tieneMaletero son primitivos, propios de Motocicleta (Vehiculo no los tiene)
    int cilindrada;
    bool tieneMaletero;

public:
    Motocicleta(std::string placa, std::string marca, std::string modelo, int anio, double precio, bool disponible,
                int cilindrada, bool tieneMaletero) 
        // Uso la lista de inicializacion para que Vehiculo inicialice lo que ya es de el (equivalente a super(...))
        : Vehiculo(placa, marca, modelo, anio, precio, disponible) {
        
        if (cilindrada < 50 || cilindrada > 2500) {
            throw std::invalid_argument("La cilindrada debe estar entre 50 y 2500 cc");
        }
        this->cilindrada = cilindrada;
        this->tieneMaletero = tieneMaletero;
    }

    // Aqui se demuestra el Polimorfismo, Motocicleta sobreescribe mostrarInformacion con su propio formato
    void mostrarInformacion() const override {
        std::cout << "| MOTOCICLETA | " << datosComunes() 
                  << " | CILINDRADA : " << cilindrada << " cc"
                  << " | MALETERO : " << (tieneMaletero ? "true" : "false") << " |" << std::endl;
    }
};