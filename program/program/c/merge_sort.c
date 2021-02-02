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

void merge_sort(int a[], int temp[], int left, int right){
    int i,r,l,m=(left+right)/2;
    if(right-left>0){
        merge_sort(a,temp,left,m);//左半分のソート
        merge_sort(a,temp,m+1,right);//右半分のソート

        //a[0]～a[m]とa[m+1]～a[right]までをマージする(合わせる)
        for(i=left,r=left,l=m+1;i<=right;i++){
            //小さい方をtemp[i]に入れる
            if((a[r]<=a[l]&&r<=m)||l>right){
                temp[i]=a[r];
                r++;
            }else{
                temp[i]=a[l];
                l++;
            }
        }
        for(i=left;i<=right;i++){
            a[i]=temp[i];
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
    int a[N],b[N];
    srand((unsigned)time(NULL));
    set_rand(a,N);
    print_array(a,N);
    merge_sort(a,b,0,N-1);
    print_array(a,N);
    return check(a,N);
}
