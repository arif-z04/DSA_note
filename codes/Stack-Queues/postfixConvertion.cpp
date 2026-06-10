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

    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        // Number
        if (isdigit(ch))
        {
            while (i < infix.size() && isdigit(infix[i]))
            {
                postfix += infix[i];
                i++;
            }

            postfix += ' '; // separator
            i--;
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
                postfix += ' ';
                st.pop();
            }

            st.pop();
        }

        else
        {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    stack<int> st;

    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        // Number
        if (isdigit(token[0]))
        {
            st.push(stoi(token));
        }
        else
        {
            int operand2 = st.top();
            st.pop();

            int operand1 = st.top();
            st.pop();

            switch (token[0])
            {
            case '+':
                st.push(operand1 + operand2);
                break;

            case '-':
                st.push(operand1 - operand2);
                break;

            case '*':
                st.push(operand1 * operand2);
                break;

            case '/':
                st.push(operand1 / operand2);
                break;

            case '^':
                st.push(pow(operand1, operand2));
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: "
         << postfix
         << endl;

    cout << "Result = "
         << evaluatePostfix(postfix)
         << endl;

    return 0;
}