#include <iostream>
#include <ctime>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

clock_t Start = clock();
//call sort function here
clock_t End = clock();
int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

const int NUMBERS_SIZE = 50000;

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

// this function sorts the given array in the range from i to k using quicksort method. In this 
// function, pivot is the midpoint element (numbers[(i+k)/2])
void Quicksort_midpoint(int numbers[], int i, int k) {
    return;
}

//this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the median of 
//the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). 
//You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.
void Quicksort_medianOfThree(int numbers[], int i, int k) {
    int j;

    if (i >= k)
    {
        return;
    }

    j = Partition_Three(numbers, i, k);

    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j+1, k);
}

int Partition_Three(int numbers[], int i, int k)
{
    int l;
    int h;
    int midpoint;
    int pivot;
    int temp;
    bool done;

    midpoint = (i + ((i + k) / 2) + k) / 3;

    pivot = numbers[midpoint];
    done = false;
    l = i;
    h = k;
    
    while (!done)
    {
        while (numbers[l] < pivot)
        {
            ++l;
        }
        while (pivot < numbers[h])
        {
            --h;
        }
        if (l >= h)
        {
            done = true;
        }
        else
        {
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            ++l;
            --h;
        }

    }
    return h;
}

//this function sorts the given array using InsertionSort method. (implementation of this method is provided in section 21.3).
void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = 1; i < numbersSize; ++i)
    {
        j = i;
        while (j < 0 && numbers[j] < numbers[j - 1])
        {
            temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            --j;
        }
    }
}

int main() {



    return 0;
}