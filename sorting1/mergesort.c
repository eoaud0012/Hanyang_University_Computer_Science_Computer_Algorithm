void merge(int* arr, int start, int mid, int end) {
    int i, j; //본 배열(arr)에서 이등분되어 사용될 양쪽 첫번째 인덱스
    int k; //분할된 배열의 값을 복사할 subarr배열에서 사용될 첫 번째 인덱스
    int x; // 마지막 단계에서 분할된 배열에서 본 배열에 복사할 때 사용할 인덱스
    int merge_size = start+end+1;
    int* subarr = (int*)malloc(sizeof(int)*merge_size);
    i = start; //본 배열의 절반 중 왼쪽 첫번째 인덱스
    j = mid+1; // 본 배열의 절반 중 오른쪽 첫번째 인덱스
    k = start; //subarr 의 전체 인덱스 중 첫번째 인덱스

    while(i <= mid && j <= end) {//이등분으로 분할된 배열에서 왼쪽 배열이 남아있고, 오른쪽 배열이 여전히 남아있다면,
        if(arr[i] <= arr[j]) //그리고, 왼쪽 배열의 원소보다, 오른쪽 배열의 원소가 더 크다면,
            subarr[k++] = arr[i++]; // 왼쪽 배열의 원소를 subarr에 순차적으로 삽입
        else subarr[k++] = arr[j++];// 오른쪽 배열의 원소를 subarr에 삽입
    }
    // 왼쪽 배열의 원소를 다 subarr에 보냈으나, 오른쪽 배열의 원소가 남았다면,
    if(i > mid) 
        while(j <= end) // 오른쪽 배열의 인덱스가 마지막 인덱스에 도착할때까지,
            subarr[k++] = arr[j++]; // subarr에 순차적으로 삽입
    else // 오른쪽 배열의 원소를 모두 subarr에 보냈으나, 왼쪽 배열의 원소가 남았다면,
        while(i <= mid) // 왼쪽 배열의 인덱스가 왼쪽 배열의 마지막 인덱스(mid)에 도착할때까지
            subarr[k++] = arr[i++]; // subarr에 순차적으로 삽입
    // 정렬된 원소가 저장되어 있는 subarr 의 원소를 본 배열인 arr에 다시 복사
    for(x = start; x <= end; x++)
        arr[x] = subarr[x];
    // 임시 배열 subarr 해제
    free(subarr);
}
// 분할 함수 sort
void sort(int* arr, int start, int end) {
    if(start < end) { // end 인덱스가 start 인덱스보다 크다면,
        int mid = (start+end) / 2; // 두 배열의 경계 인덱스 산출
        sort(arr, start, mid); // mid 경계 인덱스 기준으로 왼쪽 배열로 분할
        sort(arr, mid+1, end); // mid 다음 인덱스부터 오른쪽 배열로 분할
        merge(arr, start, mid, end); // 분할된 배열 합치기
    }
}
void mergeSort(int* arr, int size) {
    sort(arr, 0, size-1); // sort(배열주소, 시작인덱스, 마지막인덱스)
}
