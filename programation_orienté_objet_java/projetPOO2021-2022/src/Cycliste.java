public class Cycliste extends Salarie{
	private double vitesseMoyenne;
	public Cycliste(String nom,double poids,double salaire,double vitesseMoyenne){
		super(nom,poids,salaire);
		this.vitesseMoyenne=vitesseMoyenne;
	}
	public double getVitesseMoyenne() {
		return this.vitesseMoyenne;
	}
	/*public boolean aLaMeilleurVitesseMoyenne(Cycliste c) {
		return (this.vitesseMoyenne >= c.vitesseMoyenne);
	}*/
	/*public Cycliste clone() {
		return new Cycliste(getNom(),salaire(),getPoids(),vitesseMoyenne);
	}*/

}
