#include <iostream>
#include <omp.h>  

using namespace std;

int main() {
    const int SIZE = 500000000;  
    int* arr = new int[SIZE];
    long long sum = 0;

   
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  
    }

    int num_threads = 2;  
    double start_time = omp_get_wtime();

    
    #pragma omp parallel for reduction(+:sum) num_threads(num_threads) schedule(dynamic, 100000)
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    double end_time = omp_get_wtime();

    cout << "Sum of array elements: " << sum << endl;
    cout << "Execution time: " << (end_time - start_time) << " seconds" << endl;
    cout << "Number of threads: " << num_threads << endl;

    delete[] arr; 
    return 0;
}
