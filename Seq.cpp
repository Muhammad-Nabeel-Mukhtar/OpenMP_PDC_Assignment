#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    const int size = 500000000;
    int *arr = new int[size];
    long long sum = 0;

    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    clock_t start = clock();

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sum of array elements: " << sum << endl;
    cout << "Execution time: " << time_taken << " seconds" << endl;

    delete[] arr;
    return 0;
}
