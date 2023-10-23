#include <stdio.h>
#include <memory.h>
 
#define MAX 1000
 
 
void insert_array(int * a, int * size, int value)
{
    int i = -1;
    while(++i < *size && a[i] < value);
    memmove(a + i + 1, a + i, ((*size)++ - i) * sizeof(int));
    a[i] = value;
}
int main()
{
    int a[MAX];
    int i = 0;
    int x = 8;
    int size = 10;
    for(i = 0; i < size; i++)
    {
        a[i] = i + 1;
        printf("%4d", a[i]);
    }
    printf("\n");
    insert_array(a, &size, x);
    for(i = 0; i < size; i++)
        printf("%4d", a[i]);
    printf("\n");
    return 0;
}
