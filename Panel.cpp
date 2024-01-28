
#include "Panel.h"
#include <iostream>

PANEL::~PANEL(){
   
   erase(); 
   for(int i = 0; i < Child.size(); i++){
       disconnect(this, Child.at(i), i); 
    }
}

PANEL::PANEL(){

    current.vertical_length = 3; 
    initial = current;
    previous = current; 
    AutoAdjust();
}

PANEL::PANEL(string SideTitle, string MainTitle){
  
   mCurrent.SideTitle = SideTitle; 
   mCurrent.MainTitle = MainTitle; 
   mCurrent.margin = mCurrent.SideTitle.length() + mCurrent.margin; 
   current.vertical_length = 3; 
   initial = current;
   previous = current; 
   AutoAdjust();
}

PANEL::PANEL(string SideTitle, string MainTitle, int color){

    mCurrent.SideTitle = SideTitle; 
    mCurrent.MainTitle = MainTitle;  
    mCurrent.margin = mCurrent.SideTitle.length() + mCurrent.margin; 
    current.color = "\x1b[" + to_string(color) + "m"; 
    current.vertical_length = 3; 
    initial = current;
    previous = current; 
    AutoAdjust();
}

PANEL::PANEL(string SideTitle, string MainTitle, int R, int G, int B){

    mCurrent.SideTitle = SideTitle; 
    mCurrent.MainTitle = MainTitle;  
    mCurrent.margin = mCurrent.SideTitle.length() + mCurrent.margin; 
    current.color = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";
    current.vertical_length = 3; 
    initial = current;
    previous = current; 
    AutoAdjust();
}

PANEL::PANEL(int hpos, int vpos, string SideTitle, string MainTitle){
    
    current.horizontal_position = hpos; 
    current.vertical_position = vpos; 

    mCurrent.SideTitle = SideTitle; 
    mCurrent.MainTitle = MainTitle; 
    mCurrent.margin = mCurrent.SideTitle.length() + mCurrent.margin;  
    current.vertical_length = 3; 
    
    initial = current;
    previous = current; 
    AutoAdjust();
} 


PANEL:: PANEL(int hpos, int vpos, string SideTitle, string MainTitle, int color){

    current.horizontal_position = hpos; 
    current.vertical_position = vpos; 

    mCurrent.SideTitle = SideTitle; 
    mCurrent.MainTitle = MainTitle;  
    mCurrent.margin = mCurrent.SideTitle.length() + mCurrent.margin; 
    current.color = "\x1b[" + to_string(color) + "m"; 
    current.vertical_length = 3; 
    initial = current;
    previous = current; 
    AutoAdjust();
}

PANEL::PANEL(int hpos, int vpos, string SideTitle, string MainTitle, int R, int G, int B){

    current.horizontal_position = hpos; 
    current.vertical_position = vpos; 

    mCurrent.SideTitle = SideTitle; 
    mCurrent.MainTitle = MainTitle;  
    mCurrent.margin = mCurrent.SideTitle.length() + mCurrent.margin; 

    current.color = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";

    current.vertical_length = 3; 
    previous = current; 
    initial = current;
    AutoAdjust();
}



void PANEL::set_SideTitle(string str){
    mCurrent.SideTitle = str; 
}

void PANEL::set_MainTitle(string str){
    mCurrent.MainTitle = str; 
}

void PANEL::set_SideTitleColor(int color){
    
    mCurrent.SideTitleColor = "\x1b[" + to_string(color) + "m"; 
}

void PANEL::set_MainTitleColor(int color){
    
    mCurrent.MainTitleColor = "\x1b[" + to_string(color) + "m"; 
}

void PANEL::set_SideTitleColor(int R, int G, int B){
    
   mCurrent.SideTitleColor = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";

}

void PANEL::set_MainTitleColor(int R, int G, int B){
    
   mCurrent.MainTitleColor = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";

}

void PANEL::set_TitleMargin(int margin){
    mCurrent.margin = mCurrent.SideTitle.length() + margin; 
}

void PANEL::render(){
    
    AutoAdjust(); 
    
    int posX = current.horizontal_position; 
    int posY = current.vertical_position;

    int lengthX = current.horizontal_length; 
    int lengthY = current.vertical_length;
    


    string TOP_ROOF     =  CreateStringOf(1, "╭") + CreateStringOf(lengthX-2, "─") + CreateStringOf(1, "╮"); 
    string MIDDLE_PART  =  CreateStringOf(1, "│") + CreateStringOf(lengthX-2, " ") + CreateStringOf(1, "│");
    string BOTTOM_ROOF  =  CreateStringOf(1, "╰") + CreateStringOf(lengthX-2, "─") + CreateStringOf(1, "╯"); 
    

    Cursor(posX, posY);     cout << current.color << TOP_ROOF; 
    
    Cursor(posX, posY+1);   cout << MIDDLE_PART; 
    Cursor(posX+2, posY+1); cout << mCurrent.SideTitleColor << mCurrent.SideTitle;
    Cursor(posX + mCurrent.margin, posY+1); cout << mCurrent.MainTitleColor<< mCurrent.MainTitle; 

    Cursor(posX, posY+2);   cout << current.color << BOTTOM_ROOF << "\x1b[0m"; 

    previous = current; 
    mPrevious = mCurrent; 
}

void PANEL::erase(){

    ErasePortion(previous.horizontal_position, previous.vertical_position, previous.horizontal_length, previous.vertical_length);
}

void PANEL::EnableAutoAdjust(){
    mCurrent.AdjustEnabled = true; 
}

void PANEL::DisableAutoAdjust(){
    mCurrent.AdjustEnabled = false;     
}

void PANEL::AutoAdjust(){

    if(mCurrent.AdjustEnabled == true){
        int Slen = mCurrent.SideTitle.length();
        int Mlen = mCurrent.MainTitle.length(); 

        mCurrent.margin = Slen + (Slen + Mlen + 4)/3; 
        
        current.horizontal_length =  Slen + Mlen + (2*(mCurrent.margin-Slen)); 
        return; 
    }
}

bool PANEL::StateChange(){
   return((current != previous) or (mCurrent != mPrevious));
}   