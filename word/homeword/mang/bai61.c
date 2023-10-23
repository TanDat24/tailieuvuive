#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int a[999], s = 0;
    for (int i = 0; i <= 999; i++)
    {
        a[i]=rand();
        s+=a[i];
    }
    printf("%.2f\n", s/1000.0);
    for (int i = 0; i <= 999; i++)
    {
        printf("%d", a[i]);
        if (i%9==0 && i!=0)
        {
            system("pause");
            printf("\n");
        }
        
    }
    
    return 0;
}
