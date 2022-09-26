/**la classe Cycliste est une sous classe de la classe Salarie,elle permet de créer un objet cyliste 
 * cycliste sportif sa vitesse moyenne est de 15km/h*/
public class CyclisteSportif extends Cycliste{
	public CyclisteSportif(String nom,double poids,double salaire) {
		super(nom,poids,salaire,15);
	}
}
