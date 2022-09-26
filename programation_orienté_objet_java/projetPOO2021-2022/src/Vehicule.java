/** Classe abstraite vehicule qui représente un objet vehicule.
 *elle est caractérisé par les informations suivantes : un nom, un prix d’achat en euros,
une vitesse moyenne en kilomètres par heure, un taux d’émission de CO2 en grammes par
kilomètre, une charge utile en kilogrammes et un coût d’utilisation sur un kilomètre en euros
par kilomètre. */
public abstract class Vehicule {
	/**attributs*/
	private  String nom;
	private double prixAchat,tauxCO2,chargeUtile;
	/**constructeur qui permet l'initialisation de ses attributs*/
	public Vehicule(String nom,double prixAchat,double tauxCO2,double chargeUtile){
		this.nom=nom;
		this.prixAchat=prixAchat;
		this.tauxCO2=tauxCO2;
		this.chargeUtile=chargeUtile;
	}
	/**la méthode getPrix() retourne le prix*/
	public double getPrix() {
		return this.prixAchat;
	}
	/**la méthode getChargeUtile() retourne la charge utile*/
	public double getChargeUtile(){
		return this.chargeUtile;
	}
	/**la méthode getChargeUtile() retourne la charge utile*/
	public double getTauxCO2() {
		return this.tauxCO2;
	}
	/**vitesseMoyenne() Méthode abstraite qui sera implémentée dans les  classes dérrivées  de Vehiule*/
	public abstract double vitesseMoyenne();
	/**coutUtilisation() Méthode abstraite qui sera implémentée dans les  classes dérrivées  de Vehiule*/
	public abstract double coutUtilisation();

}
