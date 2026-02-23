# Assignement 2

> _Author: S M Arifuzzaman_ 
> 
> _ID: 2302054_

## Chapter - 4: Array, Records and Pointers

## 4.1 Traversing

In traversing, we will visit every single element

Algorithm:
```Fortran
(Traversing a Linear Array) Here LA is a linear array with lower 
bound LB and upper bound UB. This algorithm traverses LA applying
an operation PROCESS to each element of LA

1. Set K:= LB
2. Repeat Steps 3 and 4 while K <= UB:
3.      Apply PROCESS to LA[K]
4.      Set K:= K + 1
5. Exit
```
```Fortran
4.1(2): This algorithm traverses a linear array LA with lower bound
LB and upper bound UB

1. Repeat for K = LB to UB:
        Apply PROCESS to LA[K]
2. Exit
```


Code:
```c++
#include <iostream>
using namespace std;

void traverse_1(int arr[], int lower_bound, int upper_bound) {
    int temp = lower_bound;
    while (temp <= upper_bound) {
        cout << arr[temp] << " ";
        temp++;
    }
    cout << endl;
}

void traverse_2(int arr[], int lower_bound, int upper_bound) {
    for (int i = lower_bound; i <= upper_bound; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    traverse_1(arr, 0, 4);
    traverse_2(arr, 0, 4);
}
```
---

## 4.2 Insertion into an array

Algorithm

```Fortran
(Inserting into a Linear Array) INSERT(LA, N, K, ITEM)
Here LA is a linear array with N elements and K is a positive integer
such that K <= N. This algorithm inserts an eleemtn ITEM into the Kth position in LA.

1. Set J := N
2. Repeat steps 3 and 4 while J <= K
3.      Set LA[J + 1] := LA[J]
4.      Set J := J - 1
5. Set LA[K] := ITEM
6. Set N := N + 1
7. Exit
```

Code:

```C++
#include <iostream>
using namespace std;

int insert(int arr[], int n, int k, int item) {
    // for (int i = n - 1; i >= k; i--) {
    //     arr[i + 1] = arr[i];
    // }
    
    int j = n - 1;
    while (j >= k) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[k] = item;
    return n + 1;
}

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[50] = {1, 2, 3, 4, 5};
    int n = 5; // number of elements in the array
    int k = 2; // position to insert a new value
    int item = 10; // value to insert

    n = insert(arr, n, k - 1, item);
    printArray(arr, n);
}
```
---

## 4.3 Delation in arrays

Algorithm:
```nginx
(Deleting from a Linear Array) DELETE(LA, N, K, ITEM)
Here LA is a linear array with N elements and K is a positive 
integer such that K <= N. This algorithm inserts an element ITEM
into the Kth position in LA.

1. Set J := N
2. Repeat Steps for J = K to N - 1:
        Set LA[J] := LA[J+1]
3. Set N := N - 1
4. Exit
```
Code:
```C++
#include <iostream>
using namespace std;

int deleteElement(int arr[], int n, int k) {
    // int item = arr[k]; // for processing     
    for (int j=k; j < n-1; j++) {
        arr[j] = arr[j+1];
    }
    return n - 1;
}

void printArray(int arr[], int n) {
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[50] = {1, 2, 3, 4, 5};
    int n = 5; // number of elements in the array
    int k = 2; // position to deleteElement a new value

    n = deleteElement(arr, n, k - 1);
    printArray(arr, n);
}
```
---

## 4.4 Bubble Sort

Algorithm:
```Fortran
BUBBLE(DATA, N)
1. Repeat Steps 2 and 3 for K = 1 to N - 1
2.      Set PTR := 1
3.      Repeat while PTR <= N - K:
            (a) If DATA[PTR] > DATA[PTR + 1] then
                    swap DATA[PTR] and DATA[PTR + 1]
            (b) Set PTR := PTR + 1
4. Exit
```
Code:
```C++
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubbleSort(int *arr, int n) {
    for (int i=0; i< n; i++) {
        for (int j=0; j < n-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int *arr, int n) {
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 2, 39, -4, 25};
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    printArray(arr, sizeof(arr)/sizeof(int));
}
```
---

## 4.5 Linear Search 

Code:
```C++
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int item) {
    for (int i=0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    } // While loop? Try yourself!
    return -1;
}

int main() {
    int arr[] = {12, 2, 39, -4, 25};
    int item = 39;
    cout << linearSearch(arr, sizeof(arr)/sizeof(int), item) << endl;
}
```
---

## 4.6 Binary Search

Code:
```C++
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int item) {
    int lower_bound = 0;
    int upper_bound = n - 1;
    while (lower_bound <= upper_bound) {
        int mid = (lower_bound + upper_bound) / 2;
        if (arr[mid] == item) {
            return mid;
        } else if (arr[mid] < item) {
            lower_bound = mid + 1;
        } else {
            upper_bound = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {12, 2, 39, -4, 25};
    int item = 39;
    cout << binarySearch(arr, sizeof(arr)/sizeof(int), item) << endl;
}
```
---

## 4.7 Matrix Multiplication

Code:
```C++
#include <iostream>
using namespace std;

void matrixMultiplication(int matrix_a[][3], int matrix_b[][3], int M, int P, int N) {
    int matrix_c[M][N];
    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            matrix_c[i][j] = 0;
            for (int k=0; k < P; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            cout << matrix_c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix_a[][3] = {{1, -2, 3}, {0, 4, 5}}; // M x P
    int matrix_b[][3] = {{3, 0, -6}, {2, -3, 1}, {2, 5, 3}}; // P x N

    matrixMultiplication(matrix_a, matrix_b, 2, 3, 3);
}
```