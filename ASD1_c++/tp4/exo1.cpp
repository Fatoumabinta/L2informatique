#include<iostream>
#include<string>

using namespace std;

typedef struct cls_rarete{
    string nom;
    float facteur;
}t_cls_rarete;
typedef struct artefact{
    string nom;
    int magique, poids, prix, quantite;
    t_cls_rarete * classe;
}t_artefact;

typedef struct sac{
    int capacite, occupation;
    t_artefact tab;
}t_sac;

t_sac initSac(){
    t_sac nouveauSac;
    nouveauSac.capacite=4;    
    nouveauSac.occupation=0;    
    return nouveauSac;
}

void agumenterCapaSac(t_sac* sac){
    if(sac->occupation >= ((2*sac->capacite)/3)){
        sac->capacite=(2*sac->capacite);
    }
}

void reduireCapaSac(t_sac* sac){
    if(sac->occupation==((1*sac->capacite)/6)){
    sac->capacite = (sac->capacite/2);
    }
}

void afficherArtefact(t_artefact art){
    cout << art.nom << "," << art.magique << "magie," << art.poids << "kg, type" << (art.classe)->nom << "," << art.prix << "rupee par piece ,"  << art.quantite << "pieces"<<endl;
}

void afficherSac(t_sac sac){
    for(int i=0; i < sac.capacite){
        if(sac.tab.quantite!=0){

        }
    }
}
