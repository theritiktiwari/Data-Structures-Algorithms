#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n){
    vector<bool> isPrime(n, true);
    int cnt = 0;
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i < n; i++){
        if(isPrime[i]){
            cnt++;
            for(int j = i*2; j < n; j += i) isPrime[j] = false;
        }
    }
    return cnt;
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << "There are " << countPrimes(n) << " prime numbers less than " << n << endl;

    return 0;
}