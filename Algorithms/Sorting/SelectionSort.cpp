#include<bits/stdc++.h>
using namespace std;

// This is a normal selection sort algorithm
void selectionSort(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[minIndex]) minIndex = j;
        
        swap(arr[i], arr[minIndex]);
    }
}

// This is a recursive selection sort algorithm
void recursionSelectionSort(vector<int> &arr, int n, int index = 0){
    if(index == n) return;
    int minIndex = index;
    for(int i = index + 1; i < n; i++)
        if(arr[i] < arr[minIndex]) minIndex = i;
    
    swap(arr[index], arr[minIndex]);
    recursionSelectionSort(arr, n, index + 1);
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
    selectionSort(arr, n);
    recursionSelectionSort(arr, n);

    for(auto element: arr) cout << element << " ";
    cout << endl;

    return 0;
}