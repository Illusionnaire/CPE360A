#include <iostream>
using namespace std;

void hanoi(int N, char S, char I, char D){
    //base case
    static int count = 0;
    if (N == 1){
        cout << ++count << " Move disc " << N << " from " << S << " --> " << D << endl;
    }
    else{
        hanoi(N-1, S, D, I);
        cout << ++count << " Move disc " << N << " from " << S << " --> " << D << endl;
        hanoi(N-1, I, S, D);
    }
}

int main(){
    int n;
    char S = 'S';
    char D = 'D';
    char I = 'I';

    cout << "Enter me the number of disks: ";
    cin >> n;

    hanoi(n, S, I, D);

    return 0;
}