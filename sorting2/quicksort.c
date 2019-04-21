#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define randomize() (srand((unsigned)time(NULL)))
#define random(n) (rand() % (n) + start)
//인자로 들어온 인덱스 a , b 에 대해 인덱스에 해당되는
//배열의 값을 변경하기 위한 swap 함수
void swap(int *arr, int a, int b) {
        int tmp;
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
}
// 랜덤으로 배열의 인덱스를 구하기 위한 함수
int pickrandompivotindex(int *arr, int start, int end) {
        randomize();
return random(end-start+1);
}
int quicksort(int *arr, int start, int end) {
        int s; // (Small) pivot 보다 작은 원소에 대해 왼쪽에 추가할 인덱스용
        int k; // 일반 반복문에서 사용할 인덱스
        int randompivotindex; // 랜덤으로 뽑힌 인덱스 저장용 변수
        randompivotindex = pickrandompivotindex(arr, start, end); // 랜덤으로 인덱스 뽑기
        s = start - 1; // 인덱스 초기화, 인자로 들어온 start 인덱스보다 한 칸 왼쪽에 위치
        swap(arr, randompivotindex, end); // 인덱스를 배열의 끝 쪽과 바꾸기
        // 배열의 처음부터 끝 값 전까지 반복 실행, 피봇보다 값이 작으면 
        // s 인덱스에 해당하는 값과 바꾸면서 진행
        for(k = start; k < end; k++) {
            if(arr[k] < arr[end]) {
                s++;
                swap(arr, k, s);
           }
        }
        // 반복이 끝난 후, s+1 인덱스, 즉, s까지는 피봇보다 작은 값이 저장되어
        // 있으며, s+1 부터는 피봇보다 큰 값이 저장되어 있음
        swap(arr, end, s+1);
// s+1 위치를 리턴값으로 던져주기
return s+1;
}
void sort(int* arr, int start, int end) {
    if(start < end) { // 시작인덱스가 끝 인덱스보다 작다면
        int mid = quicksort(arr, start, end); // 피봇을 기준으로 정렬되어 있는 인덱스를 기준으로
        sort(arr, start, mid-1); // 피봇을 제외하고 피봇 이전까지 처음부터 다시 sort를 진행
        sort(arr, mid+1, end); // 피봇을 제외하고 피봇 이후부터 끝까지 다시 sort를 진행
    }
}
// 함수의 초기 call
void QUICK_SORT(int* arr, int size) {
    sort(arr, 0, size - 1);
}
void quickSort(int* arr, int size) 
{
/*
메인 함수와 quicksort.c에도 매크로 함수와 헤더파일 추가하였습니다.
#include <time.h>
#define randomize() (srand((unsigned)time(NULL)))
#define random(n) (rand() % (n) + start)
*/

   /* Your Implementation */
    QUICK_SORT(arr, size);
}
