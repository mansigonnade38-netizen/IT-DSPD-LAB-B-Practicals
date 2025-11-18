// Practical 1B. Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL. implement the following algorithm: • Examine the value in the middle of the current array and print it. • If the midpoint value is the value that we are looking for, return true • If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index. • if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint and print the index. • Continue until you find the value, or until the start reaches the end.
#include <stdio.h>

int findkey(int arr[], int key, int n) {
    int s = 0;
    int e = n - 1; 
    int m;
    int i;

    while (s <= e) {
        printf("Printing the search space: ");
        for (i = s; i <= e; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        m = (s + e) / 2;

        if (arr[m] == key) { 
            return m;
        } else if (arr[m] < key) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[100];
    int n;
    int i;
    int key, result;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array (in sorted order):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    result = findkey(arr, key, n);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
