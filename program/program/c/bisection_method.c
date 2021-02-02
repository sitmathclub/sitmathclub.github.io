/*�����Ȋw������*/
#include <stdio.h>
#include <math.h>
#define EPSIRON 1E-6
double f(double x){
    return x*x-2;
}

double bisection_method(double left,double right){
    double middle,fleft,fright,fmiddle;
    fleft=f(left);
    fright=f(right);
    if(fleft*fright>0){
      fprintf(stderr,"��Ԃɉ����܂�ł��Ȃ��\��������܂�.\n");
      return NAN;//Not a Number(����Ȑ��łȂ��l)
    }
    do{
        middle=(left+right)/2;
        fmiddle=f(middle);
        if(fleft*fmiddle<0){
            right=middle;
            fright=fmiddle;
        }else{
            left=middle;
            fleft=fmiddle;
        }
    }while(right-left>EPSIRON);
    middle=(left+right)/2;
    return middle;
}

int main(int argc,char *argv[]){
    double left,right,ans;
    if(argc==3){
        left=atof(argv[1]);
        right=atof(argv[2]);
    }else{
        printf("����T����Ԃ�a,b�̌`�œ��͂��ĉ�����.\n");
        scanf("%lf,%lf",&left,&right);
    }
    ans=bisection_method(left,right);
    if(isnan(ans)==0)printf("����%f�ł�.\n",ans);
    return 0;
}
