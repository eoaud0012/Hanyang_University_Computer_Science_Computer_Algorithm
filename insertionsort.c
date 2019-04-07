
void insertionSort(int* arr, int size)
{
// second code
    int i, j, key;
    for(j = 1; j < sizeof(arr)/sizeof(int); j++) {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
    }
    
/* first code
    int i, j, key;
    for(i=1; i<sizeof(arr)/sizeof(int); i++) {
        key = arr[i];
        for(j=i-1; j>=0; j--) {
            if(arr[j+1] = arr[j]) {
                arr[j+1] = arr[j];
                arr[j] = key;
            }
            else if(arr[j] < arr[j+1])
                break;
        }
    }
*/
}
