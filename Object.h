#include "Element.h"
#include <iostream>


using namespace std; 

class OBJECT: public ELEMENT{

    private:
      string sequence; 
        
    public:

    OBJECT();
    ~OBJECT();


    void render() override; 
    void erase() override; 

    void set_sequence(string& seq);
    string get_sequence();

};