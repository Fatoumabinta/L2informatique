#include<iostream>
#include<string>
using namespace std;

/****************** 4- Dates ***********************/
//type instant comportes les entiers h(heure),min(minute),sec(seconde)
struct instant{
    int h,min,sec;
};
//ecrireInstant permet d'afficher sous forme agréable un instant
void ecrireInstant(instant moment){
 //   cin >> moment.h;
    cout << moment.h << moment.min << moment.sec <<endl;
}
//fonction qui permet de saisir auprès de l’utilisateur un instant
instant saisirInstant(void){
    instant saisie;
    cout <<"saisissez un instant(heure,minute,seconde):"<<endl;
    cin >> saisie.h ;
    cin >> saisie.min;
    cin >> saisie.sec;
    return saisie;
}
//fonction qui permet d'ajouter une seconde
instant ajouteUneSeconde(instant moment){
    instant nouveau;
    int retenue;
    nouveau.sec = (moment.sec + 1) % 60;
    retenue = (moment.sec + 1) /60;
    nouveau.min = (moment.min + retenue) % 60;
    retenue = (moment.min + retenue) / 60;
    nouveau.h = (moment.h + retenue) % 24;
    cout <<"ajoutons une seconde,on obtient:";
    ecrireInstant(nouveau);
    return nouveau;
}
void tempsEcoule(instant initial, instant finall){
    //on suppose ici que l'instant initial vient avant l'instant final
    int c=0;
    while (initial.h != finall.h){//initial.min != final.min, initial.sec != initial.sec
        initial = ajouteUneSeconde(initial);
        c = c+1;    
    }    

}
void estAvant(instant t1, instant t2){
    if ((t1.h < t2.h) || ((t1.h == t2.h) && (t1.min < t2.min)) || ((t1.h == t2.h) && (t1.min == t2.min) && (t1.sec < t2.sec))){
        ecrireInstant(t1);
        cout << "est bien avant";
        ecrireInstant(t2);
    }
    else {
        ecrireInstant(t1);
        cout << "n'est pas avant";
        ecrireInstant(t2);
    }

}
//fonction principale
int main(){
    instant moment = saisirInstant();
    ecrireInstant(moment);
    //cout << "Entrer les deux instants,..seconde";
    instant initial = saisirInstant();
    instant finall = saisirInstant();
    tempsEcoule(initial, finall);   
    return 0;
}


