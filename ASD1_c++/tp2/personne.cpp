/*     Diallo Fatoumata Binta   et Rahaf Abdulla  */
/*     L2 informatique groupe 386N           */
/*     Second TP : pointeurs et tableaux statiques     */

#include<iostream>
#include<string>
#include<string>

using namespace std;

/****************** 2. Personne ***********************/
/****************** définitions de types ***********************/
//type t_date pour définir une date avec jour,mois et année
    typedef struct date{
        int annee;
        int jour;
        int mois;//entre 1 et 12
        
    }t_date;
    //type t_personne pour définir une personne avec son nom, son prénom, sa date de naissance, son âge, et son adresse(string)
    typedef struct personne{
        string nom;
        string prenom;
        t_date dateNaissance;
        int age;
        string adresse;

    }t_personne;

    //procédure permettant d'afficher l’information d’une personne passée en paramètre avec 't_personne'
    void afficher1(t_personne x){
        //Debut
        cout <<"nom : "<<x.nom<<endl<<"prenom : "<< x.prenom <<endl<<"date de naissance : "<< x.dateNaissance.jour<<" / "<<x.dateNaissance.mois<<" /  "<<x.dateNaissance.annee<<endl<<"age : "<<x.age<<" ans"<<endl<<"adresse : "<<x.adresse<<endl;
    //fin
    }

  /*il est mieux d’utiliser ‘t_personne*’ pour la procédure permettant d'afficher l’information d’une personne passée en paramètre, le pointeur  vers  t_personne nous permet d’accéder directement à la personne et non pas à une copie.Avec ‘t_personne’  la procédure manipule une copie de la valeur de personne */

    //procédure permettant d'afficher l’information d’une personne passée en paramètre avec 't_personne*' un pointeur vers t_personne.
    void afficher2(t_personne* x){//x->nom
        //Debut
          cout <<"nom : "<<(*x).nom<<endl<<"prenom : "<< (*x).prenom <<endl<<"date de naissance : "<< (*x).dateNaissance.jour<<" / "<<(*x).dateNaissance.mois<<" /  "<<(*x).dateNaissance.annee<<endl<<"age : "<<(*x).age<<" ans"<<endl<<"adresse : "<<(*x).adresse<<endl;
    //fin
    }

    //fonction permettant de lire les informations d'une personne saisies via le clavier
    t_personne liref(){
        //Debut
        t_personne y;
        cout<<"donner le nom"<<endl;
        cin>>y.nom;
        cout<<"donner le prenom"<<endl;
        cin>>y.prenom;
        cout<<"donner la date de naissance"<<endl;
        cin>> y.dateNaissance.jour;
        cin>>y.dateNaissance.mois;
        cin>>y.dateNaissance.annee;
        cout<<"donner  l'age"<<endl;
        cin>>y.age;
        cout<<"donner l'adresse"<<endl;
        cin>>y.adresse;
        return y;//on retourne une copie(genre photocopie)
    //fin
    }

/*Analyse des avantages et inconvénients de la version procédure et  fonction permettant de lire les informations d'une personne saisies via le clavier.
procédure:avantage on utilise moins d'espace mémoire,l’inconvénient est que la procédure modifie les informations  de la personne passé en paramètre
fonction:l’inconvénient est qu’on va utiliser beaucoup d’espace mémoire car à chaque appel de la fonction le programme va réserver un espace mémoire,la complexité sera plus grande comparé à la procédure,l’avantage il n’y a pas de risque de modification d’information d’une variable. */ 

    //procédure permettant de lire les informations d'une personne saisies via le clavier
    void lirep(t_personne* y){
        //Debut
        cout<<"donner le nom"<<endl;
        cin>>(*y).nom;
        cout<<"donner le prenom"<<endl;
        cin>>(*y).prenom;
        cout<<"donner la date de naissance"<<endl;
        cin>>(*y).dateNaissance.jour;
        cin>>(*y).dateNaissance.mois;
        cin>>(*y).dateNaissance.annee;
        cout<<"donner son age"<<endl;
        cin>>(*y).age;
        cout<<"donner son adresse"<<endl;
        cin>>(*y).adresse;
     //fin      
}

//procédure d’affichage et de saisie de t_personne en utilisant les références
void affsaisie(t_personne &z){
    //Debut
    afficher2(&z);
    lirep(&z);
    //fin
}

/******************fonction main***********************/
int main(){
     //Debut
    //definition d'une personne avec ses attributs 
    t_personne inconnu;
    inconnu.nom="Diallo";
    inconnu.prenom="Ama";
    inconnu.dateNaissance.jour=10;
    inconnu.dateNaissance.mois=4;
    inconnu.dateNaissance.annee=1998;
    inconnu.age=23;
    inconnu.adresse="4 rue de la fontaine";
    afficher1(inconnu);//afficher l’information de la copie d'inconnu
    afficher2(&inconnu);//afficher l’information d'inconnu 
    liref();//lit les informations d'inconnu saisies via le clavier
    lirep(&inconnu);//modifie les informations d'inconnu par des informations saisies via le clavier
    affsaisie(inconnu);//appel de la procédure d’affichage et de saisie de t_personne avec les références
    return 0;
    //fin
}
