#include <iostream>
#include <ctime>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

// clock_t Start = clock();
// //call sort function here
// clock_t End = clock();
// int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

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

int partition(int numbers[], int i, int k) {
    int low;
    int high;
    int mid;
    int pivot;
    int temp;
    bool done;

    mid = i + (k - i) / 2;
    pivot = numbers[mid];

    done = false;
    low = i;
    high = k;

    while (!done) {
        while (numbers[low] < pivot) {
            low += 1;
        }

        while (pivot < numbers[high]) {
            high -= 1;
        }

        if (low >= high) {
            done = true;
        }
        else {
            temp = numbers[low];
            numbers[low] = numbers[high];
            numbers[high] = temp;

            low += 1;
            high -= 1;
        }
    }
    return high;
}


// this function sorts the given array in the range from i to k using quicksort method. In this 
// function, pivot is the midpoint element (numbers[(i+k)/2])
void Quicksort_midpoint(int numbers[], int i, int k) {
    int j;

    if (i >= k) {
        return;
    }

    j = partition(numbers, i, k);

    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j+1, k);
}


//this function utilizes different pivot selection technique in quicksort algorithm. The pivot is the median of 
//the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). 
//You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.
void Quicksort_medianOfThree(int numbers[], int i, int k) {
    return;
}

//this function sorts the given array using InsertionSort method. (implementation of this method is provided in section 21.3).
void InsertionSort(int numbers[], int numbersSize) {
    return;
}

int main() {

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1, arr2, arr3);

    clock_t Start = clock();
    //call sort function here
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
    cout << "Quicksort midpoint method runtime: " << elapsedTime << endl;

    return 0;
}