
#include<stdio.h>
#define Equation struct Equation

Equation {
    int a,b,c;
};

int main(){
    Equation a,b;
    while(1){
        scanf("%d %d %d %d %d %d",&a.a,&a.b,&a.c,&b.a,&b.b,&b.c);
        if(a.a==0&&a.b==0&&a.c==0&&b.a==0&b.b==0&&b.c==0)break;
        double det = a.a * b.b - a.b*b.a;
        if(det == 0) printf("No fixed point exists.\n");
        else{
            double wx,wy,x,y;
            wx = a.c*b.b - a.b*b.c;
            wy = a.a*b.c - a.c * b.a;
            x=wx/det;
            y=wy/det;
            printf("The fixed point is at %.2lf %.2lf\n",x,y);
        }
    }
    return 0;

}
