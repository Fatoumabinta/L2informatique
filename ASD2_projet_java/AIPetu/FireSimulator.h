////////////////////////////////////////////////////////////////////////////////
/// This file is part of the Aerial Image Project (AIP).
///
/// Copyright (c) ...
///
/// The sources of AIP are distributed WITHOUT ANY WARRANTY.
////////////////////////////////////////////////////////////////////////////////

#ifndef FIRE_SIMULATOR_H
#define FIRE_SIMULATOR_H

#include <vector>
#include "Image.h"

////////////////////////////////////////////////////////////////////////////////
/// This is a fire simulator.
///
/// Given a pixel of forest in an image, it simulates a fire in the zone
/// of forest of the given pixel.
////////////////////////////////////////////////////////////////////////////////
class FireSimulator {
public:

    // i and j coordinates of the pixel of a forest area(green)
    //the input image corresponds to t=0.
    FireSimulator(Image img,int i,int j);
    
  /// Destructor
  ~FireSimulator();
 
private:

    int t;//time
    int fire_size;   //fire_size is a variable number that represents the number of fire points that will be added
    int debut_cendre; //debut ash propagation
    int ind_cendre;

    //type to represent pixel
    struct pixel{
        int i;
        int j;
    };
    pixel* tab_pixel;

};

#endif
