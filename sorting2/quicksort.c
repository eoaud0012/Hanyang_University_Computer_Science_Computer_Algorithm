#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define randomize() (srand((unsigned)time(NULL)))
#define random(n) (rand() % (n) + start)

void swap(int *arr, int a, int b) {
        int tmp;
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
}
int pickrandompivotindex(int *arr, int start, int end) {
        randomize();
return random(end-start+1);
}
int quicksort(int *arr, int start, int end) {
        int s; // (Small) pivot 보다 작은 원소에 대해 왼쪽에 추가할 인덱스용
        int k; 
        int randompivotindex;
        randompivotindex = pickrandompivotindex(arr, start, end);
        s = start - 1;
        swap(arr, randompivotindex, end);
        for(k = start; k < end; k++) {
            if(arr[k] < arr[end]) {
                s++;
                swap(arr, k, s);
           }
        }
        swap(arr, end, s+1);
return s+1;
}
void sort(int* arr, int start, int end) {
    if(start < end) {
        int mid = quicksort(arr, start, end);
        sort(arr, start, mid-1);
        sort(arr, mid+1, end);
    }
}
void QUICK_SORT(int* arr, int size) {
    sort(arr, 0, size - 1);
}
void quickSort(int* arr, int size) 
{
/*
메인 함수에 매크로 함수와 헤더파일 추가하였습니다.
#include <time.h>
#define randomize() (srand((unsigned)time(NULL)))
#define random(n) (rand() % (n) + start)
*/

   /* Your Implementation */
    QUICK_SORT(arr, size);
}
