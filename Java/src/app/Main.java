package vehiculo.app;
import vehiculo.modelo.Automovil;
import vehiculo.modelo.Motocicleta;
import vehiculo.modelo.Vehiculo;
import vehiculo.negocio.RegistroVehiculos;

import java.util.Scanner;

//Presento el menu,leo los datos e instancio los objetos Automovil o Motocicleta
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        RegistroVehiculos registro = new RegistroVehiculos();

        int opcion;
        do {
            System.out.println();
            System.out.println("===== MENU REGISTRO DE VEHICULOS =====");
            System.out.println("1. Registrar Automovil");
            System.out.println("2. Registrar Motocicleta");
            System.out.println("3. Mostrar todos los vehiculos");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opcion: ");
            opcion = Integer.parseInt(sc.nextLine().trim());

            switch (opcion) {
                case 1:
                    registrarAutomovil(sc, registro);
                    break;
                case 2:
                    registrarMotocicleta(sc, registro);
                    break;
                case 3:
                    //Aqui se ve el Polimorfismo,cada vehiculo se imprime con su propio formato
                    registro.mostrarTodos();
                    break;
                case 4:
                    System.out.println("Fin del programa.");
                    break;
                default:
                    System.out.println("Opcion invalida.");
            }
        } while (opcion != 4);

        sc.close();
    }

    private static void registrarAutomovil(Scanner sc, RegistroVehiculos registro) {
        System.out.print("Placa: ");
        String placa = sc.nextLine();
        System.out.print("Marca: ");
        String marca = sc.nextLine();
        System.out.print("Modelo: ");
        String modelo = sc.nextLine();
        System.out.print("Anio: ");
        int anio = Integer.parseInt(sc.nextLine().trim());
        System.out.print("Precio: ");
        double precio = Double.parseDouble(sc.nextLine().trim());
        System.out.print("Disponible (true/false): ");
        boolean disponible = Boolean.parseBoolean(sc.nextLine().trim());
        System.out.print("Numero de puertas: ");
        int numeroPuertas = Integer.parseInt(sc.nextLine().trim());
        System.out.print("Electrico (true/false): ");
        boolean electrico = Boolean.parseBoolean(sc.nextLine().trim());

        try {
            //Instancio el objeto,el constructor valida y arma sus atributos (heredados y propios)
            //Guardo la referencia como Vehiculo aunque el objeto real sea Automovil
            Vehiculo nuevoVehiculo = new Automovil(placa, marca, modelo, anio, precio, disponible, numeroPuertas, electrico);
            boolean exito = registro.registrar(nuevoVehiculo);
            System.out.println(exito ? "Automovil registrado." : "No se pudo registrar (arreglo lleno o placa repetida).");
        } catch (IllegalArgumentException e) {
            //Si algun dato no es valido,aviso sin cerrar el programa
            System.out.println("Datos invalidos: " + e.getMessage());
        }
    }

    private static void registrarMotocicleta(Scanner sc, RegistroVehiculos registro) {
        System.out.print("Placa: ");
        String placa = sc.nextLine();
        System.out.print("Marca: ");
        String marca = sc.nextLine();
        System.out.print("Modelo: ");
        String modelo = sc.nextLine();
        System.out.print("Anio: ");
        int anio = Integer.parseInt(sc.nextLine().trim());
        System.out.print("Precio: ");
        double precio = Double.parseDouble(sc.nextLine().trim());
        System.out.print("Disponible (true/false): ");
        boolean disponible = Boolean.parseBoolean(sc.nextLine().trim());
        System.out.print("Cilindrada: ");
        int cilindrada = Integer.parseInt(sc.nextLine().trim());
        System.out.print("Tiene maletero (true/false): ");
        boolean tieneMaletero = Boolean.parseBoolean(sc.nextLine().trim());

        try {
            //Instancio Motocicleta,mismo patron que Automovil
            Vehiculo nuevoVehiculo = new Motocicleta(placa, marca, modelo, anio, precio, disponible, cilindrada, tieneMaletero);
            boolean exito = registro.registrar(nuevoVehiculo);
            System.out.println(exito ? "Motocicleta registrada." : "No se pudo registrar (arreglo lleno o placa repetida).");
        } catch (IllegalArgumentException e) {
            System.out.println("Datos invalidos: " + e.getMessage());
        }
    }
}