#include <iostream>
using namespace std;

int factorial(int n){

    if (n <= 1){
        return n;
    }

    return n * factorial(n-1);
}


int main(){
    //factorial 
    int x;

    cout << "Give me a number, I'll get you it's factorial: ";
    cin >> x;

    cout << factorial(x);

    return 0;
}