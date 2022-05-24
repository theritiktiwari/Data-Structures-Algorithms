#include<stdio.h>
#include<stdlib.h>

// Search the element
void search(int arr[], int n){
    int element, num, f = 0;
    printf("Enter the element, which has to be searched : ");
    scanf("%d", &element);
    for (int i = 0; i < n; i++)
        if(arr[i] == element){
            f = 1;
            num = i;
            break;
        }
    if(f == 1)
        printf("%d found at index %d\n", element, num);
    else{
        printf("%d is not in array [ ", element);
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("]\n");
    }
}

// Delete the element

void delete(int arr[], int *n){
    int index;
    printf("Enter the index, which has to be deleted : ");
    scanf("%d", &index);
    if(index >= *n){
        printf("Can't Delete\n");
    } else {
        int a = arr[index];
        for (int i = index; i < (*n-1); i++)
        {
            arr[i] = arr[i+1];
        }
        *n -= 1;
        printf("%d is deleted from position %d\n", a, index);
    }
}

// Display the elements

void display(int arr[], int n){
    printf("Elements are : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main Function

int main()
{
    int n;
    printf("Enter the number of Elements : ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter Elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        
    int choice;
    while(1)
    {
        printf("\n\n-- Select the correct option --\n");
        printf("1. Search the elements\n");
        printf("2. Delete the elements\n");
        printf("3. Display all the elements\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                search(arr, n);
                break;
            case 2:
                delete (arr, &n);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Please choose correct option\n");
                break;
        }
    }
    return 0;
}