#include "stdio.h"
#include "string.h"
struct WORD{
    char Name[256];
    char Meaning[512];
};

void bubble_sort(WORD a[], int n)
{
    for(int i = n-1; i>0; i--){
        for(int j = 0; j<i;j++){
            if(strcmp(a[j].Name,a[j+1].Name)>0){
                WORD tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;

            }
        }
    }
}

int BinSearch(WORD a[], int n, char k[]) {
    bubble_sort(a,n);
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cmp = strcmp(a[mid].Name, k);
        if (cmp < 0) {
            l = mid + 1;
        } else if (cmp > 0) {
            r = mid - 1;
        } else {
            return mid; 
        }
    }
    return -1;
}

void Deleted(WORD a[],int &n, char k[]){
    int pos = BinSearch(a,n,k);
    if(pos != -1){
       for (int i = pos; i < n-1; i++)
       {
        a[i]=a[i+1];
       }
       n--;
    printf("Xoa thanh cong\n");
    } else {
        printf("Khong tim thay!\n");
    }
}

void addWords(WORD a[], int &n){
    n++;
    fflush(stdin);
    printf("Nhap tu can them: ");
    gets(a[n-1].Name);
    printf("Nhap nghi cua tu them: ");
    gets(a[n-1].Meaning);
}

void fixWords(WORD a[],int n, char p[]){
    int pos = BinSearch(a,n,p);
    if(pos != -1){
        fflush(stdin);
        printf("Nhap tu moi can sua: ");
        gets(a[pos].Name);
        printf("Nhap nghia cua tu moi: ");
        gets(a[pos].Meaning);
    } else {
        printf("Khong tim thay tu can sua!\n");
    }
}

int main(){
    FILE* f1 = fopen("INPUT.txt", "r");
    if (!f1){
        printf("ERROR");
        return 0;
    }
    WORD listWord[256];
    int n = 0;
    while(!feof(f1)){
        fgets(listWord[n].Name,256,f1);
        listWord[n].Name[strlen(listWord[n].Name) -1] = '\0';
        fgets(listWord[n].Meaning,256,f1);
        listWord[n].Meaning[strlen(listWord[n].Meaning)] = '\0';
        n++;
    }
    int k;
    do {
        printf("\n===----menu----===\n");
        printf("1.Doc file\n");
        printf("2.Tim kiem\n");
        printf("3.Sua tu\n");
        printf("4.Xoa tu\n");
        printf("5.them tu\n");
        printf("6.Sap xep\n");
        printf("7.Thoat\n");
        
        printf("Nhap so can thuc hien: \n");
        scanf("%d",&k);
        switch (k)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("%s : %s", listWord[i].Name, listWord[i].Meaning);
            }
            
            break;
        case 2:{
            char c[20];
            printf("Nhap tu can tim: ");
            fflush(stdin);
            gets(c);
            int pos = BinSearch(listWord,n,c);
            if(pos != -1) printf("Tu tim duoc la: %s:%s\n", listWord[pos].Name,listWord[pos].Meaning);
            else printf("Khong tim thay!\n");
            break;}
        case 3:{
            char p[20];
            printf("Nhap tu can sua: \n");
            scanf("%s", &p);
            fixWords(listWord,n,p);
            break;}
        case 4:{
            char d[20];
            printf("Nhap tu can xoa: ");
            scanf("%s",&d);
            Deleted(listWord,n,d);
            break;}
        case 5:{
            addWords(listWord,n);
            break;}
        case 6:{
            bubble_sort(listWord,n);
            for (int i = 0; i < n; i++)
            {
                printf("%s:%s\n",listWord[i].Name, listWord[i].Meaning);
            }
            break;}
        case 7:{
            break;
        }
        }
    }while (k != 7);
    FILE* f2 = fopen("OUTPUT.txt", "w");
    if (!f2){
        fprintf(f2,"ERROR");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(f2,"%s : %s\n",listWord[i].Name,listWord[i].Meaning);
    }
    fclose(f2);
    return 0;
}
