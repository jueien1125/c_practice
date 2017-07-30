#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *top=NULL;
void push(int);
int pop();
void printStack();

int main(void){
	int choice=0,n;
	while(choice != -1){
		printf("1) push\n2) pop\n3) print stack\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("what do you want to push?");
					scanf("%d",&n);
					push(n);
					break;
			case 2:printf("%d was popped from stack\n",pop());
					break;
			case 3:printStack();
					break; 
		}
	}
	while(top) pop();

	system("pause");
	return 0;
}
void push(int data){
	NODE *p;
	p = (NODE*) malloc(sizeof(NODE));
	if(p==NULL){
		printf ("°O¾ÐÅé¤£¨¬");
		exit(1); 
	} 
	p->data = data;
	p->next = top;
	top = p; 
}

int pop(){
	if(top==NULL){
		NODE tmp;
		if(top==NULL){
			printf("stack is empty");
			exit(1);
		}
		tmp = *top;
		free(top);
		top = tmp.next;
		return tmp.data;
	}
}

void printStack(){
	NODE *tmp=top;
	while(tmp){
		printf("%d , tmp->data");
		tmp = tmp->next;
	}
	printf("\n");
}

