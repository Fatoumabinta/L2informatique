/*   ----- Diallo Fatoumata Binta ------- Rahaf Abdulla ---- */
/* -------  université de Nantes, ----- L2 informatique  -----  groupe 386N-----  */
/*      -------------------  TP4 : chainage  -----------------------------   */
#include<iostream>
#include<string>
using namespace std;
/* ------------------- Exercice1-------------------- */
/*Question 1.a. le message qui commence en C7 est : salut*/
/*Question 1.b. le message qui commence en 09 est : c'est une liste chaineé*/
/*Question 1.c. le message qui commence en 21 est : une autre liste*/

/* ------------------- Exercice2-------Implémentation ------------- */
/*Question 3.a :le nombre  de cases mémoires qui reste allouées dynamiquement par les programmes et sous-programmes est : 6 */
/*   ------------type t_cellule representant les informations une cellule----*/ 
typedef struct cellule{
    char info;
    cellule* suivant;   
}t_cellule;
//Implémentation de l'algorithme
t_cellule* enregistrement(){
    char lettre;
    t_cellule* pcel;
    t_cellule* psuiv;
    t_cellule* tete;
    //debut
    cout<<"une lettre ? (un point pour terminer)";
    cin>>lettre;
    pcel=new t_cellule;
    //debut de la liste
    tete =pcel;
    while(lettre != '.'){
        (*pcel).info=lettre;
        psuiv=new t_cellule;
        (*pcel).suivant=psuiv;
        cout<<"une lettre ? (un point pour terminer)";
        cin>>lettre;
        pcel=psuiv;    
    }
    (*pcel).info=lettre;
    (*pcel).suivant=nullptr;
    return tete;
}
//rôle : affiche un message qui commence à l’adresse pdeb
void affiche(t_cellule* pdeb){
    char lettre;
    t_cellule* pcel;
    //debut)
    pcel=pdeb;
    while(pcel != nullptr){
        lettre=(*pcel).info;
        cout<<lettre;
        pcel=(*pcel).suivant; 
   }
    cout<<endl;
}
//procedure pour désaloué
void desalouer(t_cellule*& pcellule){
    if(pcellule!=nullptr){
        desalouer(pcellule->suivant);
        delete pcellule;
        pcellule=nullptr;
    }
}
//Fonction creer un chainage à partir d'une chaine de caractere donné
t_cellule* creerAPartirDeChaiCarac(string c){
    t_cellule* pcl;
    t_cellule* tete;
    //t_cellule* psuiv;
    pcl=new t_cellule;
    //pcl->info=c[0];
    tete=pcl;
    for(int i=0;i<c.size();i++){        
        cout<<c[i];
        pcl->info=c[i];
        pcl->suivant=new t_cellule;
        pcl=pcl->suivant;
    }  
    return tete;
}

/*---------------------fonction principale--------------------*/
int main(){
    t_cellule* pcel1;//pointeur null vers t_cellule
    t_cellule* pcel2;//pointeur null vers t_cellule
    //debut
    enregistrement();//appel à la fonction enregistrement
    pcel1=enregistrement();
    affiche(pcel1);//affichage
    pcel2=creerAPartirDeChaiCarac("hello");
    cout<<endl;
    /*------------------desallocation-------------------------*/
    desalouer(pcel1);
    desalouer(pcel2);

    return 0;
}
