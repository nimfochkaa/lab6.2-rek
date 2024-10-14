#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) 
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) 
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int FindMinEvenIndex(int* a, const int size, int i, int minIndex) 
{
    if (i == size) 
    {
        return minIndex;
    }
    if (a[i] % 2 == 0 && (minIndex == -1 || a[i] < a[minIndex])) 
    {
        minIndex = i;
    }
    return FindMinEvenIndex(a, size, i + 1, minIndex);
}

void SwapFirstWithMinEven(int* a, const int size) 
{
    int minEvenIndex = FindMinEvenIndex(a, size, 1, -1);
    if (minEvenIndex != -1) 
    {
        swap(a[0], a[minEvenIndex]);
    }
}

int main() 
{
    srand((unsigned)time(NULL));

    const int n = 22; 
    int a[n];
    int Low = -50;
    int High = 50;

    Create(a, n, Low, High, 0);
    cout << "Original array: ";
    Print(a, n, 0);

    SwapFirstWithMinEven(a, n);

    cout << "Modified array: ";
    Print(a, n, 0);

    return 0;
}

