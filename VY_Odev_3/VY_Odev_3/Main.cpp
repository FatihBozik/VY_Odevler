// Fatih Bozik
// 1358120003

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

// fonksiyon prototipleri
void diziyiDoldur(int[], int);
void diziyiYazdir(int[], int);
void kabukSiralamasi(int[], int);

int main()
{
	int dizi[MAX];

	diziyiDoldur(dizi, MAX);
	printf("Dizi olusturuldu.\nOlusturulan dizi :\n\n");
	diziyiYazdir(dizi, MAX);

	kabukSiralamasi(dizi, MAX);
	printf("\n\nDizi siralandi.\nSiralanmis dizi :\n\n");
	diziyiYazdir(dizi, MAX);

	getchar();
	getchar();
	return 0;
}

void diziyiDoldur(int D[], int Boyut)
{
	srand(time(NULL));

	for (int index = 0; index <= Boyut - 1; index++)
	{
		D[index] = rand();
	}
}

void diziyiYazdir(int D[], int Boyut)
{
	for (int index = 0; index <= Boyut - 1; index++)
	{
		printf("%d\t", D[index]);

		if ((index + 1) % 5 == 0)
			printf("\n");
	}
}

void kabukSiralamasi(int D[], int Boyut)
{
	int h = 1, B, j;

	while ((h * 3 + 1) < Boyut)
		h = h * 3 + 1;

	while (h > 0)
	{
		for (int i = h - 1; i < Boyut; i++)
		{
			B = D[i];
			j = i;

			for (j = i; (j >= h) && D[j - h] > B; j -= h)
				D[j] = D[j - h];

			D[j] = B;
		}
		h /= 3;
	}
}