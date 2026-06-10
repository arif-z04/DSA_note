#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    stack<char> st;
    queue<char> q;

    // Fill stack and queue
    for (char c : s) {
        st.push(c);
        q.push(c);
    }

    // Compare both
    while (!st.empty()) {
        if (st.top() != q.front()) {
            return false;
        }
        st.pop();
        q.pop();
    }

    return true;
}

int main() {
    string s;
    getline(cin, s);

    if (isPalindrome(s)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }

    return 0;
}