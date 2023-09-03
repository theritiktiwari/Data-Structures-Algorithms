#include<bits/stdc++.h>
using namespace std;

// This is a normal insertion sort algorithm
void insertionSort(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

// This is a recursive insertion sort algorithm
void recursionInsertionSort(vector<int> &arr, int n){
    if(n == 1) return;
    recursionInsertionSort(arr, n - 1);
    int j = n - 1;
    while(j > 0 && arr[j] < arr[j-1]){
        swap(arr[j], arr[j-1]);
        j--;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    // use any one of the following two functions at a time
    insertionSort(arr, n);
    recursionInsertionSort(arr, n);

    for(auto element: arr) cout << element << " ";
    cout << endl;

    return 0;
}