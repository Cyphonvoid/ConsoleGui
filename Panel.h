#ifndef PANEL_H
#define PANEL_H

#include "Element.h"
#include <iostream>

using namespace std; 


class PANEL: public ELEMENT{

  
    protected: 

    struct SAVE_STATE{
       
       string SideTitle = "Side Title"; 
       string MainTitle = "Main Title"; 

       string SideTitleColor = "\x1b[0m";
       string MainTitleColor = "\x1b[0m";
       
       int margin = 4;
       
       bool AdjustEnabled = true; 

       bool operator!=(SAVE_STATE &A){
         if(SideTitle != A.SideTitle) return true;
         if(MainTitle != A.MainTitle) return true; 
         if(SideTitleColor != A.MainTitleColor) return true;
         if(MainTitleColor != A.MainTitleColor) return true;

         return false; 
       }

       bool operator==(SAVE_STATE &A){
         if(SideTitle != A.SideTitle) return false;
         if(MainTitle != A.MainTitle) return false; 
         if(SideTitleColor != A.MainTitleColor) return false;
         if(MainTitleColor != A.MainTitleColor) return false;

         return true; 
       }
    };

    SAVE_STATE mCurrent, mPrevious; 
    void AutoAdjust();

    public:
    ~PANEL();
    PANEL(); 
    PANEL(string SideTitle, string MainTitle);
    PANEL(string SideTitle, string MainTitle, int color);
    PANEL(string SideTitle, string MainTitle, int R, int G, int B);
    PANEL(int hpos, int vpos, string SideTitle, string MainTitle);
    PANEL(int hpos, int vpos, string SideTitle, string MainTitle, int color); 
    PANEL(int hpos, int vpos, string SideTitle, string MainTitle, int R, int G, int B); 



    void set_SideTitle(string str);
    void set_MainTitle(string str);
    void set_SideTitleColor(int color);
    void set_MainTitleColor(int color);
    void set_SideTitleColor(int R, int G, int B);
    void set_MainTitleColor(int R, int G, int B);
    void set_TitleMargin(int margin);

    void EnableAutoAdjust();
    void DisableAutoAdjust(); 
    bool StateChange() override; 
    void render() override; 
    void erase() override; 

};

#endif 