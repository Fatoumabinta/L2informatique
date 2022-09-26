/*     Diallo Fatoumata Binta   et Rahaf Abdulla  */
/*     L2 informatique groupe 386N           */
/*     Second TP : pointeurs et tableaux statiques     */

#include<iostream>
#include<string>
#include<string>

using namespace std;

/****************** 3. Binome ***********************/
//type t_date pour définir une date avec jour,mois et année
    typedef struct date{
        int annee;
        int jour;
        int mois;
        
    }t_date;
    //type t_personne pour définir une personne avec son nom, son prénom, sa date de naissance, son âge, et son adresse(string)
    typedef struct personne{
        string nom;
        string prenom;
        t_date dateNaissance;
        int age;
        string adresse;

    }t_personne;

/*on va utiliser les attributs de type ‘t_personne*’.’t_personne*’ est un pointeur qui va contenir l’adresse d’une variable de type  t_personne,il  permet d’accéder directement aux informations de la  variable ce qui n’est pas le cas du type ’t_personne’ car avec ce dernier on va manipulé la copie de la variable réelle.Si on veut faire une modification sur les informations de la personne il faut utiliser le pointeur  pour accéder directement aux informations.le pointeur utilise moins d’espace mémoire*/

//structure t_binôme pour définir un binôme entre deux personnes
struct t_binome{
    t_personne* personne1;
    t_personne* personne2;
};

//procédure permettant d’afficher l’information sur un binôme passer en parametre
//cas affichage complet
void affichage_complet(t_binome* b){
    //Debut
   if(b->personne1==NULL && b->personne2==NULL){ //lebinôme n’est pas défini le pointeur est egal à NULL
        cout<<"le binôme n’est pas défini"<<endl;
    }
    else if(b->personne1==NULL||b->personne2==NULL){//le binome est incomplet s'il manque une personne
        cout<<"incomplet"<<endl; 
    } 
   else{//affiche le binome
    cout <<"nom : "<<b->personne1->nom<<endl<<"prenom : "<< b->personne1->prenom <<endl<<"date de naissance : "<< b->personne1->dateNaissance.jour<<" / "<<b->personne1->dateNaissance.mois<<" / "<<b->personne1->dateNaissance.annee<<endl<<"age : "<<b->personne1->age<<endl<<"adresse : "<<b->personne1->adresse<<endl;

  cout <<"nom : "<<b->personne2->nom<<endl<<"prenom : "<< b->personne2->prenom <<endl<<"date de naissance : "<< b->personne2->dateNaissance.jour<<" / "<<b->personne2->dateNaissance.mois<<" / "<<b->personne2->dateNaissance.annee<<endl<<"age : "<<b->personne2->age<<endl<<"adresse : "<<b->personne2->adresse<<endl;
    }
    //fin
}
//cas affichage succinct 
void affichage_succinct(t_binome* b){
    //Debut
    if(b->personne1==NULL && b->personne2==NULL){ 
        cout<<"le binôme n’est pas défini"<<endl;
    }
    else if(b->personne1==NULL||b->personne2==NULL){
        cout<<"incomplet"<<endl; 
    } 
   else{//on affiche le nom et le prenom
    cout <<"nom : "<<b->personne1->nom<<endl<<"prenom : "<< b->personne1->prenom <<endl; 
    cout <<"nom : "<<b->personne2->nom<<endl<<"prenom : "<< b->personne2->prenom <<endl;    
}
    //fin
}

//procédure permettant de créer un binome à partir de deux variables t_personne préexistantes
void p_creer(t_binome* b,t_personne* p1,t_personne* p2){
    //Debut
    if(b != NULL){
    b->personne1=p1;
    b->personne2=p2;
}
    //fin
}

//version fonction en utilisant les pointeurs et les références
t_binome f_creer(t_binome& b,t_personne& p1,t_personne& p2){
    //Debut
    b.personne1 = &p1;
    b.personne2 = &p2;
    return b;
    //fin
}

/******************fonction main***********************/
int main(){
    //Debut
    t_personne p1;//p1 de type t_personne
    p1.nom="Flore";
    p1.prenom="Binta";
    p1.dateNaissance.jour=10;
    p1.dateNaissance.mois=4;
    p1.dateNaissance.annee=1998;
    p1.age=23;
    p1.adresse="3 rue de la fontaine";
    t_personne p2;//p2 de type t_personne
    p2.nom="Bah";
    p2.prenom="Laure";
    p2.dateNaissance.jour=20;
    p2.dateNaissance.mois=6;
    p2.dateNaissance.annee=2000;
    p2.age=21;
    p2.adresse="6 rue de la fontaine";
    t_binome b;//b binome
    //on creer le binome à partir de p1 et p2 avec de la fonction
    f_creer(b, p1,p2);
    //affichage complet
    affichage_complet(&b);//on l'affiche
    t_binome b1,b2;
    b1.personne1=NULL;//tester le cas binome imcomplet 
    b1.personne2=&p2;
    affichage_complet(&b1);
    b2.personne1=NULL;
    b2.personne2=NULL;
    affichage_complet(&b2);//tester le cas binome pas définit
    //affichage succint
    affichage_succinct(&b);
    affichage_succinct(&b1);
    affichage_succinct(&b2);
    //on creer le binome à partir de p1 et p2 avec de la procedure
    p_creer(&b,&p1,&p2);
    return 0;
    //fin
}

