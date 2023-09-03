#include<bits/stdc++.h>
using namespace std;

// This is a normal binary search algorithm
int binarySearch(vector<int> &arr, int n, int target){
    int start = 0, end = n - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

// This is a recursive binary search algorithm
int recursionBinarySearch(vector<int> &arr, int start, int end, int target){
    if(start > end) return -1;
    int mid = start + (end - start) / 2;
    
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) return recursionBinarySearch(arr, mid + 1, end, target);
    else return recursionBinarySearch(arr, start, mid - 1, target);
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
    index = binarySearch(arr, n, k);
    index = recursionBinarySearch(arr, 0, n-1, k);

    if(index == -1) cout << "Element not found" << endl;
    else cout << "Element found at index " << index << endl;

    return 0;
}