#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node* prev;
	int value;
	struct node* next;
}node;

typedef struct queue{
	node* head;
	node* tail;
	int size;
}queue;

void push_front(int value, queue* q)
{
	node* x = (node*) malloc(sizeof(node));
	x->value = value;
	x->next = NULL;
	x->prev = NULL;
	if(q->head == NULL)
	{
		q->head = x;
		q->tail = x;
	}
	else
	{
		x->next = q->head;
		q->head->prev = x;
		q->head = x;
	}
	q->size++;
}

void push_back(int value, queue* q)
{
	node* x = (node*) malloc(sizeof(node));
	x->value = value;
	x->next = NULL;
	x->prev = NULL;
	if(q->head == NULL)
	{
		q->head = x;
		q->tail = x;
	}
	else
	{
		q->tail->next = x;
		x->prev = q->tail;
		q->tail = x;
	}
	q->size++;
}

int pop_front(queue* q)
{
	int t;
	if(q->head == NULL) return 0;
	if(q->head == q->tail)
	{
		t=q->head->value;
		free(q->head);
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		t=q->head->value;
		node* temp = q->head;
		q->head = q->head->next;
		q->head->prev = NULL;
		free(temp);
	}
	q->size--;
	return t;
}

int pop_back(queue* q)
{
	int t;
	if(q->tail == NULL) return 0;
	if(q->head == q->tail)
	{
		t = q->tail->value;
		free(q->tail);
		q->tail = NULL;
		q->head = NULL;
	}
	else
	{
		node* temp = q->tail;
		t = temp->value;
		q->tail = q->tail->prev;
		q->tail->next = NULL;
		free(temp);
	}
	q->size--;
	return t;
}

int front(queue* q)
{
	if(q->head == NULL) return 0;
	return q->head->value;
}

int back(queue* q)
{
	if(q->tail == NULL) return 0;
	return q->tail->value;
}

int main()
{
	queue* st2 = (queue*) malloc(sizeof(queue));
	st2->head = NULL;
	st2->tail = NULL;
	st2->size=0;
	queue* stm = (queue*) malloc(sizeof(queue));
	stm->head = NULL;
	stm->tail = NULL;
	stm->size=0;
	queue* st = (queue*) malloc(sizeof(queue));
	st->head = NULL;
	st->tail = NULL;
	st->size=0;
	queue* Qi = (queue*) malloc(sizeof(queue));
	Qi->head = NULL;
	Qi->tail = NULL;
	Qi->size=0;
	int n,k,i,j,x,m;
	scanf("%d %d",&n,&k);
	int c=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		while(Qi->tail!=NULL && Qi->tail->value<x)
		{
			pop_back(Qi);	
		}		
		push_back(x,Qi);
		if(c>=k && st->size<n-k+1)
		{
			if(Qi->size<k)
			{
				push_back(front(Qi),st);
			}
			else
			{
				m = pop_front(Qi);
				push_back(m,st);
			}
		}
		c++;
	}
	int h,u,p;
	int hari=0;
	while(1)
	{
		scanf("%d %d",&h,&u);
		int mx;
		int range = h-hari;
		hari=h;
		if(stm->head!=NULL) mx=front(stm);
		else mx=0;
		if(h==-1 && u==-1) break;
		while(range--)
		{
			m = pop_front(st);
			push_back(m,st2);
			int tempm=m;
			if(tempm>=mx)
			{
				push_back(tempm,stm);
				mx=tempm;
			}
		}
		while(u--)
		{
			scanf("%d",&p);
			if(p==1)
			{
				if(st2->tail==NULL)
				{
					printf("Stok abis\n");
				}	
				else
				{
					m = pop_back(st2);
					if(m == back(stm)) pop_back(stm);
					printf("Nyam\n");
				}
			}
			else if(p==2)
			{
				if(st2->head==NULL)
				{
					printf("Stok abis\n");
				}
				else
				{
					printf("%d\n",back(stm));
				}
			}
		}
	}
	return 0;
}	
