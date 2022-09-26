/*     Diallo Fatoumata Binta   et Rahaf Abdulla  */
/*     L2 informatique groupe 386N           */
/*     Second TP : pointeurs et tableaux statiques     */

#include<iostream>
#include<string>
#include<string>

using namespace std;

/******************4. Loto(*)***********************/
/*fonction qui accepte en entrée deux paramètres, une valeur et un tableau de 6 entiers.Retourne 1 si la valeur est présente dans le tableau, 0 si la valeur n'apparaît pas*/
int EstPresent(int val,int tab[6]){
    //Debut
    for(int i=0;i<6;i++){
        if(tab[i]==val) return 1;
    }
    return 0;
    //fin
}
//procédure EstPresent
void EstPresentP(int val2,int tab2[6]){
    //Debut
   EstPresent(val2,tab2);
    //fin
}

//procédure SaisieGrille qui effectue la saisie d'une grille.
void SaisieGrille(int* grille){
    //Debut    
        cout<<"saisir "<<endl;
        for(int j=0;j<6;j++){
            int tampon;
            cin>>tampon;
            /*Pour chaque numéro saisi,on vérifie que la valeur est entre 1 et 49 et différente des valeurs précédemment saisies),*/
            while((tampon>49 || tampon<=0)|| (EstPresent(tampon,grille)==1)){
                cout<<"donner un autre numero";
                cin>>tampon; //sinon, on demandera de la resaisir
            }
            grille[j]=tampon;//on introduit la valeur dans le tableau
        }
    //fin
}

/******************fonction main***********************/
int main(){
    //Debut
    //programme qui déclare un tableau de 6 entiers, et les saisit au clavier
    int num_tirage[6];
    cout<<"donner les 6 numeros du tirage du loto"<<endl;
    SaisieGrille(num_tirage);          
    //retourn 1 si 3 est présent dans num_tirage,0 sinon
    cout<<EstPresent(3,num_tirage)<<endl;
    //programme qui, en plus des six numéros du tirage du loto, demande les 6 numéros d'une grille de loto
    int num_grille[6];
    cout<<"donner les 6 numeros d'une grille de loto"<<endl;   
    SaisieGrille(num_grille);          
    cout<<endl<<"les numeros présents sont: ";
    int compt=0;
    for(int i=0;i<6;i++){
    //test et affiche les numéros qui sont présents dans le tirage
        if (EstPresent(num_tirage[i],num_grille) == 1) {
            cout << num_tirage[i]<<endl;
            compt++;
        }
    }  
    cout <<"le nombre de bon numéros est : "<<compt<<endl;//affiche le nombre de bon numéros
    //si on a les 6 bons numéros alors on est le gagnant
    if(compt==6){
        cout<<compt<<" bons numeros "<<"félicitation vous êtes le heureux gagnant"<<endl;
    }
    //avec la procédure EstPresentP
    EstPresentP(4,num_tirage);

    return 0;
    //fin

}
