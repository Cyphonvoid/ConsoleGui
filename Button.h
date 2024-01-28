#ifndef BUTTON_H
#define BUTTON_H


#include <iostream>
#include "Element.h"
#include <cmath>

//NEED TO ADD AUTO ADJUST FEATURE FOR BUTTON
 
class BUTTON: public ELEMENT{

      protected:
        struct SAVE_STATE{
          string name = "Button"; 
          string name_color = "\x1b[0m";
          int LeftMargin = 2;
          int RightMargin = 2; 
          bool AutoAdjustEnabled = true; 
  
          bool operator!=(SAVE_STATE& B){
            if(this->name != B.name)return true;
            if(this->name_color != B.name_color) return true; 
            return false; 
          } 
      };
     
      SAVE_STATE m_current, m_previous; 
      void AutoAdjust(); 
      void DefaultAdjust(string& text); 

      public:
      ~BUTTON(); 
      BUTTON(); 
      BUTTON(int hpos, int vpos); 
      BUTTON(int horizontal, int vertical, string name); 
      BUTTON(int horizontal, int vertical, string name, int clr); 
      BUTTON(int horizontal, int vertical, string name,  int R, int G, int B); 
      
      
      void render() override; 
      void erase() override; 
      bool StateChange() override; 
      void HideLeftWall() override; 
      void HideRightWall() override; 
      void HideFloor() override; 
      void HideRoof() override; 

      void set_nameColor(int R, int G, int B); 
      void set_nameColor(int clr); 
      void set_name(string str); 
      void EnableAutoAdjust(); 
      void DisableAutoAdjust(); 

 };

#endif