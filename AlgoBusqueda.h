#include <iostream>
#include <stdlib.h>   
#include <time.h>  
#include <vector>
#include <algorithm>

template <typename T>
class Search
{
private:
    std::vector <T> elements, sortedElements;
    T numberToFind;

public:
    Search(std::vector <T> _arr, T _numberToFind)
    {
        elements = _arr;
        numberToFind = _numberToFind;
        sortedElements = _arr;
        sort (sortedElements.begin(), sortedElements.end());
    }

    T sequentialSearch()
    {
        for(int i = 0; i < elements.size(); i++)
        {
            if(elements[i] == numberToFind)
                return i;
        }

        return -1;
    }

    T sortedSequentialSearch1()
    {
        for(int i = 0; i < sortedElements.size(); i++)
        {
            if(sortedElements[i] == numberToFind)
                return i;
            
            if(sortedElements[i] > numberToFind)
                return -1;
        }

        return -1;
    }

    T sortedSequentialSearch2(T step)               
    {
        int i = 0;
        while(i < sortedElements.size())
        {
            if(sortedElements[i] == numberToFind)
                return i;
            
            if(sortedElements[i] > numberToFind)
            {
                for(int j = i; j > (i - step); j--)
                {
                    if(sortedElements[j] == numberToFind)
                        return j;
                }

                return -1;
            }
            i += step;
        }

        return -1;
    }

    T binarySearch(int lowerBound, int upperBound)
    {
        int middleIndex = (lowerBound + upperBound) / 2;
        if(lowerBound > upperBound)
            return -1;

        if(sortedElements[middleIndex] == numberToFind)
            return middleIndex;

        if(sortedElements[middleIndex] < numberToFind)
            return binarySearch(middleIndex + 1, upperBound);
        else
            return binarySearch(lowerBound, middleIndex - 1);
    }

};