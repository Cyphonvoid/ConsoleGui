#ifndef FRAME_H
#define FRAME_H


#include "Element.h"
#include <iostream>

class FRAME: public ELEMENT{
    
    public:

     ~FRAME();
     FRAME(); 
     FRAME(int hpos, int vpos); 
     FRAME(int horizontal, int vertical, int width, int length, int clr); 
     FRAME(int horizontal, int vertical, int width, int length, int R, int G, int B);  

     void render() override; 
     void erase() override; 
     void print(bool i = false); 
};

#endif