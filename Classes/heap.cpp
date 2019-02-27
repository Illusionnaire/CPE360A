#include <iostream>
using namespace std;

// //"idea" of a cart
// class Cart{
// public:
//     int items;
//     float price;

//     Cart() : items(0), price(0.0){}
// };

// int main(){

//     Cart *login1;
//     Cart *login2;

//     //To create a new Cart from the heap
//     //<pointer> = new <type-of-object>
//     login1 = new Cart;
//     login2 = new Cart;

// }

//"idea" of a cart
class Tab{
public:
    int width;
    int height;
    Tab *next;

Tab() : width(40), height(20), next(NULL) {}

};

int main(){

    Tab *ptr;
    Tab *helper;

    //first tab
    ptr = new Tab;

    //journey into think chunk in the heap using the pointer
    //Change width to 100 and height to 60
    ptr->width = 100;
    ptr->height = 60;
    
    //second tab
    ptr->next = new Tab;
    ptr->next->height = 40;
    ptr->next->width = 140;
    
    //third tab
    ptr->next->next = new Tab;

    // //cut off the third tab from the chain
    // ptr->next->next = NULL;

    //Create a new tab and make it the first in the long chain
    helper = new Tab;
    helper->next = ptr; //In general if pointerA = pointerB then the address is copied between both. You do not need *ptr
    ptr = helper;

    //To remove a chunk, use 'delete'
    // delete <pointer>; --> this will not delete the pointer, but it deletes the chunk that it is pointing to.

    // //let's delete the first tab
    // delete ptr; //a very bad way of doing it because you only delete the first one and not the rest of its chain. (Memory leak)
    
    //instead do:
    helper = ptr; //Make sure helper is pointing to the location that you want to delete
    ptr = ptr->next; //Change the ptr to the new ptr location
    delete helper; //Delete the location that was previously first.



}