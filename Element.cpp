#include "Element.h"
#include <iostream>

using namespace std;

 int ELEMENT::NEW_ID = 0; 
 
 ELEMENT::ELEMENT(): OBJECT_ID(++NEW_ID){ 
 
 } 
 
 ELEMENT::~ELEMENT(){
    ELEMENT::NEW_ID--; 
 }

 void ELEMENT::connect(ELEMENT* root, ELEMENT* element){
     
    if((root == element) or (root == NULL) or (element == NULL)){
        throw; 
     }
     
    if(connected(root, element) == true) return; 

    //If root and element are not already connected then connect
    root->Child.push_back(element); 
    if(element->Parent.size() == 1) element->Parent.at(0) = root; 
    else if(element->Parent.size() < 1) element->Parent.push_back(root);
 }

 void ELEMENT::disconnect(ELEMENT* root, ELEMENT* leaf, int i){
    if(root == leaf) return; 
      
      int index; 
      index = connected(root, leaf, i); 
      
      if(index >= 0){
         root->Child.erase(Child.begin() + index); 
         leaf->Parent.clear(); 
         return; 
      }
   
    cout << "\x1b[31mERROR! ROOT and LEAF nodes are not already connected!\n"; 
    
}

 int ELEMENT::connected(ELEMENT* root, ELEMENT* leaf, int j){
     j = (j >= 0) ? j : 0; 
     for(int i = j; i < root->Child.size(); i++){
       if((root->Child.at(i) == leaf) && (leaf->Parent.at(0) == root)){
          return i; 
       }
     }

     for(int i = j; i < leaf->Child.size(); i++){
       if((leaf->Child.at(i) == root) && (root->Parent.at(0) == leaf)){
          return i; 
       }
     }
     
     return -1; 
}



//GETTERS
int ELEMENT::getX(){
   return current.horizontal_position; 
}

int ELEMENT::getY(){
   return current.vertical_position; 
}

int ELEMENT::get_Width(){
   return current.horizontal_length; 
}

int ELEMENT::get_Height(){
   return current.vertical_length; 
}

int ELEMENT::get_ID(){
   return OBJECT_ID; 
}





//MUTATORS
void ELEMENT::set_Height(int height){
   current.vertical_length = height; 
}

void ELEMENT::set_Width(int width){
   current.horizontal_length = width; 
}

void ELEMENT::set_position(int Hpos, int Vpos, bool i){
   
   if(this->Parent.size() < 1){
      //If invoking object is top most root node
      current.vertical_position = Vpos; 
      current.horizontal_position = Hpos;
   }

   else if(this->Parent.size() == 1 && Parent.at(0) != NULL){
      //if invoking ojbect is child node
       if(i == true){
         current.vMargin = Vpos; 
         current.hMargin = Hpos; 
       }
      
        current.vertical_position = Parent.at(0)->current.vertical_position + current.vMargin; 
        current.horizontal_position = Parent.at(0)->current.horizontal_position + current.hMargin; 
        i = false; 
      
   }


   for(int i = 0; i < Child.size(); i++){
      Child.at(i)->set_position(0, 0, false);
   }
   
}

void ELEMENT::set_color(int R, int G, int B){
    current.color = "\x1b[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";
}

void ELEMENT::set_color(int clr){
   current.color = "\x1b[" + to_string(clr) + "m"; 
}



//ACCESSORS
bool ELEMENT::StateChange(){
   return((current != previous));
 }

void ELEMENT::render(){}

void ELEMENT::render_tree(){
   if(this->StateChange() == true){
       //overloaded == not working properly
       this->render(); 
    }
    
    for(int i = 0; i < this->Child.size(); i++){
        Child.at(i)->render_tree();
    }
}

void ELEMENT::erase(){}

void ELEMENT::erase_tree(){
   if(this->StateChange() == true){
       this->erase();
    }
     
    for(int i = 0; i < this->Child.size(); i++){
        Child.at(i)->erase_tree();
    }
}

void ELEMENT::draw(){
   erase_tree(); 
   render_tree(); 
}

void ELEMENT::draw_self(){
   erase(); 
   render(); 
}


void ELEMENT::InitialAutoPosition(int Hpos, int Vpos, bool i){
   
   if(this->Parent.size() < 1){
      //If invoking object is top most root node
      current.vertical_position = Vpos; 
      current.horizontal_position = Hpos;
   }

   else if(this->Parent.size() == 1 && Parent.at(0) != NULL){
      //if invoking ojbect is child node
       if(i == true){
         current.vMargin = initial.vertical_position; 
         current.hMargin = initial.horizontal_position; 
       }
      
        current.vertical_position = Parent.at(0)->current.vertical_position + current.vMargin; 
        current.horizontal_position = Parent.at(0)->current.horizontal_position + current.hMargin; 
        i = true; 
      
   }


   for(int i = 0; i < Child.size(); i++){
      Child.at(i)->InitialAutoPosition(0, 0, true);
   }
   
}


void ELEMENT::HideLeftWall(){

}

void ELEMENT::HideRightWall(){

}

void ELEMENT::HideRoof(){

}

void ELEMENT::HideFloor(){
   
}
