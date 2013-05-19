#include "sort.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapSort(int numbers[], int len) {
    int i=0;
    heapify(numbers, len);
    for (i=len-1; i >= 1; i--) {
        swap(numbers+0, numbers+i);
        siftDown(numbers, 0, i-1);
    }
}

void heapify(int numbers[], int len) {
    int i=0;
    for (i=(len/2)-1; i>=0; i--)
        siftDown(numbers, i, len);
}

void siftDown(int numbers[], int root, int bottom) {
    int done = 0, maxchild = 0;
    while ((root*2 <= bottom) && (!done)) {
        maxchild = (root*2 == bottom || numbers[root * 2] > numbers[root * 2 + 1]) ? (root*2) : (root*2 + 1);
        if (numbers[root] >= numbers[maxchild])
            break;
        swap(numbers+root, numbers+maxchild);
        root = maxchild;
    }
}

void quickSort(int numbers[], int start, int end) {
    if (end <= start)
        return;
    int i = start, j = end, pivot = numbers[(start+end)/2];
    while (i < j) {
        while (numbers[i] < pivot)
            ++i;
        while (numbers[j] > pivot)
            --j;
        if (i < j) {
            swap(numbers+i, numbers+j);
            ++i;
            --j;
        }
    }
    quickSort(numbers, start, i-1);
    quickSort(numbers, j+1, end);
}
