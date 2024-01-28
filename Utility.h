#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
using namespace std; 

 void Cursor(int x, int y);
 void cursor(int x, int y);

 void DrawPoint(int horizontal, int vertical, string str);

 void ClearScreen();

void clear();
 
 string CreateStringOf(int length, string str);
 
 void ErasePortion( int hpos, int vpos,  int width, int length);

struct COLOR{
   int BLACK   =  30;
   int RED     =  31; 
   int GREEN   =  32; 
   int YELLOW  =  33; 
   int BLUE    =  34; 
   int MAGENTA =  35; 
   int CYAN    =  36; 
   int WHITE   =  37; 
   int DEFAULT =  39; 
  
 };
 
 struct ELEMENT_ATTR{

     int vertical_position   = 0; 
     int horizontal_position = 0; 
     int vertical_length     = 0; 
     int horizontal_length   = 0; 
     int hMargin             = 0; 
     int vMargin             = 0; 
     string color            = "\x1b[0m";
 };

 bool operator==(ELEMENT_ATTR& A, ELEMENT_ATTR& B);


 bool operator!=(ELEMENT_ATTR& A, ELEMENT_ATTR& B);

 struct CHAR_PACK{

     string wall        = "│"; 
     string roof        = "─";     
     string TopLeft     = "╭"; 
     string TopRight    = "╮"; 
     string BottomLeft  = "╰"; 
     string BottomRight = "╯"; 

 };



string createV(string& seq);
string createH(string& seq);
string toCursor(int x, int y);
#endif