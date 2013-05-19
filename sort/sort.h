#ifndef __BASELIB_SORT_H__
#define __BASELIB_SORT_H__

void heapSort(int numbers[], int len);
void heapify(int numbers[], int len);
void siftDown(int numbers[], int root, int bottom);

void quickSort(int numbers[], int start, int end);

#endif
