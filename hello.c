#include <stdio.h>

void MaxAndMin(int *parr, int size, int **mxPtr, int **mnPtr) 
// maxPtr과 minPtr의 주소값을 main 함수에서 받으므로, 매개변수는 이중포인터(int **)을 매개변수로 함
{
    int *max, *min; // 포인터 max,min 정의
    int i;

    max = min = parr; // 포인터 max와 min은 배열 arr을 가리킨다. max = min = &arr[0];
    printf("*max: %d, *min: %d \n", *max, *min);
    printf("max: %p, min: %p, arr: %p \n", max, min, parr);
    for(i = 0; i < size; i++)
    {
        if(*max < parr[i]) // *max = arr[0]
            max = &parr[i]; //&arr[0] = &arr[i]
        if(*min > parr[i]) // *min = arr[0]
            min = &parr[i]; // &arr[0] = &arr[i]
    }
    printf("max: %p, min: %p, arr: %p \n", max, min, parr);
    *mxPtr = max;
    *mnPtr = min;
    printf("*mxPtr: %p, *mnPtr: %p \n", *mxPtr, *mnPtr);
}

int main(void)
{
    int *maxPtr;
    int *minPtr;
    int arr[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("정수 입력 %d: ", i + 1);
        scanf("%d", &arr[i]);
        
    }
    MaxAndMin(arr, sizeof(arr)/sizeof(arr[0]), &maxPtr, &minPtr); // maxPtr과 minPtr 주소값을 인자로 전달
    printf("최대: %d, 최소: %d \n", *maxPtr, *minPtr);

    return 0;  
    //test
}