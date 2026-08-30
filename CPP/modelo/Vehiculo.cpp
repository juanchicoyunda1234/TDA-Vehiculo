#include <iostream>
#include <string>
#include <stdexcept> // Para usar std::invalid_argument
#include <sstream>   // Para reemplazar el String.format
#include <iomanip>   // Para dar formato a los números (decimales, ceros a la izquierda)

namespace vehiculo {
namespace modelo {

    class Vehiculo {
    protected: // Atributos protegidos
        std::string placa;
        std::string marca;
        std::string modelo;
        int anio;
        double precio;
        bool disponible;

        // Constructor protegido (solo lo pueden llamar Motocicleta y Automovil)
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

        // Uso std::ostringstream para armar el texto con los datos comunes
        // Es el equivalente más seguro al String.format de Java
        std::string datosComunes() const {
            std::ostringstream formato;
            formato << "PLACA : " << placa 
                    << " | MARCA : " << marca 
                    << " | MODELO : " << modelo 
                    << " | AÑO : " << std::setfill('0') << std::setw(4) << anio // Para el %04d
                    << " | PRECIO : " << std::fixed << std::setprecision(2) << precio << "$" // Para el %.2f
                    << " | DISPONIBLE : " << (disponible ? "true" : "false"); // Para el %b
            return formato.str();
        }

    public:
        virtual ~Vehiculo() = default;
        // Getter publico. El "const" al final asegura que no modifique nada.
        std::string getPlaca() const {
            return placa;
        }

        // Método abstracto: En C++ se llaman "funciones virtuales puras" y llevan un "= 0" al final
        virtual void mostrarInformacion() const = 0;
    };

} 