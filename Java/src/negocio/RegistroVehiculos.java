package vehiculo.negocio;

import vehiculo.modelo.Vehiculo;

//Es el TDA que administra el arreglo,encapsula vehiculos y cantidad como private
public class RegistroVehiculos {

    //Uso el concepto de arreglo estatico,new Vehiculo[CAPACIDAD] crea un arreglo de tamaño fijo
    //el arreglo guarda referencias Vehiculo,pero los objetos reales pueden ser Automovil o Motocicleta
    private static final int CAPACIDAD = 10;
    private final Vehiculo[] vehiculos = new Vehiculo[CAPACIDAD];
    private int cantidad;

    public RegistroVehiculos() {
        this.cantidad = 0;
    }

    public boolean estaLleno() {
        return cantidad >= CAPACIDAD;
    }

    //Recorro solo hasta cantidad,no hasta CAPACIDAD,para no tocar las posiciones vacias
    public boolean existePlaca(String placa) {
        for (int i = 0; i < cantidad; i++) {
            if (vehiculos[i].getPlaca().equals(placa)) {
                return true;
            }
        }
        return false;
    }

    //Valido que el vehiculo no sea null,que haya espacio y que la placa no este repetida antes de guardar
    public boolean registrar(Vehiculo nuevoVehiculo) {
        if (nuevoVehiculo == null || estaLleno()) {
            return false;
        }
        if (existePlaca(nuevoVehiculo.getPlaca())) {
            return false;
        }
        vehiculos[cantidad] = nuevoVehiculo;
        cantidad++;
        return true;
    }

    //Aqui se ve el Polimorfismo en accion,vehiculos[i] es tipo Vehiculo pero cada uno se
    //muestra distinto (Automovil o Motocicleta) sin que yo tenga que preguntar con ningun if
    public void mostrarTodos() {
        for (int i = 0; i < cantidad; i++) {
            vehiculos[i].mostrarInformacion();
        }
    }

    public int getCantidad() {
        return cantidad;
    }
}