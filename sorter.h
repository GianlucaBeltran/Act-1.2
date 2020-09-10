#ifndef sorter_h
#define sorter_h

#include <iostream>
#include <vector>



template <typename T>
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};


template <typename T>
class SelectionSort : public Sorter<T>
{
    public:
    SelectionSort() {};
    ~SelectionSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i+1; j < arr.size(); j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
            Sorter<T>::swap(i, min, arr);
        }        
    };
};


template <typename T>
class BubbleSort : public Sorter<T>
{
    public:
    BubbleSort() {};
    ~BubbleSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            bool no_swap = true;
            for (size_t j = 0; j < arr.size() - i-1; j++)
            {
                if (arr[j] > arr[j+1]) {
                    Sorter<T>::swap(j, j+1, arr);
                    no_swap = false;
                }
            }
            if (no_swap)
                break;
        }        
    };
};

template <typename T>
class InsertionSort : public Sorter<T>
{
    public:
    InsertionSort() {};
    ~InsertionSort() {};

    void sort(std::vector<T> &arr)
    {
        T key;
        for (size_t i = 1; i < arr.size(); i++)
        {
            key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }        
    };
};

template <typename T>
class MergeSort : public Sorter<T>
{
    public:
    MergeSort() {};
    ~MergeSort() {};

    void sort(std::vector<T> &arr)
    {
        mergesort(arr, 0, arr.size()-1);
    };

    void mergesort(std::vector<T> &arr, int l, int r)
    {
        if (l < r) {
            int m = l + (r-l) / 2;
            
            mergesort(arr, l, m);
            mergesort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }

    void merge(std::vector<T> &arr, int l, int m, int r)
    {
        // declare variables
        int leftLength = m-l+1;
        int rightLength = r - m;
        std::vector<T> L;
        std::vector<T> R; 
        
        // fill temporal arrays left | right
        for (int i=0; i < leftLength; i++) // Left Array
            L.push_back(arr[l+i]);

    
        for (int i =0; i < rightLength; i++) // Right Array 
            R.push_back(arr[m + 1 + i]);


        int i = 0 , j = 0, k = l;
        
        while(i < leftLength && j < rightLength)
        {
            if (L[i] < R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
                
        if( j < rightLength)
        {
            for(j; j < rightLength; j++)
            {
                arr[k] = R[j];
                k++;
            }
        }
        else
        {
            for (i; i < leftLength; i++)
            {
                arr[k] = L[i];
                k++;
            }
        }
    }
};

template <typename T>
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(std::vector<T> &arr)
    {
        quicksort(arr, 0, arr.size() - 1);
    };

    void quicksort(std::vector<T> &arr, int low, int high)
    {
        if (low < high)  
        {  
            /* pi is partitioning index, arr[p] is now  
            at right place */
            int pi = partition(arr, low, high);  
      
            // Separately sort elements before  
            // partition and after partition  
            quicksort(arr, low, pi - 1);  
            quicksort(arr, pi + 1, high);  
        }  
    };

    /* This function takes last element as pivot, places  
    the pivot element at its correct position in sorted  
    array, and places all smaller (smaller than pivot)  
    to left of pivot and all greater elements to right  
    of pivot */
    int partition (std::vector<T> &arr, int low, int high)
    {  
        T pivot = arr[high]; // pivot  
        int i = (low - 1);     // Index of smaller element  
      
        for (int j = low; j <= high - 1; j++)  
        {  
            // If current element is smaller than the pivot  
            if (arr[j] < pivot)  
            {  
                i++; // increment index of smaller element
                Sorter<T>::swap(i, j, arr);
            }  
        }  
        Sorter<T>::swap(i+1, high, arr);
        return (i + 1);  
    }; 
};

#endif