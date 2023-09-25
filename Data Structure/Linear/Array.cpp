#include<bits/stdc++.h>

using namespace std;

// Display the elements
void display(int arr[], int n){
    cout << "Elements are : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Search the element
void search(int arr[], int n){
    int element, num, f = 0;
    cout << "Enter the element, which has to be searched : ";
    cin >> element;
    for (int i = 0; i < n; i++)
        if(arr[i] == element){
            f = 1;
            num = i;
            break;
        }
    if(f == 1)
        cout << element << " found at index " << num << endl;
    else{
        cout << element << " is not in array [ ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "]\n";
    }
}

// Delete the element
void deleteElement(int arr[], int *n){
    int index;
    cout << "Enter the index, which has to be deleted : ";
    cin >> index;

    if(index >= *n){
        cout << "Can't Delete the element\n";
        return;
    }

    int a = arr[index];
    for (int i = index; i < (*n-1); i++)
        arr[i] = arr[i+1];
    *n -= 1;
    cout << a << " is deleted from position " << index << endl;

    display(arr, *n);
}

// Modify the element
void modify(int arr[], int n){
    int index, element;
    cout << "Enter the index, which has to be modified : ";
    cin >> index;
    cout << "Enter the element : ";
    cin >> element;
    arr[index] = element;
    cout << "Element is modified\n";
    display(arr, n);
}

// sort the elements
void sort(int arr[], int n){
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (n-i-1); j++)
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);

    cout << "Elements are sorted\n";
    display(arr, n);
}

// Main Function
int main(){
    int n;
    cout << "Enter the number of Elements : ";
    cin >> n;
    
    int arr[n];
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int choice;
    while(1){
        cout << "\n\n-- Select the correct option --\n";
        cout << "1. Search element\n";
        cout << "2. Delete element\n";
        cout << "3. Display all the elements\n";
        cout << "4. Modify element\n";
        cout << "5. Sort all the elements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice){
            case 1:
                search(arr, n);
                break;
            case 2:
                deleteElement(arr, &n);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                modify(arr, n);
                break;
            case 5:
                sort(arr, n);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Please choose correct option\n");
                break;
        }
    }
    return 0;
}