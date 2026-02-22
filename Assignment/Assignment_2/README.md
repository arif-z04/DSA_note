# Assignement 2

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
