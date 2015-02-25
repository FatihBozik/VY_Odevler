// Fatih Bozik
// 1358120003
// Veri Yapýlarý Ödev 5

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * NODEPTR;

// function prototypes
NODEPTR getnode(void);
void freenode(NODEPTR);
void insafter(NODEPTR, int);
void place(NODEPTR *, int);
void push(NODEPTR *, int);
void findCycle(NODEPTR, int[][5], int);
int isThere(NODEPTR, int);

int main()
{
	NODEPTR list = NULL;

	int graf[5][5] = {
		0, 1, 0, 0, 1,
		1, 0, 1, 1, 1,
		0, 1, 0, 1, 0,
		0, 1, 1, 0, 1,
		1, 1, 0, 1, 0
	};
	int dugumNo;

	do
	{
		printf("Lutfen (1 ile 5 arasinda) bir dugum numarasi giriniz.\n");
		scanf("%d", &dugumNo);

	} while (dugumNo < 1 || dugumNo > 5);

	push(&list, dugumNo);

	findCycle(list, graf, dugumNo);

	printf("%d. dugume gore olusacak cevrim : ", dugumNo);
	for (NODEPTR p = list; p != NULL; p = p->next)
		printf("%d -> ", p->info);

	printf("%d", dugumNo);

	getchar();
	getchar();
	return 0;
}

NODEPTR getnode()
{
	NODEPTR p;
	p = (NODEPTR)malloc(sizeof(NODE));
	return (p);
}

void freenode(NODEPTR p)
{
	free(p);
}

void push(NODEPTR *p, int x)
{
	NODEPTR q = getnode();
	q->info = x;
	q->next = *p;
	*p = q;
}

void insafter(NODEPTR p, int x)
{
	NODEPTR q;
	if (p == NULL)
	{
		printf("void insertion\n");
		exit(1);
	}

	q = getnode();
	q->info = x;
	q->next = p->next;
	p->next = q;
}

void findCycle(NODEPTR p, int graph[][5], int numnode)
{
	int i, k;

	for (i = 0; i <= 4; ++i)
	{
		if (graph[numnode - 1][i] == 1 && !isThere(p, i + 1))
		{
			insafter(p, i + 1);
			break;
		}
	}

	if (i + 1 == numnode)
		return;

	findCycle(p, graph, i + 1);
}

int isThere(NODEPTR list, int x)
{
	for (NODEPTR p = list; p != NULL; p = p->next)
		if (p->info == x)
			return 1;

	return 0;
}