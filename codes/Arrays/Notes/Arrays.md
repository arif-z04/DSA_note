# Arrays

Array is a collection of items stroed at **contiguous** memory locations.


## 1. Memory Model: Contiguous Allocation

When you declare an array in C++, the compiler reserves a singe, unbroken block of memory

```c++
int arr[5] = {10, 20, 30, 40, 50};
```

If an `int` is 4 bytes, this array takes 20 bytes of contiguous space. If the first element starts at memeory address `100`, the next is at `104`, then `108` and so on.

## 2. The Relationship between Arrays and Pointers

In C++, an array name is essentially a label for the memory address of the first element (index 0), This is known as **pointer decay**.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr; // arr "decays" to a pointer to its first element

cout << arr;     // Prints a memory address (e.g., 0x7ffe...)
cout << *arr;    // Prints 10 (dereferencing the address)
```

**The Secret Formula**

When you write `arr[i]`, the C++ compiler actually converts it to:
`*(arr + i)`

- Take the base address (arr).
- Add the index (i) multiplied by the size of the data type.
- Access the resulting memory address.
  
**Mind-blow moment:** Because of this math, `3[arr]` is technically valid in C++ and does the exact same thing as arr[3], because `*(3 + arr)` is the same as `*(arr + 3)`. (Don't do this in production, but it proves how the logic works!)


## 3. Static vs. Dynamic Arrays

### A. Static Arrays (Stack)
Allocated at compile-time. The size must be known before the program runs.

```c++
const int size = 10;
int stackArr[size]; // Allocated on the "Stack"
```
- Pros: Extremely fast allocation.
- Cons: Fixed size; if the function ends, the memory is reclaimed

### B. Dynamic Arrays (Heap)
Allocated at runtime using the `new` keyword

```c++
int n;
cin >> n;
int* heapArr = new int[n]; // Allocated on the "Heap"

// ... use the array ...

delete[] heapArr; // MUST manually delete to avoid memory leaks
```

- 