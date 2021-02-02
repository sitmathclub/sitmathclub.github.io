/*数理科学研究会*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

void set_rand(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        a[i]=rand();
    }
}

void print_array(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d,",a[i]);
    }
    putchar('\n');
}

int findmax(int a[], int start, int end){
    int i,max;
    max=start;
    for(i=start+1;i<=end;i++){
        if(a[max]<a[i])max=i;
    }
    return max;
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int a[], int n){
    int i,max;
    for(i=n;--i;){
        max=findmax(a,0,i);
        swap(&a[i],&a[max]);
    }
}

int  check(int a[], int n){
    int i;
    for(i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            //ソートに失敗した場合エラー出力にその旨を表示
            fprintf(stderr,"SORT FAILURE\n");
            return -1;
        }
    }
    return 0;
}

int main(void){
    int a[N];
    srand((unsigned)time(NULL));
    set_rand(a,N);
    print_array(a,N);
    selection_sort(a,N);
    print_array(a,N);
    return check(a,N);
}
