#include <stdio.h>
#include <stdlib.h>
void hanio(int,char,char,char);

int main(void){
	while(1){
		int n;
		scanf("%d",&n);
		hanoi(n,'A','B','C');
	}
	system("pause");
	return 0;
}

void hanoi(int n, char A, char B, char C){
	if(n==1){
		printf("move sheet from %c to %c\n",A,C);
	}
	else{
		hanoi(n-1,A,C,B);
		hanoi(1,A,B,C);
		hanoi(n-1,B,A,C);
	}
}

