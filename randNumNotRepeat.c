#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) (t=x, x=y, y=t) 
#include "bubble_sort.c"
int main(void){
	
	
	
	int i,a[100],sort[30];
    for(i=0 ; i<100 ; i++){
    	a[i]=i+1;
	}
	srand(time(NULL));
	int k,j,temp;
	for(i=0;i<100;i++){
		k=rand()%100;
		j=rand()%100;
		SWAP(a[k],a[j],temp);
	}
	
	for(i=0;i<30;i++){
		sort[i] = a[i];
	}
	sort(sort,30);
	
	
	
	for(i=0;i<30;i++) printf("%2d ",a[i]);

	system("pause");
	return 0;
}

