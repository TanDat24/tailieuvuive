#include<stdio.h>
#include<math.h>
float getRelPos ( float x, float y, float r);
int main(int argc, char const *argv[])
{
    float x, y, r;
    printf("\nNhap vao toa do x:");
    scanf("%f", &x);
    printf("\nNhap vao toa do y:");
    scanf("%f", &y);
    printf("\nNhap vao ban kinh r:");
    scanf("%f", &r);

    getRelPos(x,y,r);
    
    return 0;
}

float getRelPos ( float x, float y, float r) {
    float d2 = x*x + y*y;
    float r2 = r*r;
    if (d2<r2)
    {
        printf("\nthe point is in the circle");
        return 1;
    } else if ( d2 == r2)
    {
        printf("\nthe point is on the circle");
        return 0;
    } else {
        printf("\nthe point is out of the circle");
        return -1;
    }
}
