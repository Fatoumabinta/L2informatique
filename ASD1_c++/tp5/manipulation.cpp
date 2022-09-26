/*   ----- Diallo Fatoumata Binta ------- Rahaf Abdulla ---- */
/* -------  université de Nantes, ----- L2 informatique  -----  groupe 386N -----  */
/*      -------------------  TP4 : chainage  -----------------------------       */
#include<iostream>
#include<string>
using namespace std;
/* ------------------- Exercice3-------------------- */
/* ------------------- Manipulations ------------- */

/*Question 7.b Discutons de l’intérêt de maintenir le chaînage trié en termes de complexité temporelle et spatial: Maintenir le chainage trié permet de retrouver un élément de la chaine plus facilement,cela permet égalment de répetorier la chaine facilement en catégorie,ainsi de comparer ses  éléments facilement*/

/*   ------------type t_seance representant les informations une seance----*/ 
typedef struct seance{
    int numeroSemaine;//le numero de la semaine auquel se fera la séance
    int jourSemaine; // le jour auquel se fera la séance(1=lundi, 2=mardi, ...)
    int heures; //l'heure de la séance(de 8h à 18h)
    int minutes; //minutes de la séance(0 ou 30)
    seance* seanceSuivante;//un pointeur vers la séance suivante
}t_seance;

/*Question 5.a : fonction prenant en paramètre un pointeur vers une première t_seance et donnant le nombre total de séances prévues dans le chaînage */
int nbSeance(t_seance* seance1){
    t_seance* ssuiv;
    int compte=0;
    ssuiv=seance1;
    if(seance1!=nullptr){
        while(ssuiv!=nullptr){
                compte+=1;
                ssuiv=ssuiv->seanceSuivante;
        }
    }
    return compte+1;
}    
/*Question 5.b : procedure prenant en paramètre un pointeur vers un t_seance et affichant pour chaque séance du chaînage sur une ligne le numéro de la semaine, le jour et l’heure*/
void afficher(t_seance* seance1){
    t_seance* ssuiv;
    ssuiv=seance1;
    if(seance1!=nullptr){
        while(ssuiv!=nullptr){//ou si son suivant est different de nullptr
            cout<<"semaine "<<ssuiv->numeroSemaine;
            if(ssuiv->jourSemaine==1){
                cout<<" lundi ";
            }
            if(ssuiv->jourSemaine==2){
                cout<<" Mardi ";
            }
            if(ssuiv->jourSemaine==3){
                cout<<" Mercredi ";
            }
            if(ssuiv->jourSemaine==4){
                cout<<" Jeudi ";
            }
            if(ssuiv->jourSemaine==5){
                cout<<" Vendredi ";
            }
            if(ssuiv->jourSemaine==6){
                cout<<" Samedi ";
            }
            cout<<ssuiv->heures<<"h"<<ssuiv->minutes<<endl;
            ssuiv=ssuiv->seanceSuivante;
        }
    }
}
/*Question 5.c : Procedure prenant en paramètre un pointeur vers un t_seance et désalloue tout le chaînage commençant avec ce pointeur*/
void desalouer(t_seance*& pseance){
    if(pseance!=nullptr){
        desalouer(pseance->seanceSuivante);
        delete pseance;
        pseance=nullptr;
    }
}
/*Question 6.a :Fonction prenant en paramètre un pointeur vers un t_seance et les informations d’un créneau (semaine, jour,heures et minutes) et ajoutant une séance au chaînage donné*/
t_seance* ajouter(t_seance* pseance,int numSemaine,int jSemaine,int h,int min){
    t_seance* creneau=new t_seance;
    creneau->numeroSemaine=numSemaine;
    creneau->jourSemaine=jSemaine;
    creneau->heures=h;
    creneau->minutes=min;
    creneau->seanceSuivante=pseance;
   return creneau;
}

/*Question 6.b :Fonction prenant en paramètre un pointeur vers un t_seance et les informations d’un créneau et supprimant la séance correspondante du chaînage donné,si e créneau n’y figure pas il y'a un affichage et on retoure le chaiage*/
t_seance* supprimer(t_seance* pseance,int numSemaine,int jSemaine,int h,int min){
    t_seance* creneau;
    t_seance* csuiv;
    creneau=pseance;
    csuiv=pseance;
    if(pseance==nullptr){
        return nullptr;
    }
    //si la tete est notre cellule à supprimer
    else if(pseance->numeroSemaine==numSemaine && pseance->jourSemaine==jSemaine && pseance->heures==h && pseance->minutes==min){
        creneau=pseance->seanceSuivante;
        delete(pseance);
       // pseance=nullptr;
        return creneau;
    }
    else{
        while(creneau->seanceSuivante!=nullptr && (creneau->seanceSuivante->numeroSemaine!=numSemaine ||
       creneau->seanceSuivante->jourSemaine!=jSemaine || creneau->seanceSuivante->heures!=h || creneau->seanceSuivante->minutes!=min)){
            creneau=creneau->seanceSuivante;
        }
        if (creneau->seanceSuivante != nullptr) {
            csuiv=creneau->seanceSuivante;
            creneau->seanceSuivante=csuiv->seanceSuivante;       
            delete(csuiv);
           // csuiv=nullptr;
            return pseance;
        }
         else {
            cout<<"ce créneau ne figure pas"<<endl;
            return pseance;
        }
    }

}
/*Question 6.c :Foction prenant en paramètre un pointeur vers un t_seance et les informations d’un créneau et donnant le nombre de séances prévues (restantes) après (strictement) ce créneau.*/
int seanceRestante(t_seance* pseance,int numSemaine,int jSemaine,int h,int min){
    int compte=0;
    while(pseance != nullptr) {
        bool memeSemaine = pseance->numeroSemaine == numSemaine;
        bool memeJour =  pseance->jourSemaine == jSemaine;
        bool memeHeure = pseance->heures == h;
        bool memeMinute = pseance->minutes == min;

        if (pseance->numeroSemaine>numSemaine || (memeSemaine && pseance->jourSemaine>jSemaine) || (memeSemaine && memeJour && pseance->heures > h) || (memeSemaine && memeJour && memeHeure && pseance->minutes > min)){
            compte+=1;
            //precedent = pseance;
            pseance = pseance->seanceSuivante;        
        }  else {
            break;
        }    
}
    return compte;
}

/*Question 7.a: Refaire les questions 6.On suppose que le chaînage est maintenu en permanence trié*/
/*Question 6.a :Fonction prenant en paramètre un pointeur vers un t_seance et les informations d’un créneau et ajoutant une séance au chaînage donné trié*/
t_seance* ajouterTrie(t_seance* pseance,int numSemaine,int jSemaine,int h,int min){
t_seance* precedent = nullptr;
t_seance* tete = pseance;

while(pseance != nullptr) {
    bool memeSemaine = pseance->numeroSemaine == numSemaine;
    bool memeJour =  pseance->jourSemaine == jSemaine;
    bool memeHeure = pseance->heures == h;
    bool memeMinute = pseance->minutes == min;

    if (pseance->numeroSemaine<numSemaine || (memeSemaine && pseance->jourSemaine<jSemaine) || (memeSemaine && memeJour && pseance->heures < h) || (memeSemaine && memeJour && memeHeure && pseance->minutes < min)){
        precedent = pseance;
        pseance = pseance->seanceSuivante;        
    }  else {
        break;
    }
}
// precedentpeut etre null 
//pseance peut etre null
// ici
t_seance* creneau=new t_seance;
//t_seance* suiv;
creneau->numeroSemaine=numSemaine;
creneau->jourSemaine=jSemaine;
creneau->heures=h;
creneau->minutes=min;
creneau->seanceSuivante=pseance;

if (precedent!=nullptr) {
    precedent->seanceSuivante = creneau;
    return tete;
} else {
    return creneau;
}

}
/*Question 6.b :Pour le sous-algorithme de suppression il ne depend pas de l'ordre des éléments du chainage Donc il reste le meme pour le chainage trié et non trié*/

/*Question 6.c :Foction prenant en paramètre un pointeur vers un t_seance et les informations d’un créneau et donnant le nombre de séances prévues (restantes) après (strictement) ce créneau(chainege trié)*/
int seanceRestanteTrie(t_seance* pseance,int numSemaine,int jSemaine,int h,int min){
    t_seance* creneau;
    //t_seance* csuiv;
    t_seance* nvtete;
    creneau=pseance;
    int compte=0;
   //csuiv=pseance;
    if(pseance==nullptr){
        return 0;
    }
    else if(pseance->numeroSemaine==numSemaine && pseance->jourSemaine==jSemaine && pseance->heures==h && pseance->minutes==min){
        while(creneau->seanceSuivante!=nullptr){
            creneau=creneau->seanceSuivante;
            compte+=1;
        }
        return compte;
    }
    else{
         while(creneau!=nullptr && (creneau->numeroSemaine!=numSemaine ||
       creneau->jourSemaine!=jSemaine || creneau->heures!=h || creneau->minutes!=min)){
            creneau=creneau->seanceSuivante;
        }
    
        if (creneau != nullptr) {
            creneau=creneau->seanceSuivante;
            while(creneau!=nullptr){
                creneau=creneau->seanceSuivante;
                compte+=1;
            }
            return compte;
        }
        return compte;
    }
}
/*Question 8 :algorithme de fusion de deux chaînages de séances, avec suppression des doublons*/
/*première version Fonction on construit un nouveau chaînage sans détruire les deux autres*/
t_seance* fusionnerDansUnNouveauChainage(t_seance* tete1, t_seance* tete2){
    t_seance* ns=nullptr;
    t_seance* temp1=tete1;
    t_seance* temp2=tete2;
    if(temp1==nullptr&&temp2!=nullptr){
        return temp2;
    } else if (temp1!=nullptr&&temp2==nullptr){
        return temp1;
    } else if(temp1!=nullptr&&temp2!=nullptr) {
        while(temp1!=nullptr){
            ns=ajouterTrie(ns,temp1->numeroSemaine,temp1->jourSemaine,temp1->heures,temp1->minutes);
            temp1=temp1->seanceSuivante;
        }
        while(temp2!=nullptr){
            ns=ajouterTrie(ns,temp2->numeroSemaine,temp2->jourSemaine,temp2->heures,temp2->minutes);
            temp2=temp2->seanceSuivante;
        }
        temp1=ns;
        while(temp1->seanceSuivante!=nullptr){
            if((temp1->numeroSemaine==temp1->seanceSuivante->numeroSemaine)&&(temp1->jourSemaine==temp1
            ->seanceSuivante->jourSemaine)&&(temp1->heures==temp1->seanceSuivante->heures)&&(temp1->minutes==temp1->seanceSuivante->minutes)){
                ns=supprimer(ns,temp1->numeroSemaine,temp1->jourSemaine,temp1->heures,temp1->minutes);
            }
            temp1=temp1->seanceSuivante;
        }
        return ns;
    } else { return nullptr;}
}

/*seconde version Fonction qui modifie sur place le premier chaînage en détruisant le second*/
t_seance* fusionner2(t_seance* tete1, t_seance* tete2){
    t_seance* temp=tete2;
    if(temp!=nullptr){
        while(temp!=nullptr){
            tete1=ajouterTrie(tete1, temp->numeroSemaine, temp->jourSemaine, temp->heures, temp->minutes);
            temp=temp->seanceSuivante;
        }
        temp=tete1;
        while(temp->seanceSuivante!=nullptr){
            if((temp->numeroSemaine==temp->seanceSuivante->numeroSemaine)&&(temp->jourSemaine==temp
            ->seanceSuivante->jourSemaine)&&(temp->heures==temp->seanceSuivante->heures)&&(temp->minutes==temp->seanceSuivante->minutes)){
                tete1=supprimer(tete1,temp->numeroSemaine,temp->jourSemaine,temp->heures,temp->minutes);
            }
            temp=temp->seanceSuivante;
        }
        //desallouer(tete2);
    }
    return tete1;
}

/*---------------------fonction principale--------------------*/
int main(){
    t_seance* ps=nullptr;//pointeur null vers t_seance 
    t_seance* tete=nullptr;//pointeur null vers t_seance 
    t_seance* tete1=nullptr;//pointeur null vers t_seance 
    t_seance* tete2=nullptr;//pointeur null vers t_seance 
    t_seance* fusionne1=nullptr;//pointeur null vers t_seance 
    t_seance* fusionne2=nullptr;//pointeur null vers t_seance 
    /*------------chainage non trié------------*/
    cout<<"---------------chainage non trié------------------"<<endl;
    /*appel de la fontion ajouter*/
    ps=ajouter(ps,1,1,8,00);
    ps=ajouter(ps,1,2,11,00);
    ps=ajouter(ps,1,3,9,30);
    //desalouer(ps);
    //desalouer(tete);
    afficher(ps);//affichage du chainage
    cout<<"-----suppression d'un maillon------"<<endl;
    ps=supprimer(ps,1,2,11,0);//on supprime un maillon
    afficher(ps);//affichage du chainage après suppression d'un maillon
    cout<<"---Nombre de éances restantes après les informations données--"<<endl;
    cout<<seanceRestante(ps,1,1,8,0)<<" seances restantes"<<endl;//le nombre de seance restante
    /*------------chainage trié------------*/
    cout<<"------------------chainage trié-------------------------"<<endl;
    /*ajouter au chainage*/
    tete=ajouterTrie(tete,1,1,1,20);
    tete=ajouterTrie(tete,1,3,3,00);
    tete=ajouterTrie(tete,1,2,3,00);
    tete=ajouterTrie(tete,1,1,1,19);
    tete=ajouterTrie(tete,1,5,1,19);
    afficher(tete);//affichage
    cout<<"---Nombre de séances restantes après les informations données-"<<endl;
    cout<<seanceRestanteTrie(tete,1,2,3,0)<<endl;

    /*---chainage1 trié---*/
    tete1=ajouterTrie(tete1,1,1,8,00);
    tete1=ajouterTrie(tete1,1,2,14,00);

    /*---chainage2 trié---*/
    tete2=ajouterTrie(tete2,1,1,8,30);
    tete2=ajouterTrie(tete2,1,3,15,30);
    tete2=ajouterTrie(tete2,2,4,8,00);
 
    /*------------------chainage de fusion-------------------------*/
    cout<<"--------------chainage fusionne1----------"<<endl;
    fusionne1=fusionnerDansUnNouveauChainage(tete1,tete2);
    afficher(fusionne1);
    cout<<"--------------chainage fusionne2----------"<<endl;
    fusionne2=fusionner2(tete1,tete2);
    afficher(fusionne2);

    /*------------------desallocation-------------------------*/
    desalouer(ps);
    desalouer(tete);
    desalouer(tete1);
    desalouer(tete2);
    desalouer(fusionne1);
    desalouer(fusionne2);

    return 0;
}
