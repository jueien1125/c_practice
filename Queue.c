/*Queue 用  Linklist實作*/
#include <stdio.h>
#include <stdlib.h>

struct queue{
	int num;	//代表數據 
	int high;	//優先級 
	struct queue *pNext;	//儲存下一個節點的地址 
};
typedef struct queue Queue;//簡化隊列 

Queue *init(Queue *queueA);//初始化 
Queue *EnQueue(Queue *queueA, int num, int high);//入隊 
Queue *DeQueue(Queue *queueA, Queue *pout);//出隊 
Queue *freeall(Queue *queueA);// 清空 
void sort(Queue *queueA);//優先級排隊 
void printfall(Queue *queueA);//印出所有數據，遞迴 

void main(void){

	Queue *phead = NULL;//創建頭節點 
	phead = init(phead);//初始化 
	phead =  EnQueue(phead, 1, 1);//入隊
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 2, 1);//入隊
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 3, 2);//入隊
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 4, 1);//入隊
	printfall(phead);
		printf("\n");
	phead =  EnQueue(phead, 5, 4);//入隊
	printfall(phead);
		printf("\n");


	phead = freeall(phead);
	printfall(phead);
	
	
	while(phead != NULL){//不為空就繼續 
		Queue *ptemp = (Queue *)malloc(sizeof(Queue));
		phead = DeQueue(phead, ptemp);
		printf("\n拉屎一次以後\n");
		printfall(phead);
		printf("拉出來的是%d,%d\n", ptemp->num ,ptemp->high);
	}
	
	system("pause");
}
Queue *init(Queue *queueA)//初始化 
{
	return NULL;
}
Queue *EnQueue(Queue *queueA, int num, int high)//入隊
{
	Queue *pnewnode = (Queue *)malloc(sizeof(Queue)); //分配記憶體
	pnewnode->num = num;
	pnewnode->high = high;
	pnewnode->pNext = NULL;
	
	if(queueA == NULL)//串列為空 
	{
		queueA = pnewnode;
		sort(queueA);//排隊 
		return queueA;// 返回值 進行 賦值 
	}
	else{
		Queue *p = queueA;//頭節點
		while(p->pNext != NULL){
		 	p = p->pNext ;
		}
		//確定要插入的位置
		p->pNext = pnewnode;//插入
		sort(queueA);//排隊 
		return queueA;	 
	} 
}
Queue *DeQueue(Queue *queueA, Queue *pout)//出隊 
{
	if(queueA == NULL){
		return NULL;
	}
	else{
		pout->num = queueA->num;
		pout->high = queueA->high;
		Queue *ptemp = queueA;//紀錄要刪除的地址 
		queueA = queueA->pNext;
		free(ptemp);//釋放 
		
		return queueA;
		
	}
}
Queue *freeall(Queue *queueA)// 清空 
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
void sort(Queue *queueA)//優先級排隊 
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
				p2->high = temp.high;//交換節點的數據 
			}
		}
	}
}
void printfall(Queue *queueA)//印出所有數據，遞迴 
{
	if(queueA == NULL){
		return;
	}
	else{
		printf("%3d, %d, %p, %p\n", queueA->num, queueA->high, queueA, queueA->pNext);
		printfall(queueA->pNext);//進入下一個節點 
	}
} 
