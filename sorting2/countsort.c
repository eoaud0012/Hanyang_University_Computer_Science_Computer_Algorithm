#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define randomize() (srand((unsigned)time(NULL)))
#define random(n) (rand() % (n) + start)
// 최댓값을 구하기 위한 함수
int getMax(int *arr, int size) {
        int i;
        int max = arr[0];
        for(i = 0; i < size; i++)
            if(arr[i] >= max)
                max = arr[i];
                        
return max;
}
// 최솟값을 구하기 위한 함수
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
    int arrmin = getMin(arr, size); // 최솟값 arrmin
    int arrmax = getMax(arr, size); // 최댓값 arrmax

    int *tmpArr = (int*)malloc(sizeof(int) * (arrmax+1)); // 임시 배열 1
    int *sortedArr = (int*)malloc(sizeof(int) * (size+1)); // 임시 배열 2 생성

    for(i = 0; i <= arrmax; i++) // 임시 배열 1 초기화
        tmpArr[i] = 0;

    for(i = 0; i < size; i++) // arr 배열 값을 인덱스화, 임시 배열1에 횟수를 저장
        tmpArr[arr[i]] += 1;

    for(i = arrmin+1; i < arrmax+1; i++) // 임시배열1에서 배열 원소를 더함으로써 위치 정보를 파악해냄
        tmpArr[i] += tmpArr[i-1];

    for(i = 0; i < size; i++) { //sortedarr 임시배열2에 임시배열1의 원소를 인덱스화 하여 차례대로 저장
        sortedArr[tmpArr[arr[i]]] = arr[i];
         tmpArr[arr[i]] -= 1;
    }
    // sortedarr 값을 arr에 다시 복사
    for(i = 1; i < size+1; i++)
        arr[i-1] = sortedArr[i];
    
// 메모리 해제
    free(tmpArr);
    tmpArr = NULL;
    free(sortedArr);
    sortedArr = NULL;
}

void countSort(int* arr, int size) {
    CountSort(arr, size);
}
