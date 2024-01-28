
 #include "Button.h"
 #include <iostream>

 BUTTON::~BUTTON(){
    erase(); 

    for(int i = 0; i < Child.size(); i++){
       disconnect(this, Child.at(i), i); 
    }
 }

 BUTTON::BUTTON(){
    current = {0, 0, 0, 0, 0, 0, "\x1b[0m"}; 
    current.color = "\x1b[0m";
    initial = current;
    AutoAdjust();
 }

 BUTTON::BUTTON(int hpos, int vpos){
    current.vertical_position = vpos; 
    current.horizontal_position = hpos; 
    current.color = "\x1b[0m";
    initial = current;
    AutoAdjust();
 }

 BUTTON::BUTTON(int horizontal, int vertical, string name){
    current.vertical_position = vertical; 
    current.horizontal_position = horizontal; 

    m_current.name = name; 
    current.color = "\x1b[0m"; 
    initial = current;
    AutoAdjust();
 }

 BUTTON::BUTTON(int horizontal, int vertical, string name, int clr){
    current.vertical_position = vertical; 
    current.horizontal_position = horizontal; 
    
    m_current.name = name;
    current.color = "\x1b[" + to_string(clr) + "m"; 
    initial = current;
    AutoAdjust();
 }

 BUTTON::BUTTON(int horizontal, int vertical, string name,  int R, int G, int B){
    current.vertical_position = vertical; 
    current.horizontal_position = horizontal; 

    m_current.name = name; 
    current.color = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";
    initial = current;
    AutoAdjust();

 }

 void BUTTON::set_nameColor(int clr){
     m_current.name_color = "\x1b[" + to_string(clr) + "m";
 }

 void BUTTON::set_nameColor(int R, int G, int B){
    m_current.name_color = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";
 }
 
 void BUTTON::set_name(string str){
    m_current.name = str; 
 }


 void BUTTON::render(){
    string text = m_current.name; 
    AutoAdjust(); 
    DefaultAdjust(text); 
    int posX = current.horizontal_position; 
    int posY = current.vertical_position; 

    int lengthX = current.horizontal_length; 
    int lengthY = current.vertical_length; 

    string TOP_ROOF     = CreateStringOf(1, "╭") + CreateStringOf(lengthX-2, "─") + CreateStringOf(1, "╮"); 
    string MIDDLE_PART  = CreateStringOf(1, "│") + CreateStringOf(lengthX-2, " ") + CreateStringOf(1, "│"); 
    string BOTTOM_ROOF  = CreateStringOf(1, "╰") + CreateStringOf(lengthX-2, "─") + CreateStringOf(1, "╯"); 

    Cursor(posX, posY); cout << current.color << TOP_ROOF; 

    Cursor(posX, posY+1); cout << MIDDLE_PART; 
    Cursor(posX + m_current.LeftMargin, posY+1); cout << m_current.name_color << text;

    Cursor(posX, posY+2); cout << current.color << BOTTOM_ROOF; 

    previous = current; 
    m_previous = m_current; 

    
 }

 void BUTTON::erase(){
      
      int posX = previous.horizontal_position; 
      int posY = previous.vertical_position; 

      string remove(previous.horizontal_length, ' ');

      Cursor(posX, posY);
      cout << remove; 

      Cursor(posX, posY+1);
      cout << remove; 

      Cursor(posX, posY+2); 
      cout << remove; 
 }

 bool BUTTON::StateChange(){
    return((current != previous) or (m_current != m_previous));
 }

void BUTTON::DefaultAdjust(string& text){
  if(m_current.AutoAdjustEnabled == false){

     int lengthX = current.horizontal_length - (m_current.LeftMargin + m_current.RightMargin); 
  
     int diff = lengthX - text.length(); 
  
     diff = abs(diff);
  
     text = text.substr(0, text.length() - diff);

  }
   
 }

 void BUTTON::AutoAdjust(){

  if(m_current.AutoAdjustEnabled == true){
     current.horizontal_length = m_current.name.length() + (m_current.LeftMargin + m_current.RightMargin); 
    }
   
 }

 void BUTTON::EnableAutoAdjust(){
   m_current.AutoAdjustEnabled = true; 
 }

 void BUTTON::DisableAutoAdjust(){
   m_current.AutoAdjustEnabled = false; 
 }


 void BUTTON::HideLeftWall(){
   
 }
 
 void BUTTON::HideRightWall(){

 }
 
 void BUTTON::HideFloor(){

 }

 void BUTTON::HideRoof(){

 } 