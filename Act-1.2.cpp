#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "sorter.h"
#include "AlgoBusqueda.h"

using namespace std;


int main()
{
    srand (time(NULL)); // seed for random numbers

    int size, numberOfSearches, count = 1;
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter number of searches: ";
    cin >> numberOfSearches;

    // generate a random vector array
    vector<int> arr;
    for (size_t i = 0; i < size; i++)
    {
        arr.push_back(rand() % size);
    }

    while (numberOfSearches > 0)
    {
        int number, sortAlgorithm;
        vector<int> arrSorted(arr);

        cout << "SEARCH NUMBER " << count << endl; 

        cout << "What number do you want to find: ";
        cin >> number;

        Search <int> sequentialIndex(arr, number);
        cout << "Sequential search index: " << sequentialIndex.sequentialSearch() << endl;

        Search <int> binarySearch(arrSorted, number);
        cout << "What sorting algorithm should binary search use? (1 for insertion sort, 2 for bubblesort, 3 for quicksort): ";
        cin >> sortAlgorithm;

        if(sortAlgorithm == 1)
        {
            InsertionSort <int> insort;
            insort.sort(arrSorted);
        }
        else if(sortAlgorithm == 2)
        {
            BubbleSort <int> bubsort;
            bubsort.sort(arrSorted);
        }
        else
        {
            Quicksort <int> quicksort;
            quicksort.sort(arrSorted);
        }

        cout << "Binary search index: " << binarySearch.binarySearch(0, arr.size() - 1) << endl;
        numberOfSearches--;
        count++;
    }
    return 1;
};