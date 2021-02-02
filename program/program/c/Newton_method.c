/*数理科学研究会*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSIRON 1E-6

double f(double x){
    return x*(x-1);
}

double df(double x){
    return 2*x-1;
}

double Newton_method(double x){
    int i=0;
    double nx=x;
    do{
        x=nx;
        nx=x-f(x)/df(x);
        i++;
        if(i>1023){
            fprintf(stderr,"収束しないようです.初期値を変えるなどして下さい.\n");
            return NAN;//Not a Number(正常な数でない値)
        }
        if(fpclassify(nx)!=FP_NORMAL&&fpclassify(nx)!=FP_ZERO){
            printf("解は%fです.\n",nx);
            fprintf(stderr,"収束しないようです.初期値を変えるなどして下さい2.\n");
            return NAN;//Not a Number(正常な数でない値)
        }
    }while(fabs(nx-x)>EPSIRON);
    return nx;
}

int main(int argc,char *argv[]){
    double first,ans;
    if(argc==2){
        first=atof(argv[1]);
    }else{
        printf("初期値を入力して下さい.\n");
        scanf("%lf",&first);
    }
    ans=Newton_method(first);
    if(isnan(ans)==0)printf("解は%.15fです.\n",ans);
    return 0;
}
