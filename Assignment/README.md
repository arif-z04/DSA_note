# Assignment 1


## Chapter 2: Preliminaries




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
    return 0;
}
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