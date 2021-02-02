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

void quick_sort(int a[], int left, int right){
    int i,j,pivot;
    if(right>left){
        //ピボットの位置ををleft以上right以下の乱数にする
        pivot=a[rand()%(right-left)+left];
        for(i=left-1,j=right+1;;){
            do{i++;}while(pivot>a[i]);
            do{j--;}while(pivot<a[j]);
            if(i>=j)break;
            swap(a+i,a+j);
        }
        quick_sort(a,left,i-1);
        quick_sort(a,j+1,right);
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
    quick_sort(a,0,N-1);
    print_array(a,N);
    return check(a,N);
}
