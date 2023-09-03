#include<bits/stdc++.h>
using namespace std;

// This is a normal linear search algorithm
int linearSearch(vector<int> &arr, int n, int target){
    for(int i = 0; i < n; i++)
        if(arr[i] == target) return i;
    
    return -1;
}

// This is a recursive linear search algorithm
int recursionLinearSearch(vector<int> &arr, int n, int target){
    if(n == 0) return -1;
    if(arr[n - 1] == target) return n - 1;
    return recursionLinearSearch(arr, n - 1, target);
}

int main(){
    int n, k, index;
    cin >> n >> k;
    vector<int> arr;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    // use any one of the following two functions at a time
    index = linearSearch(arr, n, k);
    index = recursionLinearSearch(arr, n, k);

    if(index == -1) cout << "Element not found" << endl;
    else cout << "Element found at index " << index << endl;

    return 0;
}