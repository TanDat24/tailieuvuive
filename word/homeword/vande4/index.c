#include <stdio.h>
#include <math.h>
int main() {
int h,m,s;
printf ("\n nhap h,m,s hien tai: ");
scanf ("%d%d%d",&h, &m, &s);
	if (s>0&&s<59) {
		s=s+1;
		printf("\n h,m,s la: %d:%d:%d", h, m, s);
	} else {
		if(m>0&&m<59) {
			s=0;
			m=m+1;
			printf("\n h,m,s la: %d:%d:%d", h, m, s);
		} else {
			if(h>0&&h<59) {
				s=0;
				m=0;
				h=h+1;
				printf("\n h,m,s la: %d:%d:%d", h, m, s);
			} else {
				printf("0:0:0");
			}
		}
	}
	return 0;
}
