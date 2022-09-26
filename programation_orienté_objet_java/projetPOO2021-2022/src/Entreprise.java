import java.util.ArrayList;
import java.util.List;
/**la classeEntreprise permet la représentatation d’un objet Entreprise ,cette contient une liste de  course,
 * c’est dans cette classe que nous allons déterminé les courses optimales et celles qui émettent moins de CO2*/
public class Entreprise{
	private ArrayList<Course> l_course;
	private ArrayList<Course> l_coursesOptimales;
	private ArrayList<Course> l_courseMoinsDeCO2Emis;
	/**constructeur qui initialises les listes à des listes vides*/
	public Entreprise() {
		this.l_course = new ArrayList<Course>();
		this.l_coursesOptimales = new ArrayList<>();
		this.l_courseMoinsDeCO2Emis = new ArrayList<>();
	}
	/**methodes qui permet d'ajouté une course ,elle retourne la liste des courses possibles*/
	public ArrayList<Course> coursePossibles(Course c){
		l_course.add(c);
		return l_course;
	}
	public boolean RepaSeraLivrer(){
			return l_course.size()!=0;
	}
	/**methode qui retourne la liste des courses optimales*/
	public ArrayList<Course> coursesOptimales(){
		if(RepaSeraLivrer()){
			Course meilleurCourse=l_course.get(0) ;
			for(int i=1;i<l_course.size();i++){
				if(meilleurCourse.estPireQue(l_course.get(i))){
					
					meilleurCourse = l_course.get(i) ;				}
			}
			for(int i=0;i<l_course.size();i++) {
				if((l_course.get(i).quantiteDeCO2()==meilleurCourse.quantiteDeCO2())&& (l_course.get(i).prixUneCourse()==meilleurCourse.prixUneCourse())){
						l_coursesOptimales.add(l_course.get(i));
				}
			}
		}
		return l_coursesOptimales;	
	}
	
	/**methode qui retourne la liste des courses avec la quantité minimale de CO2*/
	public ArrayList<Course> l_courseMoinsDeCO2Emis(){
		if(RepaSeraLivrer()) {
			double quantiteMinimaleDeCO2;
			quantiteMinimaleDeCO2=l_course.get(0).quantiteDeCO2();
			for(int i=0;i<l_course.size();i++) {
				if(l_course.get(i).quantiteDeCO2()<quantiteMinimaleDeCO2){//l_course.get(i).moinsDeCO2(l_course.get(i+1))
					quantiteMinimaleDeCO2=l_course.get(i).quantiteDeCO2();//l_course.get(i+1)=l_course.get(i)
				}
			}
			for(int i=0;i<l_course.size();i++) {
				if(l_course.get(i).quantiteDeCO2()==quantiteMinimaleDeCO2){//if(l_course.get(i).quantiteDeCO2()==l_course.get(i+1).quantiteDeCO2())
					l_courseMoinsDeCO2Emis.add(l_course.get(i));
				}
			}
		}
		return l_courseMoinsDeCO2Emis;
	}
	/**affiche les nom des conducteurs dont les courses sont optimales*/
	public void afficherNoMCoursierOptimales(){
		for(int i=0;i<l_coursesOptimales.size();i++) {
		System.out.println(
				l_coursesOptimales.get(i).getConducteur().getNom());				
		}
	}
	/**affiche les nom des conducteurs dont les courses sont possibles*/
	public void afficherNoMCoursierPossibles(){
		for(int i=0;i<l_course.size();i++) {
		System.out.println(
				l_course.get(i).getConducteur().getNom());				
		}
	}
		/**affiche les nom des conducteurs dont les courses sont possibles*/
	public void afficherNoMCoursierMoinsDeCO2(){
		for(int i=0;i<l_courseMoinsDeCO2Emis.size();i++) {
			System.out.println(
					l_courseMoinsDeCO2Emis.get(i).getConducteur().getNom());				
			}
		
	}
}
