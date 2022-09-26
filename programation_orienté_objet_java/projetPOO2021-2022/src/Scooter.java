/**classe Scooter est une sous classe de Vehicule,elle permet de créer un objet Scooter
 * Un scooter a une charge utile en kilogrammes, une cylindrée en centimètres cube et une consom-
mation moyenne d’essence en litres par 100 kilomètres. Sa vitesse moyenne est de 30 kilomètres
par heure plus sa cylindrée divisée par 50. Son taux d’émission de CO2 est égal à sa cylindrée
divisée par 4. Son coût d’utilisation sur un kilomètre est égal au prix d’achat divisé par 20000
plus le coût de la consommation d’essence (en fonction du prix d’un litre d’essence qui sera
représenté par une variable dont la valeur est fixée, par exemple 1, 65 euros).*/
public class Scooter extends Vehicule{
	private double cylindree,consommationMoyEssence;
	private static final double prixUnLitreEssence=1.50;
	
	public Scooter(String nom,double prixAchatScooter,double chargeUtile,double cylindree,double consommationMoyEssence) {
		super(nom,prixAchatScooter,cylindree/4,chargeUtile);
		this.cylindree=cylindree;
		this.consommationMoyEssence=consommationMoyEssence;
	}
	public double vitesseMoyenne(){
		double vm=30+(this.cylindree/50);
		return vm;
	}
	public double coutUtilisation() {
		double coutConsommationEssenceSurUnkm=((consommationMoyEssence/100)*prixUnLitreEssence);
		double c;
		c=((getPrix()/20000)+coutConsommationEssenceSurUnkm);
		return c;
	}
}
