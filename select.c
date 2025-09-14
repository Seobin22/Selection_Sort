#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

void change(int *first, int *after){
    int temp;
    temp = *first;
    *first = *after;
    *after = temp;
}

void sort(int *arr){
    int mi;
    //0부터 끝-1 까지 돌아가면 현재 인덱스 ,, 현재 인덱스 +1 부터 끝까지 비교 . 
    for(int top=0;top<size-1;top++){
        mi=top;
        for (int t=top+1;t<size;t++){
            if(arr[mi] > arr[t]) mi=t;
            }    
            if (top!=mi) change(&arr[top],&arr[mi]);
        }                
}
int is_sorted(int A[],int n){
    for (int i=0; i<n-1;i++){
        if (A[i]>A[i+1]){
            
            printf("0");
            return 0;
        }
    }
    printf("1_____________-\n");

    return 1;
}
void timecheck(int A[]){
    /*for(step;step<10001;)*/
    clock_t start;
    double time_used;
    start = clock();
    sort(A);
;   time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("time : %f\n",time_used);
}
int D(void){
    int an,n=1,step=0;
    int *list;
    while (1) {
        an=step+(n-1)*step;
        printf("%d\n",an);

        list=(int *)malloc(sizeof(int)*an);
        if (list==NULL) {
            printf("no memory\n");
            return -1;
        }

        // for(int i=0;i<size;i++){
        // arr[i]=rand()%100000+1;
        // }


        if (n==10 || step==0){
            n=1;
            if (step==0){step=10;
                n=0;}
            else if (step==1000)break;
            else step*=10;
        }
        n++;
    }
}

int main(void)
{   
    printf("test ddddddddd  try\n");
    srand(time(NULL));
    int arr[size]={0};
    for(int i=0;i<size;i++){
        arr[i]=rand()%100000+1;
    }

    sort(arr);
    is_sorted(arr,size);
    printf("+________________");
    D();
    return 0;
}



// }
// for(int i=0;i<10;i++){
//     printf("%d : %d\n",i,arr[i]);
// }
