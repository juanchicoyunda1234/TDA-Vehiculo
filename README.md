# TDA Registro de Vehículos

## Descripcion

Desarrollar en **Java** y **C++** un programa que registre información de vehículos usando:

- un arreglo estático o de tamaño fijo;
- al menos dos tipos de datos primitivos;
- una clase;
- instanciación de objetos;
- herencia;
- polimorfismo;
- comentarios que identifiquen cada concepto.

### Solución propuesta

Se crea un TDA `RegistroVehiculos` con capacidad para **diez** elementos. El arreglo almacena referencias de tipo `Vehiculo`, pero los objetos reales pueden ser automóviles o motocicletas.

El programa contiene cinco clases:

| Clase | Responsabilidad |
|---|---|
| `Vehiculo` | Clase abstracta que contiene los atributos comunes. |
| `Automovil` | Clase hija con número de puertas y estado eléctrico. |
| `Motocicleta` | Clase hija con cilindrada y maletero. |
| `RegistroVehiculos` | TDA que administra el arreglo estático. |
| `Main` | Presenta el menú, recibe datos e instancia objetos. |

### Modelo de dominio

- **`Vehiculo` (abstracta):** atributos comunes protegidos (`placa`, `marca`, `anio` e `precio`) y un método abstracto que cada hija sobrescribe.
- **`Automovil`:** hereda de `Vehiculo`; agrega `numeroPuertas` (`int`) y `esElectrico` (`boolean`).
- **`Motocicleta`:** hereda de `Vehiculo`; agrega `cilindrada` (`int`) y `tieneMaletero` (`boolean`).
- **`RegistroVehiculos`:** TDA con `new Vehiculo[10]`, un `tope`/`cantidad` y operaciones para registrar y listar.
- **`Main`:** menú de consola. Recibe los datos del usuario, instancia `Automovil` o `Motocicleta` con `new` y los entrega al TDA.

### Conceptos aplicados

| Requisito | Aplicación |
|---|---|
| Arreglo estático | `new Vehiculo[10]` crea un arreglo de tamaño fijo. |
| Datos primitivos | `int`, `double` y `boolean`. |
| Clase | `Vehiculo`, `Automovil`, `Motocicleta` y `RegistroVehiculos`. |
| Instanciación | `new Automovil(...)`, `new Motocicleta(...)`. |
| Herencia | `Automovil extends Vehiculo` y `Motocicleta extends Vehiculo`. |
| Polimorfismo | Método abstracto sobrescrito con `@Override`. |
| Encapsulamiento | Atributos `private` y `protected`. |
| Comentarios | El código contiene marcas `CONCEPTO:`. |

Los primitivos quedan así: `int` (`anio`, `numeroPuertas`, `cilindrada`, `cantidad`), `double` (`precio`) y `boolean` (`esElectrico`, `tieneMaletero`).

El polimorfismo se observa al recorrer el arreglo de tipo `Vehiculo`: cada posición puede apuntar a un automóvil o a una motocicleta, y la llamada al método abstracto ejecuta la versión de la clase real.

## Estructura del proyecto

Arquitectura modular en 3 paquetes/carpetas (implementada en Java y C++):

- `modelo/`  -> clases del dominio (`Vehiculo`, `Automovil`, `Motocicleta`).
- `negocio/` -> TDA `RegistroVehiculos` que administra el arreglo estático.
- `app/`     -> punto de entrada (`Main.java` / `main.cpp`) con el menú.

## Diagramas

- Diagrama de clases: `diagramas/diagrama-clases.md`
- Diagrama de paquetes: `diagramas/diagrama-paquetes.md`

## Como ejecutar

### Java

Desde la carpeta `Java`:

```bash
# Compilar todas las clases
javac -d bin src/modelo/*.java src/negocio/*.java src/app/*.java

# Ejecutar
java -cp bin app.Main
```

### C++

> **Nota:** Este proyecto no utiliza archivos de cabecera `.h`. Cada clase contiene su declaracion e implementacion en su archivo `.cpp` con guardas `#ifndef`, incluyendose automaticamente en cadena. Por lo tanto, solo debe compilarse `app/main.cpp`.

Desde la carpeta `CPP`:

```bash
# Compilar
g++ -std=c++17 app/main.cpp -o programa

# Ejecutar (Linux / macOS)
./programa

# Ejecutar (Windows)
programa.exe
```

## Equipo

| Rol | Integrante |
|---|---|
| Lider | Juan Chico |
| Documentacion - Diagramas | Jeremy Torosina |
| Documentacion - Informe | Jullisa Altamirano |
| Backend - Modelo | Joseph Romo |
| Backend - Negocio | Andres Yamuca |
| Frontend - Integracion | Noemi Tuza |
