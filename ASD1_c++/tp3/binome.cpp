/*     Diallo Fatoumata Binta   et Rahaf Abdulla  */
/*     L2 informatique groupe 386N           */
/*     Troisième TP : tableaux dynamiques — 1     */
#include<iostream>
#include<string>

using namespace std;

/****************** Binomes ***********************/

/******************premier temps ***********************/
/*type t_etudiante qui stock le numéro étudiant (un entier), une chaine de caractères avec le nom et le prénom, un pointeur vers son binôme (une autre étudiante).*/

typedef struct etudiante{
    int numEtudiant;
    string nomPrenom;
    etudiante* binome;
}t_etudiante;

//fonction qui retourne vrai si l'étudiant passé en parametre à un binome,faux sinon
bool est_en_binome(t_etudiante *e){
    if((*e).binome!=NULL){ 
        return true;
    }
    else{
        return false;
    }
}

/*procédure permettant de modifier le nom d’une étudiante passé en paramètre modifiable*/
void modifNom(t_etudiante* etudiante,string nouveauNom){
    (*etudiante).nomPrenom=nouveauNom;
}

//procédure prenant deux étudiantes en paramètres modifiables et formant un binôme
void formeBinome(t_etudiante* etudiante1,t_etudiante* etudiante2){
    //on ne peut pas former un nouveau binome avec un étudiant qui se trouve déja dans un binome
    if(est_en_binome(etudiante1)==false && est_en_binome(etudiante2)==false){
    etudiante1->binome=etudiante2;
    etudiante2->binome=etudiante1;
    }
}

//procédure prenant une étudiante en paramètre et l’affichant, ainsi que son binôme
void affiche(t_etudiante* etudiante){
    if(est_en_binome(etudiante)==true){
    cout<<"numero etudiant : "<<(*etudiante).numEtudiant<<endl<<"nom et prenom : "<<(*etudiante).nomPrenom<<endl<<"numero etudiant de son binome : "<<etudiante->binome->numEtudiant<<endl<<"nom et prenom de son binome : "<<etudiante->binome->nomPrenom<<endl;
    }
    //s'il n'a pas de binome on l'affiche sans son binome
    else{
    cout<<"numero etudiant : "<<(*etudiante).numEtudiant<<endl<<"nom et prenom : "<<(*etudiante).nomPrenom<<endl<<" (cette étudiante n'a pas de binome) "<<endl;
    }
}

/*procédure prenant une étudiante en paramètre modifiable et détruisant le binôme qu’il  formait*/
void supprimebinome(t_etudiante *etudiante){
    if(est_en_binome(etudiante)==true){
    (*(*etudiante).binome).binome=NULL;
    (*etudiante).binome=NULL;
    }
}

/******************fonction main***********************/
int main(){
    t_etudiante x;
    x.numEtudiant=1;
    x.nomPrenom="Diallo Ama";
    x.binome=&x;
    //appel de la procedure qui modifie le nom 
    modifNom(&x,"Bah Laure");
    
    t_etudiante y;
    y.numEtudiant=2;
    y.nomPrenom="Sow Fifi";
    y.binome=&x;
    //appel de la procedure formebinome
    formeBinome(&x,&y);
    affiche(&y);

/****************** second temps ***********************/
    //declaration de tableau dynamique
    t_etudiante* tab_etudiantes;
    //déclaration et saisie le nombre d’étudiantes
    int nombreEtudiantes;
    cout<<"donner le nombre d'etudientes";
    cin >> nombreEtudiantes;
    //on creer le tableau s'il y'a au moins une étudiante 
    if(nombreEtudiantes > 0){
     tab_etudiantes = new t_etudiante[nombreEtudiantes];
    }
    //si non on affiche un cas d'erreur
    else{
        cout<<"nombre d'étudiantes invalide"<<endl;
    }
    //demande de saisie à l'utilisateur les informations (numéro étu + nom/prénom) sur chaque étudiante
    for(int i=0;i<nombreEtudiantes;i++){
    int numero;
    cout<<"saisir le numero de l'étudiante "<<i+1<<" : ";
    cin >> numero;
    //cas d'erreur si le numero de l'étudiante est inférieur ou égal à 0
    while(numero<=0){
        cout<<"numero d'étudiante incorrects,saisir un numero valide"<<endl;
    cin >> numero;        
    }
    tab_etudiantes[i].numEtudiant=numero;
    cout<<"saisir le nom de l'étudiante "<<i+1<<" : ";
    cin >> tab_etudiantes[i].nomPrenom;
    cout<<endl;
    tab_etudiantes[i].binome = NULL;
    }
      
    /*demande à l’utilisateur de former des binômes en saisissant les numéros étudiants (jusqu’à la saisie de nombre “-1”)*/
for(int i = 0; i < nombreEtudiantes / 2; i++) {
    t_etudiante *etudiante_1;
    t_etudiante *etudiante_2;  

    int num_etudiant_1;
    int num_etudiant_2;
    
    cout<<"saisir le premier numero étudiant pour former binome: ";
    cin >> num_etudiant_1;  
    //le programme s'arrete si l'utilisateur saisit -1   
    if (num_etudiant_1 == -1) {
        cout<<"erreur numero invalide"<<endl;
        break;
    }
// trouver etudiante_1 à partir de numero_etudianet_1
    for(int i=0;i<nombreEtudiantes;i++){
        if (tab_etudiantes[i].numEtudiant== num_etudiant_1) {
            etudiante_1=&tab_etudiantes[i];
        }
    }

    cout<<"saisir le second numero étudiant pour former binome: ";
    cin >> num_etudiant_2;
    //le programme s'arrete si l'utilisateur saisit -1   
    if (num_etudiant_2 == -1) {
        cout<<"erreur numero invalide"<<endl;
        break;
    }    

    // trouver etudiante_2 à partir de numero_etudiante_2
    for(int i=0;i<nombreEtudiantes;i++){
        if (tab_etudiantes[i].numEtudiant== num_etudiant_2) {
            etudiante_2=&tab_etudiantes[i];
        }     
    }
   /*si l'utilisateur essaye de former un binôme pour des étudiantes qui sont déjà en binôme il s'affiche à l'écran que ces étudiants sont déjà dans un binome
    et seul le prémier binome est considéré*/
    if(est_en_binome(etudiante_1)==true){
        cout <<etudiante_1->nomPrenom<<" a déjà un binome"<<endl;
    }
    if(est_en_binome(etudiante_2)==true){
        cout <<etudiante_2->nomPrenom<<" a déjà un binome"<<endl;
    }
    formeBinome(etudiante_1, etudiante_2);//on forme le binome
    }
//Affichage de tous les binômes
cout <<"Binôme : ";
for(int i=0;i<nombreEtudiantes/2;i++){
    if(est_en_binome(&tab_etudiantes[i])==true){
        cout <<tab_etudiantes[i].nomPrenom<<" avec "<<(*tab_etudiantes[i].binome).nomPrenom<<endl;     
    }
}
//Affichage etudiantes sans binomes
cout <<"Sans Binôme : ";
for(int i=0;i<nombreEtudiantes;i++){
    if (est_en_binome(&tab_etudiantes[i])==false) {
            cout<<tab_etudiantes[i].nomPrenom<< "," <<endl;
        }
    } 
cout <<endl;
//detruit tous les binomes et re-affiche la liste d’étudiantes sans binômes
cout <<"étudiantes sans Binôme après avoir detruit tous les binomes : ";
for(int i=0;i<nombreEtudiantes;i++){
    if(est_en_binome(&tab_etudiantes[i])==true){
        supprimebinome(&tab_etudiantes[i]);
    }
    if (est_en_binome(&tab_etudiantes[i])==false) {
        cout<<tab_etudiantes[i].nomPrenom<< ",";
    }
}
cout <<endl;

//desalouer la mémoire alloué au début du programme
delete [] tab_etudiantes;

return 0;
}
