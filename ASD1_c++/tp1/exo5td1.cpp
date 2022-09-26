#include<iostream>
#include<string>
using namespace std;

/****************** 5 - Coûts ***********************/
//fonction sommeCar prenant en entrée un entier positif n et retournant la somme des carrés des entiers de 1 à n
int sommeCar(int n){
    int s, k;
    s = 0;
    for(k=1; k<n; k++){
        s = s + k * k;
    } 
}
//fonction nbPairs renvoyant pour P passé en paramètre le nombre d'entiers n<P tel que la somme des carrés des entiers de 1 à n soit paire
int nbPairs(int p){
    int n, k;
    k = 0;
    for(n = 0; n <= p-1; n++){
        if(sommeCar(n) % 2 == 0){
            k = k+1;
        }
    } 
    return k;       
}
int main(){
return 0;
}
