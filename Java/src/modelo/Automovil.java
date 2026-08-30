package vehiculo.modelo;

//Aplico Herencia,Automovil hereda de Vehiculo con extends
public class Automovil extends Vehiculo {

    //numeroPuertas y electrico son primitivos,propios de Automovil (Vehiculo no los tiene)
    private int numeroPuertas;
    private boolean electrico;

    public Automovil(String placa, String marca, String modelo, int anio, double precio, boolean disponible,
                     int numeroPuertas, boolean electrico) {
        //Uso super para que Vehiculo inicialice lo que ya es de el
        super(placa, marca, modelo, anio, precio, disponible);
        if (numeroPuertas < 2 || numeroPuertas > 6) {
            throw new IllegalArgumentException("Un automovil debe tener entre 2 y 6 puertas");
        }
        this.numeroPuertas = numeroPuertas;
        this.electrico = electrico;
    }

    //Se demuestra el Polimorfismo,Automovil sobreescribe mostrarInformacion con su propio formato
    //Uso String.format para armar la salida,igual que datosComunes() de Vehiculo
    @Override
    public void mostrarInformacion() {
        System.out.println(String.format("| AUTOMOVIL | %s | PUERTAS : %d | ELECTRICO : %b |",
                datosComunes(), numeroPuertas, electrico));
    }
}