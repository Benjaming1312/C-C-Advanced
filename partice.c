#include<stdio.h>
#include<stdlib.h>

#define N 5
struct student {
	int math;
	int english;
	int computer;
};
typedef struct student stu;
int main () {
	stu s[N];
	stu sum = {0, 0, 0};
	int i;
	int op;
	int n=0;
	
	while(1) {
		puts("(1) �s�W");
		puts("(2) �d��");
		puts("(3) �ק�");
		puts("(4) �C�X�Ҧ����");
		puts("(5) �p��U�쥭��");
		puts("(6) �p��Y�H����");
		puts("(0) ���}");
		
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				scanf("%d", &s[n].math);
				scanf("%d", &s[n].english);
				scanf("%d", &s[n].computer);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				for (i =0; i<n; i++) {
					printf("%d\n", s[n].math);
					printf("%d\n", s[n].english);
					printf("%d\n", s[n].computer);
				}
				break;
			case 5:
				break;
			case 6:
				break;
			case 0:
				return;
				break;
		}
		system("pause");
		system("cls");
	}
	
//	for (i=0; i<N; i++) {
//		scanf("%d", &s[i].math);
//		scanf("%d", &s[i].english);
//		scanf("%d", &s[i].computer);
//	}
//	
//	for(i=0; i< N; i++) {
//		sum.math += s[i].math;
//		sum.english += s[i].english;
//		sum.computer += s[i].computer;
//	}
//	
//	printf("%.2f\n", (double)sum.math/N);
//	printf("%.2f\n", (double)sum.english/N);
//	printf("%.2f\n", (double)sum.computer/N);
	
	return 0;
}

