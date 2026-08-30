# Diagrama de paquetes - TDA Registro de Vehículos

Arquitectura en tres capas, igual en Java (`src/`) y en C++ (`CPP/`).

```mermaid
flowchart TB
    subgraph app [app]
        Main["Main<br/>menu, lectura de datos<br/>e instanciacion"]
    end

    subgraph negocio [negocio]
        Registro["RegistroVehiculos<br/>TDA - arreglo Vehiculo[10]"]
    end

    subgraph modelo [modelo]
        Base["Vehiculo<br/>clase abstracta"]
        Auto["Automovil"]
        Moto["Motocicleta"]
        Base --> Auto
        Base --> Moto
    end

    Main --> Registro
    Main --> Auto
    Main --> Moto
    Registro --> Base
```

```mermaid
classDiagram
    direction LR

    namespace modelo {
        class Vehiculo {
            <<abstract>>
        }
        class Automovil
        class Motocicleta
    }

    namespace negocio {
        class RegistroVehiculos
    }

    namespace app {
        class Main
    }

    Vehiculo <|-- Automovil
    Vehiculo <|-- Motocicleta
    RegistroVehiculos o-- Vehiculo
    Main ..> RegistroVehiculos
    Main ..> Automovil
    Main ..> Motocicleta
```

## Dependencias entre carpetas

| Capa | Contiene | Depende de |
|---|---|---|
| `modelo/` | `Vehiculo`, `Automovil`, `Motocicleta` | nada |
| `negocio/` | `RegistroVehiculos` | `modelo` |
| `app/` | `Main` | `modelo` y `negocio` |

`negocio` trabaja solo con el tipo `Vehiculo`. El tipo concreto (`Automovil` o `Motocicleta`) lo decide `Main` al instanciar, y el TDA lo trata de forma polimórfica.
