#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){

	char s[]={"abcdefghijklmnopqrstuvwxyz"};
	int k=3;
	int len = strlen(s);
    int i,j;
    char temp;
    for(i=0;i<len;i+=2*k){

        for(j=i;j<(k/2)+i;j++){
            int index = i+(i+k)-1;
            temp = s[j];
            s[j] = s[index-j];
            s[index-j] = temp;
        }
    }
	printf("%s\n",s);
	system("pause");
	return 0;
}



