#include <stdio.h>
#include <stdlib.h>
#define size 100
int main(void)
{   
    printf("test ddddddddd  try");
    int arr[size]={0};
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
    return 0;
}

// void sort(int){
//     int max=0;
//     //0부터 끝-1 까지 돌아가면 현재 인덱스 ,, 현재 인덱스 +1 부터 끝까지 비교 . 
//     for(int k=0;k<size-1;i++){
//         int t=k+1;
//         for (t;t<size;t++){
// `           if(arr[k]<arr[t]) 
//         }
// }
// for(int i=0;i<10;i++){
//     printf("%d : %d\n",i,arr[i]);
// }
