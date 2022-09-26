#include<iostream>
#include<string>
using namespace std;

/****************** 3 - Combien ***********************/
//fonction principale
int main(){

    int nb, toto, cpt;//trois variables de type entier
//portion 0
    cin >> nb;
    toto = 0;
    cpt = 0;
    while(cpt <= nb){
        toto = toto + cpt;
        cpt = cpt + 1;    
    }
    cout << toto <<endl; 
    int N;//variable de type entier
//portion 1
    //cin >> N;
    cpt = 1;
    while(cpt < N+1){
        cpt = cpt + 2; 
    }
//portion 2
    toto = N;
    for(cpt = 1; cpt = N + N; cpt++){
        toto = N - toto;    
    }  
//portion 3
    while(N - cpt < N){
        cpt = cpt - N;
    } 
     
    return 0;
}
