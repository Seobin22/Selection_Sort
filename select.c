#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void change(int *first, int *after){
    int temp;
    temp = *first;
    *first = *after;
    *after = temp;
}
void r_sort(int *arr,int an){
    if (an>0){
    int max;
    for(int top=0;top<an-1;top++){
        max=top;
        for (int t=top+1;t<an;t++){
            if(arr[max] < arr[t]) max=t;
            }    
            if (top!=max) change(&arr[top],&arr[max]);
        }                
}
}
int r_is_sorted(int A[],int n){
    for (int i=0; i<n-1;i++){
        if (A[i]<A[i+1]){
            return 0;
        }
    }
    return 1;
}
/////////////////////////////////////
void sort(int *arr,int an){
    if (an>0){
    int mi;
    //0부터 끝-1 까지 돌아가면 현재 인덱스 ,, 현재 인덱스 +1 부터 끝까지 비교 . 
    for(int top=0;top<an-1;top++){
        mi=top;
        for (int t=top+1;t<an;t++){
            if(arr[mi] > arr[t]) mi=t;
            }    
            if (top!=mi) change(&arr[top],&arr[mi]);
        }                
}
}
int is_sorted(int A[],int n){
    for (int i=0; i<n-1;i++){
        if (A[i]>A[i+1]){
            return 0;
        }
    }
    return 1;
}
///////////////////////////////////////////
int *makearr(int an){
    int *arr;
        arr=(int *)malloc(sizeof(int)*an);
        if (arr==NULL) {
            printf("no memory\n");
            return NULL;
        }
        if(an!=0){
        for(int i=0;i<an;i++){
        arr[i]=rand()%100000+1;
        }}
        return arr;
}


void timecheck(int A[],int an){
    /*for(step;step<10001;)*/
    clock_t start;
    double time_used;
    start = clock();
    r_sort(A,an); 
    time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("%10.3f",time_used);
    if (r_is_sorted(A,an)==1) printf("%10s\n","정렬됨");
    else printf("%10s\n","정렬안됨");
}
int D(int MAX_SIZE){
    int an,n=1,step=0;
    int *arr;
    while (1) {
        an=step+(n-1)*step;
        printf("%10d",an);//배열크기
        arr=makearr(an);

        timecheck(arr, an);
        free(arr);


        if (n==10 || step==0){
            n=1;
            if (step==0){step=10;
                n=0;}
            else if (step==MAX_SIZE/10)break;
            else step*=10;
        }
        n++;
    }
    return 0;
}

int binsearch(int list[], int searchnum, int right){

}





int main(void)
{   
    srand(time(NULL));
    int *arr;
    printf("1.1. 무작위 100,000개 정수 생성 및 정렬, 정렬 검사 수행\n");


    printf("1.1.1. 배열 A에 100,000개의 정수를 무작위로 생성하여 저장\n");
    arr=makearr(100000);
    for(int i=0;i<100;i++){
        printf("%d  ",arr[i]);
    }
    printf("... 완료\n");
    printf("1.1.2. 배열 A에 무작위로 저장된 정수를 정렬\n");
    if (arr!=NULL)sort(arr,100000);
    for(int i=0;i<100;i++){
        printf("%5d ",arr[i]%1000);
    }
    printf("... 완료\n");
    printf("1.1.3.배열 A에 정렬된 정수의 정렬 상태 확인\n");
    if (is_sorted(arr,100000)==1) printf("정렬완료!!!\n");
    free(arr);

    printf("1.2. 배열의 크기를 100부터 1,000,000까지 바꾸면서 sort 함수의 실행 시간 측정\n");

    printf("%10s %10s %10s\n","n","시간","정렬상태");
    D(100);
    printf("1.3. 100,000개의 정수를 무작위로 생성하여 정렬 후 이진검색 수행\n1.3.1. 배열에 100,000개의 정수를 무작위로 생성하여 저장\n");
    arr=makearr(100000);

    printf("완료.\n");
    /////////////////////////////////////////////
    printf("1.3.2. 배열에 무작위로 저장된 정수 정렬\n");
    if (arr!=NULL)sort(arr,100000);
    printf("완료\n");
    printf("1.3.3. 배열에 정렬된 정수의 정렬 상태 확인\n");
    if (is_sorted(arr,100000)==1) printf("정렬완료!!!\n");
    return 0;
}



// }
// for(int i=0;i<10;i++){
//     printf("%d : %d\n",i,arr[i]);
// }
