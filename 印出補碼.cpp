#include <stdio.h>
#include <stdlib.h>
int main(void){

while(1){
		int num,i;
	scanf("%d",&num);
	int data = 1<<31;
	
	for(i=1;i<=32;i++){
		printf("%c",(num&data ? '1':'0'));
		num <<= 1;
		if(i%4==0){
			printf(" ");
		}
	}
		printf("\n");
}

	system("pause");
	return 0;
}

