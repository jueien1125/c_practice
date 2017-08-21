/*Queue ��  Linklist��@*/
#include <stdio.h>
#include <stdlib.h>

struct queue{
	int num;	//�N��ƾ� 
	int high;	//�u���� 
	struct queue *pNext;	//�x�s�U�@�Ӹ`�I���a�} 
};
typedef struct queue Queue;//²�ƶ��C 

Queue *init(Queue *queueA);//��l�� 
Queue *EnQueue(Queue *queueA, int num, int high);//�J�� 
Queue *DeQueue(Queue *queueA, Queue *pout);//�X�� 
Queue *freeall(Queue *queueA);// �M�� 
void sort(Queue *queueA);//�u���űƶ� 
void printfall(Queue *queueA);//�L�X�Ҧ��ƾڡA���j 

void main(void){

	Queue *phead = NULL;//�Ы��Y�`�I 
	phead = init(phead);//��l�� 
	phead =  EnQueue(phead, 1, 1);//�J��
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 2, 1);//�J��
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 3, 2);//�J��
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 4, 1);//�J��
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 5, 4);//�J��
	printfall(phead);
		printf("\n");


	phead = freeall(phead);
	printfall(phead);
	
	
	while(phead != NULL){//�����ŴN�~�� 
		Queue *ptemp = (Queue *)malloc(sizeof(Queue));
		phead = DeQueue(phead, ptemp);
		printf("\n�ԫˤ@���H��\n");
		printfall(phead);
		printf("�ԥX�Ӫ��O%d,%d\n", ptemp->num ,ptemp->high);
	}
	
	system("pause");
}
Queue *init(Queue *queueA)//��l�� 
{
	return NULL;
}
Queue *EnQueue(Queue *queueA, int num, int high)//�J��
{
	Queue *pnewnode = (Queue *)malloc(sizeof(Queue)); //���t�O����
	pnewnode->num = num;
	pnewnode->high = high;
	pnewnode->pNext = NULL;
	
	if(queueA == NULL)//��C���� 
	{
		queueA = pnewnode;
		sort(queueA);//�ƶ� 
		return queueA;// ��^�� �i�� ��� 
	}
	else{
		Queue *p = queueA;//�Y�`�I
		while(p->pNext != NULL){
		 	p = p->pNext ;
		}
		//�T�w�n���J����m
		p->pNext = pnewnode;//���J
		sort(queueA);//�ƶ� 
		return queueA;	 
	} 
}
Queue *DeQueue(Queue *queueA, Queue *pout)//�X�� 
{
	if(queueA == NULL){
		return NULL;
	}
	else{
		pout->num = queueA->num;
		pout->high = queueA->high;
		Queue *ptemp = queueA;//�����n�R�����a�} 
		queueA = queueA->pNext;
		free(ptemp);//���� 
		
		return queueA;
		
	}
}
Queue *freeall(Queue *queueA)// �M�� 
{
	if(queueA == NULL){
		return NULL;
	}
	else{
		Queue *p1,*p2;
		p1=p2=NULL;
		p1 = queueA;
		while(p1->pNext != NULL){
			p2 = p1->pNext;
			p1->pNext = p2->pNext;
			free(p2); 
		}
		free(queueA);
		return NULL;
	}
}
void sort(Queue *queueA)//�u���űƶ� 
{
	if(queueA == NULL || queueA->pNext == NULL){
		return;
	}
	Queue *p1,*p2;
	p1=p2=NULL;
	for(p1 = queueA; p1!=NULL; p1=p1->pNext){
		for(p2 = queueA; p2!=NULL; p2=p2->pNext){
			if(p1->high > p2->high){
				Queue temp;
				temp.num = p1->num;
				p1->num = p2->num;
				p2->num = temp.num;
				
				temp.high = p1->high;
				p1->high = p2->high;
				p2->high = temp.high;//�洫�`�I���ƾ� 
			}
		}
	}
}
void printfall(Queue *queueA)//�L�X�Ҧ��ƾڡA���j 
{
	if(queueA == NULL){
		return;
	}
	else{
		printf("%3d, %d, %p, %p\n", queueA->num, queueA->high, queueA, queueA->pNext);
		printfall(queueA->pNext);//�i�J�U�@�Ӹ`�I 
	}
} 
