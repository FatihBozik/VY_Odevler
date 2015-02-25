// Fatih Bozik
// 1358120003

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 500

// fonksiyon prototipleri
void diziyiYazdir(int[], int);
void insertionSort(int[], int);
void diziyiDoldur(int[], int);

int main()
{
	int dizi[BOYUT];
	time_t basla, bit;

	diziyiDoldur(dizi, BOYUT);
	printf("Dizi olusturuldu.\n\nDizi :\n");
	diziyiYazdir(dizi, BOYUT);

	// dizi sýralanmadan önceki zaman
	time(&basla);

	// dizi sýralandý.
	insertionSort(dizi, BOYUT);

	// dizi sýralandýktan sonraki zaman
	time(&bit);


	printf("Dizi insertion sort'a gore siralandi\nDizi :\n");
	diziyiYazdir(dizi, BOYUT);
	printf("Baslangic zamani : %s\n", ctime(&basla));
	printf("Bitis zamani     : %s\n", ctime(&bit));
	printf("Dizinin siralanmasi %lf saniye surdu..", difftime(bit, basla));


	getchar();
	getchar();
	return 0;
}

void diziyiYazdir(int D[], int Boyut)
{
	for (int index = 0; index <= Boyut - 1; index++)
	{
		printf("%d\t", D[index]);

		if ((index + 1) % 10 == 0)
			printf("\n");
	}
}

void diziyiDoldur(int D[], int boyut)
{
	srand(time(NULL));

	for (int index = 0; index <= boyut - 1; index++)
		D[index] = (rand() % boyut) + 1;
}

void insertionSort(int D[], int boyut)
{
	for (int i = 1; i < boyut; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (D[j] < D[j - 1])
			{
				int temp = D[j];
				D[j] = D[j - 1];
				D[j - 1] = temp;
			}
		}
	}
}