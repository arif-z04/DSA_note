#include <iostream>
using namespace std;

int moveCount = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        moveCount++;

        cout << "Move " << moveCount
             << ": Disk 1 from "
             << source << " -> "
             << destination << endl;

        return;
    }

    // Step 1
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2
    moveCount++;

    cout << "Move " << moveCount
         << ": Disk " << n
         << " from "
         << source << " -> "
         << destination << endl;

    // Step 3
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSteps:\n\n";

    towerOfHanoi(n, 'A', 'B', 'C');

    cout << "\nTotal Moves = " << moveCount << endl;

    return 0;
}