// Fatih Bozik & Ahmet Eroðlu
// 1358120003  & 1358120010
// Veri Yapýlarý Ödev 6

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
void findCycle(NODEPTR, int[][4], int, int);
int isThere(NODEPTR, int);
void insert(NODEPTR *, int);

int main()
{
	NODEPTR list = NULL;
	int baslangic, bitis;
	int graf[4][4] = {
		0, 1, 0, 1,
		1, 0, 1, 1,
		0, 1, 0, 1,
		1, 1, 1, 0
	};
	printf("Baslangic ve bitis dugumlerini giriniz.\nBaslangic :");
	scanf("%d", &baslangic);
	printf("Bitis     :");
	scanf("%d", &bitis);

	push(&list, baslangic);
	findCycle(list, graf, baslangic, bitis);

	printf("%d den %d dugumune gore olusacak yol : ", baslangic, bitis);
	for (NODEPTR p = list; p != NULL; p = p->next)
	{
		if (p->next == NULL)
			printf("%d", p->info);

		else
			printf("%d -> ", p->info);
	}





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

void place(NODEPTR *plist, int x)
{
	NODEPTR  p, q = NULL;
	for (p = *plist; p != NULL; p = p->next)
		q = p;

	/* at this point, a node containing x must be inserted */

	insafter(q, x);
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

void findCycle(NODEPTR p, int graph[][4], int baslangic, int bitis)
{
	int i, k;

	for (i = 0; i <= 3; ++i)
	{
		if (graph[baslangic - 1][i] == 1 && !isThere(p, i + 1))
		{
			place(&p, i + 1);
			break;
		}
	}

	if (i + 1 == bitis)
		return;

	findCycle(p, graph, i + 1, bitis);
}

int isThere(NODEPTR list, int x)
{
	for (NODEPTR p = list; p != NULL; p = p->next)
		if (p->info == x)
			return 1;

	return 0;
}