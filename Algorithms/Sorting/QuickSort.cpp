#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivot = arr[low];
        int left = low, right = high;

        while(left < right){
            while(arr[left] <= pivot && left <= high-1) left++;
            while(arr[right] > pivot && right >= low+1) right--;
            if(left < right) swap(arr[left], arr[right]);
        }
        swap(arr[right], arr[low]);
        quickSort(arr, low, right-1);
        quickSort(arr, right+1, high);
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
    
    quickSort(arr, 0, n-1);

    for(auto element: arr) cout << element << " ";
    cout << endl;

    return 0;
}