//import java.awt.*;
/**la classe PointGPS permet la représentatation d’un point avec les coordonnés x et y*/
import javax.swing.JComponent;

public class PointGPS {
	private int x,y;
	public PointGPS(int x,int y) {
		this.x=x;
		this.y=y;
	}
	public int getX() {
		return this.x;
	}
	public int getY() {
		return this.y;
	}
	public double distance(PointGPS p) {
		double dx = this.x - p.x;
		double dy = this.y - p.y;
		return  Math.sqrt((dx * dx) + (dy * dy));
	}

}
