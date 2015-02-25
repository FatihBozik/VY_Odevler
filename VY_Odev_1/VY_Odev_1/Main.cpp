// Fatih Bozik
// 1358120003

#include <stdio.h>
#define SIZE 10

struct stack
{
	int top;
	int stackdizi[SIZE];
};

struct queue
{
	int front, rear;
	int queuedizi[SIZE];
};

void menu();
void sPush(struct stack *);
void sPopAndQinsert(struct queue *, struct stack *);
void yazdir(struct queue);


int main()
{
	struct stack so;
	so.top = -1;

	struct queue qo;
	qo.front = qo.rear = SIZE - 1;

	int secim = 0;

	menu();
	printf("Lutfen 1'i secin\n");
	scanf("%d", &secim);

	while (secim != 1)
	{
		printf("Yanlýs secim:\n");
		menu();
		printf("Lutfen 1'i secin\n");
	}

	// eleman giriþi
	sPush(&so);

	menu();
	printf("Lutfen 2'yi secin\n");
	scanf("%d", &secim);

	while (secim != 2)
	{
		printf("Yanlýs secim:\n");
		menu();
		printf("Lutfen 2'yi secin\n");
	}

	// secim2
	sPopAndQinsert(&qo, &so);
	printf("Atama yapildi\n\n");

	menu();
	printf("Lutfen 3'u secin\n");
	scanf("%d", &secim);

	while (secim != 3)
	{
		printf("Yanlýs secim:\n");
		menu();
		printf("Lutfen 3'u secin\n");
	}

	yazdir(qo);

	getchar();
	getchar();
	return 0;
}

void sPush(struct stack * ps)
{
	int sayi;

	for (int i = 0; i <= SIZE - 1; i++)
	{
		printf("%d. sayiyi giriniz: \n", i + 1);
		scanf("%d", &sayi);

		ps->stackdizi[++(ps->top)] = sayi;
	}

}

void sPopAndQinsert(struct queue * pq, struct stack * ps)
{
	for (int i = 0; i <= SIZE - 1; i++)
	{
		if (pq->rear == SIZE - 1)
		{
			pq->rear = 0;
		}
		else if (pq->rear == pq->front)
		{
			printf("Kuyruk dolu");
			return;
		}
		else
		{
			(pq->rear)++;
		}

		pq->queuedizi[pq->rear] = ps->stackdizi[(ps->top)--];

	}

}

void menu()
{
	printf("1. Yigita eleman girisi\n");
	printf("2. Kuyruga atama yap\n");
	printf("3. Kuyrugu Listele\n");
}

void yazdir(struct queue pq)
{
	for (int i = SIZE - 1; i >= 1; i--)
	{
		printf("%d -> ", pq.queuedizi[i]);
	}
	printf("%d", pq.queuedizi[0]);

}
