////////////////////////////////////////////////////////////////////////////////
/// This file is part of the Aerial Image Project (AIP).
///
/// Copyright (c) ...
///
/// The sources of AIP are distributed WITHOUT ANY WARRANTY.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include "Analyst.h"
#include "Color.h"
#include "Image.h"
#include <list>
#include <algorithm>

//#include""

using namespace std;

Analyst::Analyst(const Image& img): image(img) {
    
    nbzone=0;
    tab_zone=new Analyst::Analyst::Zone[img.size()];
    for(int i=1;i<=img.height();i++){
        for(int j=1;j<=img.width();j++){
            Color c = img.getPixel(i,j);
            tab_zone[img.toIndex(i,j)].c = c;
            
            if  (i > 1) {
                Color ch = img.getPixel(i-1,j);
                if((c == ch)){ //si ça a la meme couleur 
                    tab_zone[img.toIndex(i,j)].num=tab_zone[img.toIndex(i-1,j)].num;
                    continue;
                }    
            }

            if  (j > 1) {
                Color cg = img.getPixel(i,j-1);
                if((c == cg)){ //si ça a la meme couleur 
                    tab_zone[img.toIndex(i,j)].num=tab_zone[img.toIndex(i,j-1)].num;
                    continue;
                }    
            }
            nbzone++;
            tab_zone[img.toIndex(i,j)].num=nbzone;
        }
    }

}


Analyst::~Analyst() {
    delete[] tab_zone;
}

bool Analyst::belongToTheSameZone(int i1, int j1, int i2, int j2){
    if(tab_zone[image.toIndex(i1,j1)].num == tab_zone[image.toIndex(i2,j2)].num){
        return true;
    }
    else{
        return false;
    }
}

int Analyst::nbZones() const{

    return nbzone;
}

Image Analyst::fillZone(int i, int j, Color c){
    int width;
    int height;
    cout<<"width : "<<endl;
    cin >>width;
    cout<<"height : "<<endl;
    cin >>height;
    Image img(width,height);
    img.setPixel(i,j, c);
    return img;
}


int Analyst::nbPixelsOfColor(Color c) const{
    int compt=0;
    for(int i=1;i<=image.height();i++){
        for(int j=1;j<=image.width();j++){
            tab_zone[image.toIndex(i,j)].c = c;
            compt++;
        }
    }
    return compt;
}


int Analyst::nbZonesOfColor(Color c) const{
    std::set<int> tab_num_zone = {};
    for(int i=1;i<=image.height();i++){
        for(int j=1;j<=image.width();j++){
            if(tab_zone[image.toIndex(i,j)].c == c && tab_num_zone.count(tab_zone[image.toIndex(i,j)].num) == 0){
                tab_num_zone.insert(tab_zone[image.toIndex(i,j)].num);
            }
        }
    }
    return tab_num_zone.size();
}

std::set<int> Analyst::zoneOfPixel(int i, int j){ 
    std::set<int> pixel_indexes = {};
    int num_pixel = tab_zone[image.toIndex(i,j)].num;
    for(int i1=1;i1<=image.height();i1++){
        for(int j1=1;j1<=image.width();j1++){
            if(tab_zone[image.toIndex(i1,j1)].num == num_pixel){
                pixel_indexes.insert(image.toIndex(i1,j1));
            }
        }
    }
    return pixel_indexes;      

}


