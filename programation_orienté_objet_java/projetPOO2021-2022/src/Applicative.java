import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
/**Fonction principale*/
public class Applicative {
	public static void main(String arg[]){
		
		Vehicule vehicule1=new Velo("v1",3500,new CyclisteDebutant("Cyclou",70,10));
		Salarie salarie1=new CyclisteDebutant("Jade",70,8);
		PointGPS localEntreprise=new PointGPS(1,10);
		PointGPS lieuDeLivraison=new PointGPS(20,10);
		//RepasATransporter repas1=new RepasATransporter(4.5,4);
		//boolean seraLivrer;
		try {
		System.out.println("-----les courses possibles-----");
		Course course1=new Course(localEntreprise,lieuDeLivraison,4,salarie1,vehicule1);
		Course course2=new Course(new PointGPS(1,100),new PointGPS(220,100),4,new ConducteurDeScooter("Alfred",80,9),new Scooter("Yamama",1000,20,55,5));
		Course course3=new Course(new PointGPS(1,100),new PointGPS(220,100),4,new CyclisteExpert("Anna",67,8),new Velo("Vavite",200,new  CyclisteExpert("cyclisteExpert1",70,20)));
		Entreprise entreprise1=new Entreprise();
		entreprise1.coursePossibles(course1);
		entreprise1.coursePossibles(course2);
		entreprise1.coursePossibles(course3);
		entreprise1.afficherNoMCoursierPossibles();
		System.out.println("------les coursiers optimales---");
		entreprise1.coursesOptimales();
		entreprise1.afficherNoMCoursierOptimales();
		System.out.println("------les coursiers qui emmettent moins de CO2---");
		entreprise1.l_courseMoinsDeCO2Emis();
		entreprise1.afficherNoMCoursierMoinsDeCO2();	
		 JFrame f = new JFrame("Dessiner un cercle");
		    Trajet dessine = new Trajet(entreprise1);
		    f.getContentPane().add(dessine);
		    f.setSize(250, 250);
		    f.setVisible(true);
		    f.setResizable(false);
		    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}

}
