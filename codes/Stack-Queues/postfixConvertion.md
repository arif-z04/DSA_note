Great — this is a **fully correct infix → postfix → evaluation system** with multi-digit support. I’ll explain it function by function, and also show how data flows step-by-step.

---

# 1. `precedence()` Function

```cpp
int precedence(char op)
```

## Purpose

Decides **priority of operators** so we know which one should be executed first.

---

## Code

```cpp
if (op == '^') return 3;
```

* Highest priority
* Example: `2 ^ 3`

---

```cpp
if (op == '*' || op == '/' || op == '%')
    return 2;
```

* Medium priority
* Example: `2 * 3`, `6 / 2`

---

```cpp
if (op == '+' || op == '-')
    return 1;
```

* Lowest priority
* Example: `2 + 3`

---

```cpp
return 0;
```

* For `(` or unknown characters

---

## Summary

| Operator | Priority |
| -------- | -------- |
| ^        | 3        |
| * / %    | 2        |
| + -      | 1        |

---

# 2. `infixToPostfix()`

---

## Purpose

Converts:

```text
(12 + 25) * 4
```

into:

```text
12 25 + 4 *
```

(using postfix notation with spaces)

---

## Key Idea

We use a **stack to store operators temporarily**.

Operands go directly to output.

---

# Step-by-step explanation

## Function header

```cpp
string infixToPostfix(string infix)
```

Input: infix expression
Output: postfix expression (string)

---

## Stack and output

```cpp
stack<char> st;
string postfix = "";
```

* `st` → stores operators like `+ - * /`
* `postfix` → final result

---

## Loop through expression

```cpp
for (int i = 0; i < infix.size(); i++)
```

We scan character by character.

---

# CASE 1: Space

```cpp
if (ch == ' ')
    continue;
```

Ignore spaces in input.

---

# CASE 2: Number (multi-digit)

```cpp
if (isdigit(ch))
```

### Important part

```cpp
while (i < infix.size() && isdigit(infix[i]))
{
    postfix += infix[i];
    i++;
}
```

### What it does:

If input is:

```text
25
```

It reads both digits together → `"25"`

---

### Then:

```cpp
postfix += ' ';
```

We add a space to separate tokens.

So:

```text
25 becomes "25 "
```

---

### Why decrement i?

```cpp
i--;
```

Because the outer loop will also increment `i`.

We adjust to avoid skipping characters.

---

# CASE 3: '('

```cpp
st.push(ch);
```

We store it until we find `)`.

---

# CASE 4: ')'

```cpp
while (!st.empty() && st.top() != '(')
```

Pop all operators inside parentheses.

---

Example:

```text
(12 + 25)
```

Stack:

```text
(
+
```

We pop `+`.

---

Then:

```cpp
st.pop(); // remove '('
```

---

# CASE 5: Operator (+ - * / ^)

```cpp
else
```

This is the most important logic.

---

## While condition

```cpp
while (!st.empty() &&
       precedence(st.top()) >= precedence(ch))
```

### Meaning:

👉 If stack top has higher or equal priority, pop it first.

---

## Example

Input:

```text
2 + 3 * 4
```

### When we see `*`:

Stack contains:

```text
+
```

We compare:

```text
precedence('+') = 1
precedence('*') = 2
```

Since `1 >= 2` is false → we push `*`.

---

## Then push operator

```cpp
st.push(ch);
```

---

# AFTER LOOP

```cpp
while (!st.empty())
```

Pop remaining operators.

---

## Final return

```cpp
return postfix;
```

---

# 3. `evaluatePostfix()`

---

## Purpose

Evaluates:

```text
12 25 + 4 *
```

---

## Stack for numbers

```cpp
stack<int> st;
```

Stores operands.

---

## Tokenization

```cpp
stringstream ss(postfix);
string token;
```

This splits input by spaces:

Example:

```text
12 25 + 4 *
```

becomes:

```text
"12"
"25"
"+"
"4"
"*"
```

---

## Loop tokens

```cpp
while (ss >> token)
```

---

# CASE 1: Number

```cpp
if (isdigit(token[0]))
```

Example:

```text
"25"
```

Convert:

```cpp
stoi(token)
```

Push into stack.

---

# CASE 2: Operator

```cpp
else
```

We pop two values:

```cpp
operand2 = top
operand1 = next top
```

---

## Why operand2 first?

Because:

```text
operand1 operator operand2
```

Example:

```text
2 - 3
```

If reversed → wrong result.

---

## Switch statement

### Addition

```cpp
operand1 + operand2
```

---

### Subtraction

```cpp
operand1 - operand2
```

---

### Multiplication

```cpp
operand1 * operand2
```

---

### Division

```cpp
operand1 / operand2
```

---

### Power

```cpp
pow(operand1, operand2)
```

---

## Push result back

```cpp
st.push(result);
```

---

# Final result

```cpp
return st.top();
```

---

# FULL FLOW EXAMPLE

Input:

```text
(12 + 25) * 4
```

---

## Step 1: infix → postfix

```text
12 25 + 4 *
```

---

## Step 2: evaluation

Stack operations:

### Push 12

```
12
```

### Push 25

```
12 25
```

### + → 12 + 25 = 37

```
37
```

### Push 4

```
37 4
```

### * → 37 * 4 = 148

```
148
```

---

## Final output

```text
Postfix Expression: 12 25 + 4 *
Result = 148
```

---

# KEY IDEA SUMMARY

### infixToPostfix

* Uses **stack for operators**
* Uses **string for output**
* Handles:

  * precedence
  * parentheses
  * multi-digit numbers

---

### evaluatePostfix

* Uses **stack for values**
* Uses **tokenization**
* Applies operations when operator appears

---

