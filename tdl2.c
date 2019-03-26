#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[105][105],n,ans;
typedef struct koor{
	int x;
	int y;
}koor;

typedef struct node{
	koor value;
	struct node* next;
}node;

typedef struct stack{
	struct node* top;
	int size;
}stack;

void push(koor k, stack* st)
{
	node* box = (node*) malloc(sizeof(node));
	box->next = NULL;
	box->value = k;
	if(st->size==0) st->top = box;
	else
	{
		box->next = st->top;
		st->top = box;
	}
	st->size++;
}

void pop(stack* st)
{
	if(st->size==0) return;
	node* temp = st->top;
	st->top = st->top->next;
	free(temp);
	st->size--;
}

koor top(stack* st)
{
	koor kosong; kosong.x = -1; kosong.y = -1;
	if(st->size==0) return kosong;
	return st->top->value;
}

void emptyStack(stack* st)
{
	while(st->size) pop(st);
}

int cek(stack* st)
{
	while(st->size)
	{
		koor now = st->top->value;
		pop(st); 
		arr[now.x][now.y]=0;
		if(now.x == 0 && now.y == n-1)
		{
			ans=1;
			break;
		}
		if(now.x + 1 < n && arr[now.x+1][now.y])
		{
			koor move = now;
			move.x = now.x+1;
			push(move,st);
		} 
		
		if(now.x - 1 >= 0 && arr[now.x-1][now.y])
		{
			koor move = now;
			move.x = now.x-1;
			push(move,st);
		} 
		if(now.y + 1 < n && arr[now.x][now.y+1])
		{
			koor move = now;
			move.y = now.y+1;
			push(move,st);
		} 
		if(now.y - 1 < n && arr[now.x][now.y-1])
		{
			koor move = now;
			move.y = now.y-1;
			push(move,st);
		}	
	}
	if(ans) return 1;
	else return 0;
}

int main()
{
	memset(arr,0,sizeof(arr));
	stack* st = (stack*) malloc(sizeof(stack));
	st->top = NULL;
	st->size = 0;
	int i,j,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	if(arr[0][n-1]==0 || arr[n-1][0]==0) printf("Buntu yaa Thanus\n");
	else
	{
		koor k;
		k.x=n-1;
		k.y=0;
		push(k,st);
		if(cek(st)) printf("Ada jalan yaa Thanus\n");	
		else printf("Buntu yaa Thanus\n");
	}
	return 0;
}
