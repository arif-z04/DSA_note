# Assignment 1
---

## Chapter 2: Preliminaries

### 2.1 Largest Element in array

Used `goto` method here. (not recommended)

```cpp
#include <bits/stdc++.h>
using namespace std;

void LargestElementInArray(int DATA[], int N)
{
    int K = 0, LOC = 0, MAX = DATA[0];
increment_counter:
    K = K + 1;
    if (K == N)
    {
        cout << "LOC = " << LOC << ", MAX = " << MAX << "\n";
        return;
    }
    if (MAX < DATA[K])
    {
        LOC = K;
        MAX = DATA[K];
    }
    goto increment_counter;
}

int main()
{
    int DATA[] = {3, 5, 9, 2};
    int N = sizeof(DATA) / sizeof(int);
    LargestElementInArray(DATA, N);
    return 0;
}
```
### 2.2 Quadratic equation
### 2.3 Largest Element in array (while loop)

### 2.4 Linear Search
```cpp
#include <bits/stdc++.h>
using namespace std;

void LinearSearch(int DATA[], int N, int ITEM)
{
    int K = 0, LOC = -1;
    while (LOC == -1 && K < N)
    {
        if (ITEM == DATA[K])
            LOC = K;
        K = K + 1;
    }
    if (LOC == -1)
        cout << "ITEM is not on the array DATA\n";
    else
        cout << LOC << " is the location of ITEM\n";
    return;
}

int main()
{
    int DATA[] = {3, 5, 9, 2};
    int N = sizeof(DATA) / sizeof(int);
    int ITEM = 9;
    LinearSearch(DATA, N, ITEM);
    return 0;
}
```

### Input & Output:

**Input:**
```cpp
DATA = {3, 5, 9, 2}
ITEM = 9
```
**Output:**
```cpp
2 is the location of ITEM
```





---

## Chapter 3: String Processing 

### Algorithm: 3.1 Delation

```c++
#include <bits/stdc++.h>
using namespace std;

int searchPattern(string str, string pattern){
    int pat_len = pattern.length();
    int str_len = str.length();

    for(int i = 0; i <= str_len - pat_len; i++){
        for(int j = 0; j < pat_len; j++){
            if(str[i + j] != pattern[j]){
                break;
            } else if (j == pat_len - 1){
                return i;
            }
        }
    }
    return -1; // not found
}

string erase(string str, int idx, int pattern_length){
    string temp = "";
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(idx <= i && i <= idx + pattern_length - 1){
            continue;
        }
        temp += str[i];
    }

    return temp;
}

int main(){

    string str = "To be or not 2B, that is the B,?";
    string pattern = "B,";

    int index = searchPattern(str, pattern);

    while(index != -1){
        str = erase(str, index, pattern.length());
        index = searchPattern(str, pattern);
    }

    cout << str << endl;
    return 0;
}
```
### Input and Output:
Input: 
```css
To be or not 2B, that is the B,?
```
Output:
```css
To be or not 2 that is the ?
```


### Explanation: 

### **Function :** `int searchPattern()` 
* **Parameters :** `string str, string pattern`
* **Returns :** Gives the first index where `pattern` appears in `str`

* Example:
 
  If `str = "HELLO"` and `pattern = "LO"`
  - last valid start index is `3`

### Breaking down the loop:
```Cpp
for(int i = 0; i <= str_len - pat_len; i++)
```
- `i` starting index in `str`
- iteration upto `str_len - pat_len`, not to go out of bounds

**Inner Loop**
```Cpp
for(int j = 0; j < pat_len; j++)
```
- `j` - index inside `pattern`
- Compares: `str[i + j]` vs `pattern[j]`


> Note: Finding the pattern has the complexity of O(n * m) where `n` = length of the string, `m` = length of pattern.
> 
> This function checks only character by character, so matching only single character will give the index or else `-1`.

### Function: `string erase()`
**Parameters:** `string str, int idx, int pattern_length`
**Purpose:** Removes a substring from `str` starting at `idx` with length `pattern_length`

### Explanation: 
```cpp
string temp = "";
int length = str.length();
```
- Here, `temp` is the new string after deletion

**Loop:** 
```cpp
for(int i = 0; i < length; i++)
    // skips the pattern part
    if(idx <= i && i <= idx + pattern_length - 1){
        continue;
    }
```
**Example:**
```
str = "ABCDEF"
idx = 2
pattern_length = 2
```

- Characters at index `2` and `3` (`CD`) are skipped.
- Then the other characters are stored in `temp`
- Returns `temp` string. (The modified string)

---

### Algorithm: 3.2 Replacement

```cpp
#include <bits/stdc++.h>
using namespace std;

int searchPattern(string str, string pattern) {
    int pattern_length = pattern.length();
    int string_length = str.length();

    for (int i=0; i <= string_length - pattern_length; i++) {
        for (int j=0; j <pattern_length; j++) {
            if (str[i+j] != pattern[j]) {
                break;
            } else if (j == pattern_length - 1) {
                return i;
            }
        }
    }
    return -1;
}

string erase(string str, int index, int pattern_length) {
    string temp = "";
    int length = str.length();

    for (int i=0; i <length; i++) {
        if (index <= i && i <= index+pattern_length-1) {
            continue;
        }
        temp += str[i];
    }

    return temp;
}

string insert(string str, int index, string placeholder) {
    string temp = "";
    int length = str.length();

    for (int i=0; i <length; i++) {
        if (i == index) {
            temp += placeholder;
        }
        temp += str[i];
    }

    return temp;
}

int main()
{
    string str = "To be or not 2B, that is the?";
    string pattern = "2B";
    string placeholder = "to be";

    int index = searchPattern(str, pattern);
    str = eraseABit(str, index, pattern.length());
    str = insertABit(str, index, placeholder);

    cout << str << endl;
}
```

### Input & Ouput:

Input
```css
To be or not 2B, that is the?
```
Output
```css
To be or not to be, that is the?
```

### Explanation:

### Function : `string insert()`
**Parameters:** `string str, int index, string placeholder`

**Purpose**: Insert `placeholder` string before `index` in the string.

**Variables:**
- `string temp = "";`
- `int length = str.length()` 

**Loop**
```cpp
for(int i = 0; i < length; i++){
    if(i == index){
        temp += placeholder;
    }
    // index matches places the placeholder str
    
    temp += str[i]; // add original char

    return temp; // return updated str
}
```
> Note: In this algorithm, I used naive pattern matching and manual string deletion and insertion.

--- 

### Algorithm: 3.3 Pattern Matching

Pattern matching is the process of checking whether a given sequence of characters (pattern) is present in a given string or not. The simplest way to do this is to check each substring of the string with the pattern. If the substring matches the pattern, then return the index of the substring in the string. Otherwise, return -1.

```cpp
#include <bits/stdc++.h>
using namespace std;

int patternMatching(string str, int str_len, string pattern, int pattern_len)
{
    if (pattern_len > str_len)
        return -1;

    int k = 0, max = str_len - pattern_len + 1;
    while (k < max)
    {
        for (int l = 0; l < pattern_len; l++)
        {
            if (pattern[l] != str[l + k])
                break;
            if (l + 1 == pattern_len)
                return k;
        }
        k++;
    }
    return -1;
}

int main()
{
    string str = "To be or not 2B, that is the ?";
    string pattern = "B,";
    int index = patternMatching(str, str.length(), pattern, pattern.length());
    cout << "Index is : " << index << endl;
    return 0;
}
```

### Input & Output:

**Input:**
```
String  : "To be or not 2B, that is the ?"
Pattern : "B,"
```
**Output:**
```
Index is : 14
```

---