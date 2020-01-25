#include <stdio.h>
#include <math.h>
#define Point struct Point
Point{
    double X;
    double Y;
};

unsigned int is_equal(Point A, Point B){
    if(A.X == B.X && B.Y == A.Y) return 1;
    return 0;
}

Point getDPoint(Point* A, Point* B, Point* C){
    Point S = {(A->X + C->X)/2.0 , (A->Y + C->Y)/2.0 };
    Point D = { (A->X + C->X) - B->X , (A->Y + C->Y) - B->Y};
    return D;
}

int main(){
    Point input[4];
    Point A,B,C;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&input[0].X,&input[0].Y,&input[1].X,&input[1].Y,&input[2].X,&input[2].Y,&input[3].X,&input[3].Y) != EOF){
        int i, e;
        for(i = 0; i < 4; i++){
            for(e = 0; e < 4; e++){
                if(e==i) continue;
                if(is_equal(input[e],input[i])) break;
            }
            if(is_equal(input[e],input[i])) break;
        }
        if(i > e){
            int p = e;
            e = i;
            i = p;
        }
        if((i == 0 && e == 3)){
            A = input[1];
            B = input[0];
            C = input[2];
        }
        else if((i == 0 && e == 1)){
            A = input[3];
            B = input[0];
            C = input[2];
        }
        else if((i == 2 && e == 3)){
            A = input[1];
            B = input[2];
            C = input[0];
        }
        else if((i == 0 && e == 2)){
            A = input[1];
            B = input[0];
            C = input[3];
        }
        else if((i == 1 && e == 3)){
            A = input[0];
            B = input[1];
            C = input[2];
        }
        else if((i == 1 && e == 2)){
            A = input[0];
            B = input[1];
            C = input[3];
        }
        if(A.X > C.X){
            Point x = A;
            A = C;
            C = x;
        }

        Point D = getDPoint(&A,&B,&C);
        printf("%.3f %.3f\n",D.X,D.Y);
    }
    return 0;
}
