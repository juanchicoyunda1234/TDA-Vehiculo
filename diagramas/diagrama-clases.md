# Diagrama de clases - TDA Registro de Vehículos

El TDA `RegistroVehiculos` guarda hasta **10** referencias de tipo `Vehiculo`. Los objetos reales son `Automovil` o `Motocicleta`. `Main` presenta el menú, recibe datos e instancia esas clases hijas.

```mermaid
classDiagram
    direction TB

    class Vehiculo {
        <<abstract>>
        #String placa
        #String marca
        #String modelo
        #int anio
        #double precio
        #boolean disponible
        #Vehiculo(placa, marca, modelo, anio, precio, disponible)
        #datosComunes() String
        +getPlaca() String
        +mostrarInformacion()*
    }

    class Automovil {
        -int numeroPuertas
        -boolean electrico
        +Automovil(placa, marca, modelo, anio, precio, disponible, numeroPuertas, electrico)
        +mostrarInformacion()
    }

    class Motocicleta {
        -int cilindrada
        -boolean tieneMaletero
        +Motocicleta(placa, marca, modelo, anio, precio, disponible, cilindrada, tieneMaletero)
        +mostrarInformacion()
    }

    class RegistroVehiculos {
        -Vehiculo[] vehiculos
        -int cantidad
        -int CAPACIDAD 10
        +RegistroVehiculos()
        +registrar(Vehiculo) boolean
        +existePlaca(placa) boolean
        +mostrarTodos()
        +estaLleno() boolean
        +getCantidad() int
    }

    class Main {
        +main(String[]) void
        -registrarAutomovil(RegistroVehiculos)
        -registrarMotocicleta(RegistroVehiculos)
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
| `Vehiculo <|-- Automovil` y `Vehiculo <|-- Motocicleta` | **Herencia.** Las hijas reutilizan placa, marca, modelo, año, precio y disponible. |
| `mostrarInformacion()` abstracto en `Vehiculo` | **Polimorfismo.** Cada hija lo sobrescribe (`@Override` en Java, `override` en C++). |
| `RegistroVehiculos o-- Vehiculo` (0..10) | **Arreglo estático** de 10. Guarda referencias, no el tipo concreto. |
| `Main ..> Automovil` y `Main ..> Motocicleta` | **Instanciación.** El menú hace `new Automovil(...)` y `new Motocicleta(...)`. |
| Atributos `#` en `Vehiculo` y `-` en las hijas y el TDA | **Encapsulamiento.** `protected` en la clase base y `private` en el resto. |
| `int`, `double` y `boolean` | **Datos primitivos** pedidos en el enunciado. |

## Responsabilidades

| Clase | Paquete / carpeta | Responsabilidad |
|---|---|---|
| `Vehiculo` | `modelo` | Clase abstracta con los atributos comunes. |
| `Automovil` | `modelo` | Clase hija con número de puertas y estado eléctrico. |
| `Motocicleta` | `modelo` | Clase hija con cilindrada y maletero. |
| `RegistroVehiculos` | `negocio` | TDA que administra el arreglo estático. |
| `Main` | `app` | Presenta el menú, recibe datos e instancia objetos. |
