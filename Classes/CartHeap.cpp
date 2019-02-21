#include <iostream>
using namespace std;

class Cart{
public: 
    int items;

    Cart() : items(0){}

};

int main(){
    //==================
    //    APP SPACE
    //==================
    Cart myCart;
    myCart.items = 5;

    //==================
    //    HEAP SPACE
    //==================
    //step 1: get a pointer!
    Cart *ptr;

    //<pointer> = new <object>
    ptr = new Cart;
    ptr->items = 5;


    return 0;
}