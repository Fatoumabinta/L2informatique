////////////////////////////////////////////////////////////////////////////////
/// This file is part of the Aerial Image Project (AIP).
///
/// Copyright (c) ...
///
/// The sources of AIP are distributed WITHOUT ANY WARRANTY.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Image.h"
#include <random>

using namespace std; 

//constructor
Image::Image(int w, int h){
    width_=w;
    height_=h;
    size_=w*h;

    color_tab = new Color*[width_];
   
    for(int i=0; i < width_; i++ ){
        color_tab[i] = new Color[height_];  
    }

    for(int i=0; i< width_; i++){
        for(int j=0; j< height_; j++){
             color_tab[i][j]= Color::Black ;
        }
    }
    
}

//destructor

Image::~Image(){
    delete[] color_tab;
}

int Image:: width() const{
    return width_;
}

int Image:: height() const{
    return height_;
}

int Image:: size() const{
    return size_;
}

Color Image::getPixel(int i, int j) const{
    return color_tab[j-1][i-1];
}

void Image::setPixel(int i, int j, Color col){
    //std::cout << "set pixel (" << i  << "," << j << ") = " << col << std::endl;
    color_tab[j-1][i-1] = col;
}

Image::Image(const Image& img) {
    width_ = img.width_;
    height_ = img.height_;
    size_ = img.size_;
    color_tab = img.color_tab;
}


bool Image::areConsecutivePixels(int i1, int j1, int i2, int j2) const{
    if((i1-i2==1 || i1-i2==-1) && (j1==j2)){
        return true;
    }
    else if((j1-j2==1 || j1-j2==-1) && (i1==i2)){
        return true;
    }
    else{
        return false;
    }
}

int Image::toIndex(int i,int j) const{
    int index;
    index=(i-1)*width()+(j-1);
    return index;
}

std::pair<int, int> Image::toCoordinate(int k) const{
    std::pair<int,int>p;
    p.first=k/width()+1;
    p.second=k%width()+1;
    //cout << p.first << " , "<<p.second;
    return p;
}

void Image::fillRectangle(int i1, int j1, int i2, int j2, Color c){
    for(int i=i1;i<=i2;i++){
        for(int j=j1;j<=j2;j++){
            setPixel(i, j, c);
        }
    }
}

void Image::writeSVG(const std::string& filename, int pixelSize) const
{
  assert(pixelSize > 0);

  std::ofstream file;
  file.open(filename + ".svg");

  if (!file) throw std::runtime_error("error open file (write SVG)");

  file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
       << std::endl
       << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\""
       << pixelSize*width()
       << "\" height=\""
       << pixelSize*height()
       << "\">"
       << std::endl;

  for (int i = 1; i <= height(); ++i)
    for (int j = 1; j <= width(); ++j)
      file << "<rect width=\""
           << pixelSize
           << "\" height=\""
           << pixelSize
           << "\" x=\""
           << pixelSize*(j-1)
           << "\" y=\""
           << pixelSize*(i-1)
           << "\" fill=\""
           << getPixel(i, j)
           << "\" />"
           << std::endl;

  file << "</svg>"
       << std::endl;

  file.close();
}

void Image::writeAIP(const std::string& filename) const{
    std::ofstream file;
    file.open(filename + ".aip");

    if (!file) throw std::runtime_error("error open file (write SVG)");

    file << width()<<" "<<height()<<endl;
    for (int i = 1; i <= height(); ++i){
        for (int j = 1; j <= width(); ++j){
            file << getPixel(i,j).toInt();
        }
file<<endl;
    }
    
}

Image Image::readAIP(const std::string& filename) {
    std::ifstream file;
    file.open(filename + ".aip");
    int width;
    int height;
    file >> width;
    file >> height;
    Image img(width,height);
    char color;
    for (int i = 1; i <= height; ++i){
        for (int j = 1; j <= width; ++j){
            file >> color;
            img.setPixel(i, j, Color::makeColor(color-'0'));
        }
    }
    return img;
}

