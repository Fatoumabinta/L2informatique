/**la classe Salarie est une super classe de la classe Cycliste et ConducteurDeScooter,
 * elle permet de créer un objet salarié.Un salarié possède un nom, un poids en
kilogrammes, un salaire en euros par heure. Sa charge utile est égale à son poids divisé par 8*/
public class Salarie {
	private  String nom;
	private double poids;//poids en  kg
	private double salaire;//en euro par heure
	public Salarie(String nom,double poids,double salaire){		
		this.nom=nom;
		this.poids=poids;
		this.salaire=salaire;
		//this.fonction =fonction;	
	}
	public String getNom(){
		return this.nom;
	}
	public double getPoids(){
		return this.poids;
	}
	public double getSalaire(){
		return this.salaire;
	}
	public double chargeUtile() {
		return (getPoids()/8);
	}
	/*public Salarie clone() {
		return new Salarie(nom,poids,salaire);
	}*/
}
