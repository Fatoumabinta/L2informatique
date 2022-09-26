/**classe CyclisteDebutant est une sous classe de la classe Cycliste ,elle permet de créer un objet CyclisteDebutant 
 * sa vitesse moyenne est de 10 km/h*/
public class CyclisteDebutant extends Cycliste{
	public CyclisteDebutant(String nom,double poids,double salaire) {
		super(nom,poids,salaire,10);
	}
}
