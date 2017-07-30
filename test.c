#include <stdio.h>
#include <stdlib.h>
int main(void){
	
	char *str = (char *) malloc(100);
	strcpy(str,"hello");
	free(str);
	if(str!=NULL){
		strcpy(str,"world");
		printf(str);
	}

	system("pause");
	return 0;
}


