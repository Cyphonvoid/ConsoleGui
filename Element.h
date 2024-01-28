#ifndef ELEMENT_H
#define ELEMENT_H

//Header files
#include <iostream>
#include <vector> 
#include "Utility.h"

using namespace std; 



class ELEMENT{
    private:
    static int NEW_ID;
       
    protected:

    const int OBJECT_ID; 
     
    //TO SAVE PREVIOUS INFO
    ELEMENT_ATTR current, previous, initial; 
    CHAR_PACK pack; 
    vector<ELEMENT*> Parent; 
    vector<ELEMENT*> Child; 
     

    public:
     ELEMENT(); 
    ~ELEMENT(); 
    
    void connect(ELEMENT* root, ELEMENT* element); 
    void disconnect(ELEMENT* root, ELEMENT* leaf, int i = -1); 
    int connected(ELEMENT* root, ELEMENT* leaf, int j = -1);
    template <typename... Args>
    void add(Args&&... args){
        
        std::vector<ELEMENT*> nodes{std::forward<Args>(args)...};
        int num = nodes.size();
        
        for(int i = 0; i < num; i++){
           connect(this, nodes[i]); 
        }
       
        InitialAutoPosition(initial.horizontal_position, initial.vertical_position);
    }

    template <typename... Args>
    void remove(Args&&... args){
        std::vector<ELEMENT*> nodes{std::forward<Args>(args)...};
        int num = nodes.size();
        
        for(int n = 0; n < nodes.size(); n++){

          for(int i = 0; i < Child.size(); i++){
             
             if(nodes.at(n) == Child.at(i)){
                disconnect(this, nodes[n], i); 
                nodes.erase(nodes.begin() + n); 
                n--; //This make sures to not skip any shifted elements
                break; 
             }
          } 
        } 

    }

     

    //GETTERS
    int getX();
    int getY(); 
    int get_Height(); 
    int get_Width(); 
    int get_ID(); 

    //MUTATORS
    void set_position(int Hpos, int Vpos, bool i = true);
    void set_Height(int height); 
    void set_Width(int width); 
    void set_color(int R, int G, int B); 
    void set_color(int clr); 
    
    
   
    void draw(); 
    void erase_tree(); 
    void render_tree(); 
    void draw_self();  
    virtual bool StateChange(); 
    virtual void render();
    virtual void erase(); 
    virtual void HideLeftWall(); 
    virtual void HideRightWall(); 
    virtual void HideRoof(); 
    virtual void HideFloor(); 
    void InitialAutoPosition(int Hpos, int Vpos, bool i = true);
 };

#endif