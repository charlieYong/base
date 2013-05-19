#ifndef _CY_SORT_H_
#define _CY_SORT_H_

void heapSort(int numbers[], int len);
void heapify(int numbers[], int len);
void siftDown(int numbers[], int root, int bottom);

void quickSort(int numbers[], int start, int end);

#endif
