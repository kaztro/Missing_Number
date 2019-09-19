#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>


using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low -1);

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return(i + 1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low,pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void missingNumber(int A[], int sA, int next, int aux){
    if (aux < sA) missingNumber(A, sA, next, aux + 1);
    else {
        next = A[aux - 1];
        next++;
        if(next%2 != 0) next++;
        cout << next;
    }
}


//Funcion para llenar el arreglo
void fillArr(int *array, int sA, int aux) {
    if (aux < sA) {
        cout << "Input number " << aux + 1 << " of " << sA << endl;
        cin >> array[aux];
        fillArr(array, sA, aux + 1);
    }
}

void printArray(int arr[], int sA, int aux){
    if (aux < sA) {
        cout << arr[aux] << " ";
        printArray(arr, sA, aux + 1);
    }
}

int main() {
    int size;
    cout << "Gimme the size of the A array" << endl;
    cin >> size;

    int A[size];
    fillArr(A, size, 0);

    int n = sizeof(A) / sizeof(A[0]);

    cout<<"This is your array: \n";
    printArray(A, n, 0);
    cout << endl;

    quickSort(A, 0, n - 1);

    cout << "Sorted array: \n";
    printArray(A, n, 0);
    cout << endl;

    cout<<"The maximum missing number: \n";
    missingNumber(A, n, 0, 0);

    return 0;
}