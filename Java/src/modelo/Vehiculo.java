package vehiculo.modelo;

// Aplico el concepto de Herencia ya que Vehiculo es el que se va a heredar a Motocicleta y Automovil
public abstract class Vehiculo {

    // Atributos no primitivos
    protected String placa;
    protected String marca;
    protected String modelo;
    protected int anio;
    //
    protected double precio;
    protected boolean disponible;

    protected Vehiculo(String placa, String marca, String modelo, int anio, double precio, boolean disponible) {
        if (placa == null || placa.isEmpty()) {
            throw new IllegalArgumentException("La placa es obligatoria");
        }
        if (marca == null || marca.isEmpty()) {
            throw new IllegalArgumentException("La marca es obligatoria");
        }
        if (modelo == null || modelo.isEmpty()) {
            throw new IllegalArgumentException("El modelo es obligatorio");
        }
        if (anio < 1886 || anio > 2100) {
            throw new IllegalArgumentException("El anio debe estar entre 1886 y 2100");
        }
        if (precio < 0) {
            throw new IllegalArgumentException("El precio no puede ser negativo");
        }
        this.placa = placa;
        this.marca = marca;
        this.modelo = modelo;
        this.anio = anio;
        this.precio = precio;
        this.disponible = disponible;
    }

    //Getter publico,aunque placa es protected,RegistroVehiculos esta en otro paquete y no hereda
    //de Vehiculo,entonces necesita este metodo para poder leer la placa (existePlaca)
    public String getPlaca() {
        return placa;
    }

    //Uso String.format para armar el texto con los datos que comparten todos los vehiculos
    //cada clase hija llama a este metodo dentro de su propio mostrarInformacion()
    protected String datosComunes() {
        return String.format("PLACA : %s | MARCA : %s | MODELO : %s | AÑO : %04d | PRECIO : %.2f$ | DISPONIBLE : %b",
                placa, marca, modelo, anio, precio, disponible);
    }

    //Aplico el concepto de Polimorfismo,cada vehiculo va a mostrar su informacion de manera diferente
    //RegistroVehiculos llama vehiculos[i].mostrarInformacion() sin saber si es Automovil o Motocicleta
    public abstract void mostrarInformacion();
}