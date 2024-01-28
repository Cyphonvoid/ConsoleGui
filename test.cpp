#include "package.h"


int main(){
   
  BUTTON button(4, 1, "button", 240, 0, 0);
  button.draw();
  while(true){
    string input;
    cin >> input; 


    if(input == "E" or input == "e"){
        return 0;
    }
  }   
}