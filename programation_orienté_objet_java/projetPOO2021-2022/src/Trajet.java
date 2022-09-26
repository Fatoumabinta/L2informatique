import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.Timer;

/** La classe Trajet est une sous classe de  ‘JComponent’ et ‘ActionListener’,elle a comme donné la position du Livreur,
 * De l'entreprise et du lieu de la livraison. 
 * Cette classe nous permet de faire le graphique:le local de l’entreprise est représenté par un rectangle vert,
 *  le lieu de livraison par un rectangle rouge et le salarié qui effectue la livraison par un cercle bleu.
 *   Cette classe permet de voir la position du livreur en temps réels.*/
public class Trajet extends JComponent implements ActionListener{
	//attributs
	Entreprise entreprise;
	private int xLivreur; 
	private int yLivreur;
	
	private int xEntreprise;
	private int yEntreprise;
	
	private int xLivraison;
	private int yLivraison;
	/**constructeur*/
	public Trajet(Entreprise entreprise) {
		this.entreprise=entreprise;
		xLivreur=entreprise.coursesOptimales().get(0).getLocaLEntreprise().getX();
		yLivreur=entreprise.coursesOptimales().get(0).getLocaLEntreprise().getY();
		xLivraison=entreprise.coursesOptimales().get(0).getLieuDeLivraison().getX();
		yLivraison=entreprise.coursesOptimales().get(0).getLieuDeLivraison().getY();
		xEntreprise=entreprise.coursesOptimales().get(0).getLocaLEntreprise().getX();
		yEntreprise=entreprise.coursesOptimales().get(0).getLocaLEntreprise().getY();
		timer = new Timer(1000, this);//il bouge chaque les une seconde 
		timer.start();	
	}
	
	private int dx = 10;	
	private Timer timer;
	/** la méthode paint permet la représentation des objets*/
	public void paint(Graphics g){
	    g.setColor(Color.blue);
	    g.drawOval(xLivreur, yLivraison, 15, 15); //abscisse,ordonné,largeur du cercle,hauteur du cercle 
	    g.setColor(Color.red);
	    g.drawRect(xLivraison, yLivraison, 13, 13); 
	    g.setColor(Color.green);
	    g.drawRect(xEntreprise, yEntreprise, 13, 13); 
	}
	/**cette permet de connaitre la position du livreur à temps réel */	    
	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("Dessine.actionPerformed()");
		if (xLivreur < xLivraison) {
//			yLivraison+= dy;
			xLivreur += dx;
			repaint();
		} else {
			timer.stop();
		}
	}
		
}
