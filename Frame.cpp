
#include "Frame.h"
#include <iostream>

FRAME::~FRAME(){
    
    erase(); 

    for(int i = 0; i < Child.size(); i++){
       disconnect(this, Child.at(i), i); 
    }
 }

 FRAME::FRAME(){
    current = {0, 0, 0, 0, 0, 0, "\x1b[0m"}; 
    current.color = "\x1b[0m";
    initial = current;
 }

 FRAME::FRAME(int hpos, int vpos){
    current.vertical_position = vpos; 
    current.horizontal_position = hpos; 
    current.color = "\x1b[0m";
    initial = current;
 }

 FRAME::FRAME(int horizontal, int vertical, int width, int length, int clr){
    current.vertical_position = vertical; 
    current.horizontal_position = horizontal; 

    current.vertical_length = length; 
    current.horizontal_length = width; 

    current.color = "\x1b[" + to_string(clr) + "m"; 
    initial = current;
 }

 FRAME::FRAME(int horizontal, int vertical, int width, int length,  int R, int G, int B){
    current.vertical_position = vertical; 
    current.horizontal_position = horizontal; 

    current.vertical_length = length; 
    current.horizontal_length = width; 

    current.color = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";
    
    initial = current;
 }

 void FRAME::render(){

    int hLength = current.horizontal_length-2;

    string TOP_ROOF = pack.TopLeft + CreateStringOf(hLength, pack.roof) + ((hLength >= 0)?pack.TopRight : ""); 
    string BOTTOM_ROOF = pack.BottomLeft + CreateStringOf(hLength, pack.roof) +  ((hLength >= 0)?pack.BottomRight : ""); 

    int total_height = current.vertical_position + current.vertical_length-2; 
    int start = current.vertical_position+1; 
    
     
    cout << current.color; 
    Cursor(current.horizontal_position, current.vertical_position); 
    cout << TOP_ROOF; 
    
    Cursor(current.horizontal_position, current.vertical_position + current.vertical_length-1); 
    cout  << BOTTOM_ROOF; 


    for(int i = start; i <= total_height; i++){
        DrawPoint(current.horizontal_position, i, pack.wall);
        DrawPoint(current.horizontal_position + hLength+1, i, pack.wall); 
    }
    
    cout << "\x1b[0m"; 
    previous = current; 
 }

 void FRAME::erase(){

    int hLength = previous.horizontal_length;

    string TOP_ROOF = CreateStringOf(hLength, " "); 
    string BOTTOM_ROOF =CreateStringOf(hLength, " "); 

    int total_height = previous.vertical_position + previous.vertical_length-2; 
    int start = previous.vertical_position+1; 
    
     
    cout << previous.color; 
    Cursor(previous.horizontal_position,  previous.vertical_position); 
    cout << TOP_ROOF; 
    
    Cursor(previous.horizontal_position,  previous.vertical_position +  previous.vertical_length-1); 
    cout  << BOTTOM_ROOF; 


    for(int i = start; i <= total_height; i++){
        DrawPoint(previous.horizontal_position, i, " ");
        DrawPoint(previous.horizontal_position + hLength-1, i, " "); 
    }
 }

 void FRAME::print(bool i){
   //cout << boolalpha << (previous != current); 
   if(i == false) return; 
   cout << Parent.at(0) << " : " << endl; 

 }