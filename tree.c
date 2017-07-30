#include <stdio.h>
#include <stdlib.h>
#define lchild(i) 2*i
#define rchild(i) 2*i+1
typedef struct node{
	char data;
	struct node* lchild;
	struct node* rchild;
}NODE;

void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);
 
int main(void){
	
	int i;
	NODE tree[14];
	for(i=1; i<14; i++){
		tree[i].data = 'a'+i-1;
		if(lchild(i)<14) tree[i].lchild = &tree[lchild(i)];
		else tree[i].lchild = NULL;
		if(rchild(i)<14) tree[i].rchild = &tree[rchild(i)];
		else tree[i].rchild = NULL;
	}
	preorder(tree+1);
	printf("\n");
	inorder(tree+1);
	printf("\n");
	postorder(tree+1);
	printf("\n");
	
	system("pause");
	return 0;
}

void preorder(NODE* p){
	if(p){
		printf("%c",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(NODE* p){
	if(p){
		inorder(p->lchild);
		printf("%c",p->data);
		inorder(p->rchild);
		}
}

void postorder(NODE* p){
	if(p){
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%c",p->data);
	} 
} 

