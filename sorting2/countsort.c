#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define randomize() (srand((unsigned)time(NULL)))
#define random(n) (rand() % (n) + start)
int getMax(int *arr, int size) {
        int i;
        int max = arr[0];
        for(i = 0; i < size; i++)
            if(arr[i] >= max)
                max = arr[i];
                        
return max;
}
int getMin(int *arr, int size) {
        int i;
        int min = arr[0];
        for(i = 0; i < size; i++)
            if(arr[i] <= min)
                min = arr[i];
                        
return min;
}
void CountSort(int* arr, int size)
{
    int i;
    int arrsize = size;
    int arrmin = getMin(arr, size);
    int arrmax = getMax(arr, size);

    int *tmpArr = (int*)malloc(sizeof(int) * (arrmax+1));
    int *sortedArr = (int*)malloc(sizeof(int) * (size+1));

    for(i = 0; i <= arrmax; i++)
        tmpArr[i] = 0;

    for(i = 0; i < size; i++)
        tmpArr[arr[i]] += 1;

    for(i = arrmin+1; i < arrmax+1; i++)
        tmpArr[i] += tmpArr[i-1];

    for(i = 0; i < size; i++) {
        sortedArr[tmpArr[arr[i]]] = arr[i];
         tmpArr[arr[i]] -= 1;
    }
                                      
    for(i = 1; i < size+1; i++)
        arr[i-1] = sortedArr[i];
    

    free(tmpArr);
    tmpArr = NULL;
    free(sortedArr);
    sortedArr = NULL;
}

void countSort(int* arr, int size) {
    CountSort(arr, size);
}
