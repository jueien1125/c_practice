#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) (t=x, x=y, y=t) 
int main(void){
	int i,a[30];
	srand(time(NULL));
	for(i=0;i<30;i++){
		a[i]=rand()%100;
		printf("%2d ",a[i]);
	}
	printf("\n");
	sort(a,30);
	for(i=0;i<30;i++) printf("%2d ",a[i]);
	printf("\n");
	
	
	system("pause");
	return 0;
}

void sort(int a[],int n){
	int i,j,f,temp;
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				SWAP(a[j],a[j+1],temp);
				f=1;
			}
		}
		if(f==0)break;
	}
}
