#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) (t=x, x=y, y=t) 
int main(void){
	
	
int i,a[100],array[30];
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
		array[i] = a[i];
	}
	sort(array,30);
	
	for(i=0;i<30;i++) printf("%d ",array[i]);
	printf("\n");
	system("pause");
	return 0;
}

void sort(int a[],int n){
	int i,j,f,temp;
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				SWAP(a[j],a[j+1],temp);
				f=1;
			}
		}
		if(f==0)break;
	}
}
