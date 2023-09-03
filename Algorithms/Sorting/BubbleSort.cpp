#include<bits/stdc++.h>
using namespace std;

// This is a normal bubble sort algorithm
void bubbleSort(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// This is a recursive bubble sort algorithm
void recursionBubbleSort(vector<int> &arr, int n){
    if(n == 1) return;
    int i = 0;
    while(i < n - 1){
        if(arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        i++;
    }
    recursionBubbleSort(arr, n - 1);
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
    bubbleSort(arr, n);
    recursionBubbleSort(arr, n);

    for(auto element: arr) cout << element << " ";
    cout << endl;

    return 0;
}