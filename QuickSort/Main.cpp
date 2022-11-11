#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "QuickSort.h"

int rrand(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;;
}

int main()
{   

    /*
    string str = "";

    for (size_t size = 1; size <= 100; size++) {
        srand(time(nullptr));

        vector<int> mass(size);

        for (size_t i = 0; i < size; i++) {
            mass[i] = rrand(-50000, 50000);
        }

        vector<int> mass2(size);
        for (size_t i = 0; i < size; i++) {
            mass2[i] = mass[i];
        }

        auto start = chrono::high_resolution_clock::now();
        quickSort(&mass[0], &mass[size - 1], [](int a, int b) { return a < b; });
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << duration.count() * 10000.0 << endl;

        auto start2 = chrono::high_resolution_clock::now();
        insertionSort(&mass2[0], &mass2[size - 1], [](int a, int b) { return a < b; });
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double> duration2 = end2 - start2;
        //cout << duration2.count() * 1000 << endl;
        str += to_string(duration2.count() * 10000.0);
        str += "\n";
    }
    cout << endl <<endl<< str << endl;*/

  
     
}