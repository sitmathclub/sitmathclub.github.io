/*�����Ȋw������*/
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
            fprintf(stderr,"�������Ȃ��悤�ł�.�����l��ς���Ȃǂ��ĉ�����.\n");
            return NAN;//Not a Number(����Ȑ��łȂ��l)
        }
        if(fpclassify(nx)!=FP_NORMAL&&fpclassify(nx)!=FP_ZERO){
            printf("����%f�ł�.\n",nx);
            fprintf(stderr,"�������Ȃ��悤�ł�.�����l��ς���Ȃǂ��ĉ�����2.\n");
            return NAN;//Not a Number(����Ȑ��łȂ��l)
        }
    }while(fabs(nx-x)>EPSIRON);
    return nx;
}

int main(int argc,char *argv[]){
    double first,ans;
    if(argc==2){
        first=atof(argv[1]);
    }else{
        printf("�����l����͂��ĉ�����.\n");
        scanf("%lf",&first);
    }
    ans=Newton_method(first);
    if(isnan(ans)==0)printf("����%.15f�ł�.\n",ans);
    return 0;
}
