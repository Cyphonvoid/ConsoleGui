#include "Utility.h"
#include <iostream>

using namespace std; 

void Cursor(int x, int y) {
    string cursor = "\x1b[" + to_string(y) + ";" + to_string(x) + "H";
    cout << cursor; 
}

void cursor(int x, int y) {
    string cursor = "\x1b[" + to_string(y) + ";" + to_string(x) + "H";
    cout << cursor; 
}

string toCursor(int x, int y){
    string cursor = "\x1b[" + to_string(y) + ";" + to_string(x) + "H";
    return cursor; 
}

void DrawPoint(int horizontal, int vertical, string str){
     string cursor = "\x1b[" + to_string(vertical) + ";" + to_string(horizontal) + "H"; 
     cout << cursor << str; 
 }

 void ClearScreen(){
   printf("\x1b[H\x1b[2J"); 
}

void clear(){
   printf("\x1b[H\x1b[2J"); 
}
 
 string CreateStringOf(int length, string str){
    string temp = ""; 
    for(int i = 0; i < length; i++){
       temp += str; 
    }

    return temp; 
 }
 
 void ErasePortion( int hpos, int vpos,  int width, int length) {
	for (int i = 0; i < length; i++) {
		string str(width, ' ');
		Cursor(hpos, vpos + i);
		cout << str;
	}
}


 bool operator==(ELEMENT_ATTR& A, ELEMENT_ATTR& B){
      
      if(A.color != B.color) return false; 
      if(A.vertical_position != B.vertical_position) return false; 
      if(A.horizontal_position != B.horizontal_position) return false; 
      if(A.vertical_length != B.horizontal_length) return false; 
      if(A.horizontal_length != B.horizontal_length) return false; 
      if(A.vMargin != B.vMargin) return false; 
      if(A.hMargin != B.hMargin) return false; 

     return true; 
 }


 bool operator!=(ELEMENT_ATTR& A, ELEMENT_ATTR& B){
      
      if(A.color != B.color){ return true;}
      if(A.vertical_position != B.vertical_position){ return true;} 
      if(A.horizontal_position != B.horizontal_position){ return true; }
      if(A.vertical_length != B.vertical_length){ return true; }
      if(A.horizontal_length != B.horizontal_length){ return true;} 
      if(A.vMargin != B.vMargin){ return true; }
      if(A.hMargin != B.hMargin){ return true; }

     return false; 
 }


 string createH(string seq){
    
    //Stores position
    int X, Y; 

    //Stores the string to be displayed
    string Final; 

    //Get the first X positino using 'X' and ','  
    int iposx = stoi(seq.substr(seq.find('X', 0)+1, seq.find(',', 0)-1));
    
    //Get the first Y positino using 'Y' and ']' 
    int iposy = stoi(seq.substr(seq.find('Y', 0)+1, seq.find(']', 0)-1));

    
    for(int i = 0; seq[i] != '!'; i++){
       
       //Find the opening to read rendering instruction
       if(seq[i] == '('){
         int commaPos = seq.find(',', i); 
         //Get the length using '(' and ','
         int length = stoi(seq.substr(i+1, commaPos-i-1));

         //Get the character using ',' and ')'
         string code = seq.substr(commaPos+1, seq.find(')')-commaPos-1);

         Final += CreateStringOf(length, code); 
       }
    }

    return toCursor(iposx, iposy) + Final;
 }

 string createV(string seq){
   
     
 }

