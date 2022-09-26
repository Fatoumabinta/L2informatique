#include<iostream>
#include<string>
using namespace std;

/****************** 2 - Enregistrements audio ***********************/

/*définition de types. Un disque audio est caractérisé par son titre, son éditeur et son année d’édition. Il contient en outre une liste de pistes : on
supposera qu’il y en a exactement 3 pour cet exercice (single) ; chaque piste est elle même caractérisée par son titre, son
artiste et sa durée. Une durée est exprimée en minutes et secondes entières */
struct Duree{
    int min, sec;
};
struct PisteAudio{
    string titre, artiste;
    Duree duree;
};
struct DisqueAudio{
    string titre,editeur;
    int annee;
    PisteAudio piste1, piste2, piste3;
};

//fonction principale
int main(){
    DisqueAudio disquePerso;//variable disquePerso de type DisqueAudio
    Duree duree;//variable duree de type Duree
    //affichage du titre du disque
    cout << disquePerso.titre;
    //changement de l’éditeur du disque en « Université de Nantes »
    disquePerso.editeur = "université de Nantes";
    //intituler le disque par la concaténation des artistes de ses trois pistes
    disquePerso.titre = disquePerso.piste1.artiste + disquePerso.piste2.artiste + disquePerso.piste3.artiste;
    //ajout de 1 minute et 30 secondes à la durée de la 2e piste du disque 
    if(duree.sec < 30){
        disquePerso.piste2.duree.min = disquePerso.piste2.duree.min +1;
        disquePerso.piste2.duree.sec = disquePerso.piste2.duree.sec + 30;    
    }
    else if(duree.sec >= 30){
        disquePerso.piste2.duree.min = disquePerso.piste2.duree.min +2; 
        disquePerso.piste2.duree.sec = disquePerso.piste2.duree.sec - 30;           
    }
    //vérification que les titres des trois pistes sont bien en ordre alphabétique 
    disquePerso.piste1.titre <= disquePerso.piste2.titre;
    disquePerso.piste2.titre <= disquePerso.piste3.titre;    
    return 0;
}
