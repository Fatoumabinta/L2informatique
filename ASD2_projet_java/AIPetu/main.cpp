////////////////////////////////////////////////////////////////////////////////
/// This file is part of the Aerial Image Project (AIP).
///
/// Copyright (c) ...
///
/// The sources of AIP are distributed WITHOUT ANY WARRANTY.
////////////////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "FireSimulator.h"
#include "Analyst.h"

int main(void)
{

    Color c;
    Image img(200,100);//create image

    //zone

     //blue in the middle
    int i1 = 1; 
    int j1 = img.width()/2 - 8;

    int i2 = img.height(); 
    int j2 = img.width()/2 + 8;
    img.fillRectangle(i1, j1, i2, j2 ,Color::Blue);

    //green on top
    i1 = 1; 
    j1 = 1;

    i2 = 25; 
    j2 = 24;

    img.fillRectangle(i1, j1, i2, j2 ,Color::Green);

    //white in the middle
    i1=22;
    j1=21;

    i2=80;
    j2=50;

    img.fillRectangle(i1, j1, i2, j2 ,Color::White);

    // green at the bottom
    i1=75;
    j1=47;

    i2=100;
    j2=91;

    img.fillRectangle(i1, j1, i2, j2 ,Color::Green);


    ////create Analyste
    Analyst anali(img);
    anali.nbZonesOfColor(Color::Green);

   // img.readAIP("fichierAIP");
    img.writeAIP("fichierAIP");
    Image::readAIP("fichierAIP").writeSVG("test", 4);
    

    ////create FireSimulator
    FireSimulator simulator(img,87,69);

  return 0;
}
