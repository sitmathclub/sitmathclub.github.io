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

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int a[], int n){
    int i,j;
    for(i=n;--i;){
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
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
    bubble_sort(a,N);
    print_array(a,N);
    return check(a,N);
}
