#include<bits/stdc++.h>
using namespace std;

// iterative implementation of Euclid's algorithm
int iterativeGCD(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;

    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }

    return a;
}

// recursive implementation of Euclid's algorithm
int recursiveGCD(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;

    if(a > b) return recursiveGCD(a-b, b);
    else return recursiveGCD(a, b-a);
}

int main(){
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    
    // use any one of the following two lines to calculate GCD
    cout << "GCD of " << a << " and " << b << " is " << iterativeGCD(a, b) << endl;
    cout << "GCD of " << a << " and " << b << " is " << recursiveGCD(a, b) << endl;

    return 0;
}