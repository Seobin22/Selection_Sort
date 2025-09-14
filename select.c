#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 1000000

void change(int *first, int *after){
    int temp;
    temp = *first;
    *first = *after;
    *after = temp;
}

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
void timecheck(int A[],int an){
    /*for(step;step<10001;)*/
    clock_t start;
    double time_used;
    start = clock();
    sort(A,an); 
    time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("%10f",time_used);
    if (is_sorted(A,an)==1) printf("%10s\n","정렬됨");
    else printf("%10s\n","정렬안됨");
}
int D(void){
    int an,n=1,step=0;
    int *arr;
    while (1) {
        an=step+(n-1)*step;
        printf("%10d",an);//배열크기
/////////////////////////////////(arr 생성)
        arr=(int *)malloc(sizeof(int)*an);
        if (arr==NULL) {
            printf("no memory\n");
            return -1;
        }
        if(an!=0){
        for(int i=0;i<an;i++){
        arr[i]=rand()%100000+1;
        }}
////////////////////////////////////
        timecheck(arr, an);
        free(arr);


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
    printf("%10s %10s %10s\n","n","시간","정렬상태");
    srand(time(NULL));
    D();
    return 0;
}



// }
// for(int i=0;i<10;i++){
//     printf("%d : %d\n",i,arr[i]);
// }
