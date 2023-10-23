#include<stdio.h>
#include<math.h>
float DT(float xA, float yA, float xB, float yB, float xC, float yC);
float Stg(float a, float b, float c);
int main(int argc, char const *argv[])
{
    float xA,xB,xC,yA,yB,yC;
    printf("\nNhap toa do diem A: ");
    printf("\nxA = "); scanf("%d", &xA);
    printf("\nyA = "); scanf("%d", &yA);

    printf("\nNhap toa do diem B ");
    printf("\nxB = "); scanf("%d", &xB);
    printf("\nyB = "); scanf("%d", &yB);

    printf("\nNhap toa do diem C: ");
    printf("\nxC = "); scanf("%d", &xC);
    printf("\nyC = "); scanf("%d", &yC);

        float a,b,c;
        a = DT(xA,yA,xB,yB);
        b = DT(xB,yB,xC,yC);
        c = DT(xC,yC,xA,yA);
        float S = Stg(a,b,c);
        printf("\nS tam giac: %.2f", S);
    return 0;
}

float DT(float xA, float yA, float xB, float yB, float xC, float yC) {
    float d;
    d = sqrt(pow((xA-xB),2) + pow((yA - yB),2));
    return (d);
}

float Stg(float a, float b, float c) {
    float p, s;
    p = (a + b + c)/2;
    s = sqrt(p*(p -a)*(p - b)*(p -c));
    return(s);
}