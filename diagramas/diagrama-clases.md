# Diagrama de clases - TDA Registro de Vehículos

El TDA `RegistroVehiculos` guarda hasta **10** referencias de tipo `Vehiculo`. Los objetos reales son `Automovil` o `Motocicleta`. `Main` presenta el menú, recibe datos e instancia esas clases hijas.

```mermaid
classDiagram
    direction TB

    class Vehiculo {
        <<abstract>>
        #String placa
        #String marca
        #int anio
        #double precio
        +Vehiculo(placa, marca, anio, precio)
        +describir() String*
        +mostrarInformacion()
    }

    class Automovil {
        -int numeroPuertas
        -boolean esElectrico
        +Automovil(placa, marca, anio, precio, numeroPuertas, esElectrico)
        +describir() String
    }

    class Motocicleta {
        -int cilindrada
        -boolean tieneMaletero
        +Motocicleta(placa, marca, anio, precio, cilindrada, tieneMaletero)
        +describir() String
    }

    class RegistroVehiculos {
        -Vehiculo[] vehiculos
        -int cantidad
        +int CAPACIDAD 10
        +RegistroVehiculos()
        +registrar(Vehiculo) boolean
        +mostrarTodos()
        +getCantidad() int
        +estaLleno() boolean
    }

    class Main {
        +main(String[]) void
        -mostrarMenu()
        -registrarAutomovil(RegistroVehiculos)
        -registrarMotocicleta(RegistroVehiculos)
        -listarVehiculos(RegistroVehiculos)
    }

    Vehiculo <|-- Automovil : hereda
    Vehiculo <|-- Motocicleta : hereda
    RegistroVehiculos "1" o-- "0..10" Vehiculo : arreglo estatico
    Main ..> RegistroVehiculos : usa
    Main ..> Automovil : instancia
    Main ..> Motocicleta : instancia
```

## Lectura del diagrama

| Relación | Qué representa |
|---|---|
| `Vehiculo <|-- Automovil` y `Vehiculo <|-- Motocicleta` | **Herencia.** Las hijas reutilizan placa, marca, año y precio. |
| `describir()` marcado como abstracto (`*`) en `Vehiculo` | **Polimorfismo.** Cada hija lo sobrescribe con `@Override`. |
| `RegistroVehiculos o-- Vehiculo` (0..10) | **Arreglo estático** `new Vehiculo[10]`. Guarda referencias, no el tipo concreto. |
| `Main ..> Automovil` y `Main ..> Motocicleta` | **Instanciación.** El menú hace `new Automovil(...)` y `new Motocicleta(...)`. |
| Atributos `#` en `Vehiculo` y `-` en las hijas y el TDA | **Encapsulamiento.** `protected` en la clase base y `private` en el resto. |
| `int`, `double` y `boolean` | **Datos primitivos** pedidos en el enunciado. |

## Responsabilidades

| Clase | Paquete | Responsabilidad |
|---|---|---|
| `Vehiculo` | `modelo` | Clase abstracta con los atributos comunes. |
| `Automovil` | `modelo` | Clase hija con número de puertas y estado eléctrico. |
| `Motocicleta` | `modelo` | Clase hija con cilindrada y maletero. |
| `RegistroVehiculos` | `negocio` | TDA que administra el arreglo estático. |
| `Main` | `app` | Presenta el menú, recibe datos e instancia objetos. |
