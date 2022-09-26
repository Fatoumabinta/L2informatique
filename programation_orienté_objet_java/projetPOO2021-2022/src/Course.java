import java.util.*;
/**la classe Course est une  classe qui permet de créer un objet Course pour la livraison d’un repas.
 * Cette classe a comme attribut Vehicule (vehicule),Salarie (conducteur),PointGPS (localEntreprise) et PointGPS (lieuDeLivraison).
 * C’est une classe dont le constructeur  peut lever une exception
 *  si la charge utile est inférieur au poids à transporter et si le temps de parcours  est plus d’une heure.*/

public class Course{
	/**attributs*/
	private double poidsATransporter;
	private Vehicule vehicule;
	private Salarie conducteur;
	private PointGPS localEntreprise;
	private PointGPS lieuDeLivraison;
	/**constructeur initialise les attributs*/
	public Course(PointGPS localEntreprise,PointGPS lieuDeLivraison,double poidsATransporter,Salarie conducteur,Vehicule vehicule)throws Exception{
		this.conducteur=conducteur;
		this.vehicule=vehicule;
		this.localEntreprise=localEntreprise;
		this.lieuDeLivraison=lieuDeLivraison;
		if(chargeUtile() >= this.poidsATransporter && this.localEntreprise.distance(lieuDeLivraison)/vehicule.vitesseMoyenne()<=10000) {
			this.poidsATransporter = poidsATransporter;
	    }
		else {
			throw new Exception("la charge utile est inférieur au poids à transporter ou le temps de parcours suppérieur à 1");
		}
	}
	/**getPoidsATransporter() retourne le poids à transporter*/
	public double getPoidsATransporter(){
		return this.poidsATransporter;
	}
	/**getLocaLEntreprise() retourne le local de l'entreprise*/
	public PointGPS getLocaLEntreprise(){
		return this.localEntreprise;
	}
	/**getLieuDeLivraison() retourne le lieu de livraison*/
	public PointGPS getLieuDeLivraison(){
		return this.lieuDeLivraison;
	}
	/**elle retourne la charge utile du vehicule si celle ci est supérieur à celle du conducteur
	 *  sinon elle retourne celle du conducteur*/
	public double chargeUtile() {
		if(vehicule.getChargeUtile() > conducteur.chargeUtile()){
			return vehicule.getChargeUtile();
		} else {			
			return  conducteur.chargeUtile();	
		}
	}
	/** quantiteDeCO2() calcul et rétour de la quantité de CO2*/
	public double quantiteDeCO2() {
		return(vehicule.getTauxCO2()*(this.localEntreprise.distance(this.lieuDeLivraison)*2));
	}
	/**prixUneCourse() calcul et rétour du prix d'une course*/
	public double prixUneCourse() {
		return(conducteur.getSalaire()+(vehicule.coutUtilisation()/(this.localEntreprise.distance(this.lieuDeLivraison)*2)));
	}
	/**Retourne vrai si this est pire que la course en parametre*/
	public boolean estPireQue(Course c){
		boolean estPire=false;
		if((this.quantiteDeCO2() > c.quantiteDeCO2() && this.prixUneCourse() > c.prixUneCourse()) 
				||(this.quantiteDeCO2() > c.quantiteDeCO2() && this.prixUneCourse() == c.prixUneCourse()) 
				||(this.quantiteDeCO2() == c.quantiteDeCO2() && this.prixUneCourse() > c.prixUneCourse())) {
			estPire=true;
		}
		return estPire;
	}
	/**retourne le salarié */
	public Salarie getConducteur() {
		return this.conducteur;
	}
	
}
