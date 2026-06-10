#include <bits/stdc++.h>

using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    stack<int> st;
    for (char ch : postfix)
    {
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }

        else
        {
            int operand2 = st.top();
            st.pop();

            int operand1 = st.top();
            st.pop();

            int result;

            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;

            case '-':
                result = operand1 - operand2;
                break;

            case '*':
                result = operand1 * operand2;
                break;

            case '/':
                result = operand1 / operand2;
                break;

            case '^':
                result = pow(operand1, operand2);
                break;

            default:
                result = 0;
            }
            st.push(result);
        }
    }

    return st.top();
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: "
         << postfix
         << endl;

    cout << "Result = "
         << evaluatePostfix(postfix)
         << endl;

    return 0;
}