#include<iostream>
#include<string>
using namespace std;

/****************** 1-Tu erre en série ***********************/
//definition de type série qui comporte le nom de la série et l'année de création
struct serie{
    string nom;
    int anneeCreation;
};
//definition de type saison
struct saison{
    serie origine;//origine de la saison de type série 
    int annee;
    int numero;
    int nbEpisodes;//nombre d'épisodes de la saison
};
//definition de type episodes
struct episodes{
    saison provenance;//de quelle saison provient l'épisode
    int numero;//numero de l'épisode 
    string titre;//titre de l'épisode
};
//fonction principale
int main(){
    //Algorithme démoun qui affiche le nom d'une nouvelle série et son année de création
    serie H50, H50bis;
    int an;
    H50.nom = "Hawaii 5.0";
    an = 1968;
    H50.anneeCreation = an;
    H50bis.nom = H50.nom;
    H50bis.anneeCreation = an + 42;
    cout << "nouvelle série" <<" "<< H50bis.nom <<" ";
    cout << "en" <<" " << H50.anneeCreation << endl;

    //Algorithme démodeux affiche le numero d'une saison et le nom de la série de cette saison
    saison ST1;
    ST1.annee = 1966;
    ST1.numero = 1;
    ST1.nbEpisodes = 29;
    ST1.origine.nom = "Star Trek";
    ST1.origine.anneeCreation = ST1.annee;
    cout << ST1.origine.nom <<" "<<"saison"<<" "<<ST1.numero <<endl;
    return 0;
}
