#include<stdio.h>
#include<stdlib.h>
 

struct Point2D
{
   double X, Y;
};

struct Point2D *InputDynamicPoint2D(){
    struct Point2D *tmp = (struct Point2D*)malloc(sizeof(struct Point2D));
    //struct Point2D *tmp;
    scanf("%lf%lf", &tmp->X,&tmp->Y);
    return tmp;
}
void DisplayPoint2D (struct Point2D *p){
    printf("(%.2lf, %.2lf)",p->X,p->Y);
}

int main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt","w", stdout);
struct Point2D* p;
p = InputDynamicPoint2D();
DisplayPoint2D(p); 
}