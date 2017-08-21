#include <stdio.h>
#include <stdlib.h>
int main(void){
	
////while(1){
//	 	int i,n,pow=2;
////  		scanf("%d",&n);
//  		for(i=0 ; i<5 ;i++){
//  			
//			  printf("%d\n",pow); 
//			  if(n<pow){
//			  	
//			  }
//  			
//		  }
//
////}
	
	
	while(1){
		int n;
		scanf("%d",&n);
		printf("%ud\n",power(2,n));
	}
	
	system("pause");
	return 0;
}
int power(int num,int pow){
	int i;
	if(pow==0)return 1;
	else{
		for(i=1;i<pow;i++){
		num=num*2;
		}
	return num;
	}
}
