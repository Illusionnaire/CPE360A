#include <iostream>
using namespace std;

class Cart {
public:
    int numberofItems;
    float totalPrice;
    
    Cart() : numberofItems(0), totalPrice(0.0){}

    void addToCart(){
        numberofItems++;
        cout << "Added an item to cart!" << endl;
    }
};

int main(){
    int x = 0;
    int *ptr;
    ptr = &x;


    Cart myCart;
    Cart *pal;

    pal = &myCart;
    myCart.addToCart();

    // "Pal can also access these "rooms" inside myCart
    pal->numberofItems = 3;

    cout << "Number of items now: " << myCart.numberofItems << endl;


    return 0;
}