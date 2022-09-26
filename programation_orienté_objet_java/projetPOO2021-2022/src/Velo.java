import java.util.*;
/**la classe Velo est une sous classe de Vehicule,
 * elle permet de créer un objet vélo.
 * Un vélo a une vitesse moyenne qui dépend du cycliste. Son taux d’émission de CO2 est
nul. Sa charge utile est nulle. Son coût d’utilisation sur un kilomètre est égal au prix d’achat
divisé par 30000.*/
public class Velo extends Vehicule {
	Cycliste c;
	public Velo(String nom,double prixAchatVelo,Cycliste c){
		super(nom,prixAchatVelo,0,0);
		this.c=c;
		//this.l_cycliste=new ArrayList<Cycliste>();
	}
	public double vitesseMoyenne(){
		return c.getVitesseMoyenne();//depend du cycliste
	}
	public double coutUtilisation() {
		return getPrix()/30000;
	}

}
