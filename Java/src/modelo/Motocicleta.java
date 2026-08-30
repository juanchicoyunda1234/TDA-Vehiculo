package vehiculo.modelo;

//Aplico Herencia,Motocicleta hereda de Vehiculo con extends
public class Motocicleta extends Vehiculo {

    //cilindrada y tieneMaletero son primitivos,propios de Motocicleta (Vehiculo no los tiene)
    private int cilindrada;
    private boolean tieneMaletero;

    public Motocicleta(String placa, String marca, String modelo, int anio, double precio, boolean disponible,
                       int cilindrada, boolean tieneMaletero) {
        //Uso super para que Vehiculo inicialice lo que ya es de el
        super(placa, marca, modelo, anio, precio, disponible);
        if (cilindrada < 50 || cilindrada > 2500) {
            throw new IllegalArgumentException("La cilindrada debe estar entre 50 y 2500 cc");
        }
        this.cilindrada = cilindrada;
        this.tieneMaletero = tieneMaletero;
    }

    //Se demuestra el Polimorfismo,Motocicleta sobreescribe mostrarInformacion con su propio formato
    //Uso String.format para armar la salida,igual que datosComunes() de Vehiculo
    @Override
    public void mostrarInformacion() {
        System.out.println(String.format("| MOTOCICLETA | %s | CILINDRADA : %d cc | MALETERO : %b |",
                datosComunes(), cilindrada, tieneMaletero));
    }
}