#include <stdio.h>
#include <math.h>
int main() {
    int a, hang_chuc, hang_don_vi;
    printf("\nNhap so tu 10 den 99: ");
    scanf("%d", &a);
    if (a>9||a<100)
    {
        switch (a/10)
        {
        case 1:
        printf("\nMuoi");
            break;
        case 2:
        printf("\nhai muoi");
            break;
            case 3:
        printf("\nba muoi");
            break;
            case 4:
        printf("\nbon muoi");
            break;
            case 5:
        printf("\nnam muoi");
            break;
            case 6:
        printf("\nsau muoi");
            break;
            case 7:
        printf("\nbay muoi");
            break;
            case 8:
        printf("\ntam muoi");
            break;
            case 9:
        printf("\nchin muoi");
            break;
        }
        switch (a%10)
        {
        case 1:
        printf("\nMuoi");
            break;
        case 2:
        printf("\nhai");
            break;
            case 3:
        printf("\nba");
            break;
            case 4:
        printf("\nbon");
            break;
            case 5:
        printf("\nnam");
            break;
            case 6:
        printf("\nsau");
            break;
            case 7:
        printf("\nbay");
            break;
            case 8:
        printf("\ntam");
            break;
            case 9:
        printf("\nchin");
            break;
        }
    }
    else printf("\nKhong phai so co 2 chu so!!!");
    
}