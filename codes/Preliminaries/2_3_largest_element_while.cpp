#include <iostream>
using namespace std;

void LargestElementInArray(int DATA[], int N)
{
    int K = 0, LOC = 0, MAX = DATA[0];
    while (K < N)
    {
        if (MAX < DATA[K])
        {
            LOC = K;
            MAX = DATA[K];
        }
        K = K + 1;
    }
    cout << "LOC = " << LOC << ", MAX = " << MAX << "\n";
}

int main()
{
    int DATA[] = {3, 5, 9, 2};
    int N = sizeof(DATA) / sizeof(int);
    LargestElementInArray(DATA, N);
    return 0;
}