//A tale of boxes lesson
#include <iostream>
using namespace std;

int main(){
    int x = 5;
    int *pal; //pal does not know x, it is a pointer that can store adresses, but not real numbers

    //pall meets x, more so, gets the address of x;
    pal = &x;

    //here's me changing x to 10
    x = 10;

    cout << "X is now: " << x << endl;

    //pal can change the contents, too!
    //so here's pal changing the value of x to 20
    *pal = 20;
    //x comes back home to see what's in it

    cout << "X, after pal's visit, is now: " << x << endl;


    // *pal gives the value of the inner contents at that location
    // pal gives the address of the variable


    // cout << "Value of x:" << x << endl;
    // cout << "Address of x: " << &x << endl;

    // if (x > 0) {
    //     //New scope (sub-scope within the main scope)
    //     float y = 3.14;
    //     cout << "y is: " << y << endl;
    // }

    // //Will not run
    // cout << "Y outside the if statement: " << y << endl;




    return 0;
}