#include <stdio.h>
#include <stdlib.h>
int main(void){
	 
//int i;
//int a=2;
//for(i=0;i<5;i++){
//	printf("%d,",sum(a));
//}

//int a,b,c,d;
//a=10;
//b=a++;
//c=++a;
//d=10*a++;
//
//printf("a,b,c,d:%d,%d,%d,%d",a,b,c,d);

unsigned int a= 6;
int b = -20;
printf("%ud\n",a+b);
printf((a+b>6)?puts(">6"):puts("<=6"));
	return 1;
}
int sum(int a){
	auto int c=0;
	static int b =3;
	c+=1;
	b+=2;
	return(a+b+c);
}


