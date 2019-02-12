#include <iostream>
using namespace std;

//Signature of a Function --> Must have a unique signature
//<return-type> <name> <arguments>


int main(){
    int counter = 0;
    int counter2 = 0;
    int sum = 0;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i*i; j++){
                
            for(int k = 0; k < j; k++){
                counter++; // n times 1+1+1+1
                sum+=2;
            }
            counter2++;
            sum++;
        }
        sum++;
    }

    cout << sum << "\t" << counter2 << "\t" << counter;


    return 0;
}