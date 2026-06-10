#include <iostream>
using namespace std;

void printTree(int n, string prefix = "", bool isLast = true)
{
    cout << prefix;

    if (!prefix.empty())
        cout << (isLast ? "└── " : "├── ");

    cout << "TOH(" << n << ")" << endl;

    if (n == 1)
        return;

    string childPrefix = prefix + (isLast ? "    " : "│   ");

    // First child
    printTree(n - 1, childPrefix, false);

    // Middle child (move)
    cout << childPrefix << "├── Move Disk " << n << endl;

    // Last child
    printTree(n - 1, childPrefix, true);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    printTree(n);

    return 0;
}