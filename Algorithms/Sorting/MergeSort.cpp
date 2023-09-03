#include<bits/stdc++.h>
using namespace std;

// Merge two sorted arrays into one
void mergeSortMerge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid + 1;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }

    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i = low; i <= high; i++) arr[i] = temp[i - low];
}

// Divide the array into two parts and sort them individually
void mergeSortDivide(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int mid =  low + (high - low) / 2;
    mergeSortDivide(arr, low, mid);
    mergeSortDivide(arr, mid + 1, high);
    
    mergeSortMerge(arr, low, mid, high);
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
    
    mergeSortDivide(arr, 0, n-1);

    for(auto element: arr) cout << element << " ";
    cout << endl;

    return 0;
}