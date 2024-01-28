#include "Object.h"

using namespace std; 


OBJECT::OBJECT(){
    this->sequence = "";
}


OBJECT::~OBJECT(){

}


void OBJECT::render(){
   cout << createH(this->sequence);
}



void OBJECT::erase(){

}


void OBJECT::set_sequence(string& seq){
  this->sequence = seq; 
}

string OBJECT::get_sequence(){
  return this->sequence; 
}