////////////////////////////////////////////////////////////////////////////////
/// This file is part of the Aerial Image Project (AIP).
///
/// Copyright (c) ...
///
/// The sources of AIP are distributed WITHOUT ANY WARRANTY.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cassert>
#include "Analyst.h"
#include "FireSimulator.h"
#include <time.h>

#include <random>

using namespace std; 


FireSimulator::FireSimulator(Image img,int i,int j){

    if(img.getPixel(i,j)!=Color::Green){
        cout<<"enter the pixels of a forest area"<<endl;
    }

    //draw a random number between 1 and the drill zone
    srand(time(NULL));

    fire_size = rand() % 100 + 70;//fire size
    
    debut_cendre = rand() % fire_size/2; //debut ash propagation   

    tab_pixel = new FireSimulator::FireSimulator::pixel[fire_size];

    img.fillRectangle(i, j, i, j ,Color::Red); //adding start light
    img.writeSVG("img_t0",2);

    ind_cendre = 0;

    for(t=0; t<fire_size ; t++){
        int position_fire = rand() % 4 + 1;//taille du feu

         //block determining the coordinates of the next fire 
        if(position_fire == 1){     //si = 1 one point up
            i = i-1;
              
        } else if(position_fire == 2){  //si = 2 one point to the right
            j = j+1;
            
        } else if(position_fire == 3){ //si = 3 one dot down
            i = i+1;
 
            
        } else if(position_fire == 4){ //si = 4 a point on the left
            j = j-1;
 
            
        }
        //ind_pixel += 1; 
        img.fillRectangle(i, j, i, j ,Color::Red); //propagation du feu  
        tab_pixel[t].i = i;
        tab_pixel[t].j = j;
 

        if(t >= debut_cendre){
            img.fillRectangle(tab_pixel[ind_cendre].i,tab_pixel[ind_cendre].j, tab_pixel[ind_cendre].i, tab_pixel[ind_cendre].j ,Color::Black); //propagation cendre 

            ind_cendre++;
        }

        img.writeSVG("resultat/img_t" + std::to_string(t),4);
    }

    
    for(int k=0;k<debut_cendre;k++){
      img.fillRectangle(tab_pixel[ind_cendre].i,tab_pixel[ind_cendre].j, tab_pixel[ind_cendre].i, tab_pixel[ind_cendre].j ,Color::Black); //propagation ash 

        ind_cendre ++;
       img.writeSVG("resultat/img_t" + std::to_string(ind_cendre),4);
    }
    img.writeSVG("resultat/img_t" + std::to_string(ind_cendre),4);


}


FireSimulator::~FireSimulator(){
    delete[] tab_pixel;
}
