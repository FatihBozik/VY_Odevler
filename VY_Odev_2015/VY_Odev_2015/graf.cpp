/*
Not:   Graf.txt dosyasýnýn ilk satýrýnda graftaki düðüm sayýsý yer almalýdýr.
Hemen altýndaki satýrlarda ise graf 1 ve 0 lardan oluþacak þekilde matris formunda simgelenmelidir.

Misal:  5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0

komþuluk matrisinin ilk satýrý 0 numaralý dugumunu temsil etsin.
ikinci satýrý 1 numaralý dugumunu temsil etsin.
ucuncu satýrý 2 numaralý dugumunu temsil etsin.
dorduncu satýrý 3 numaralý dugumunu temsil etsin.
besinci satýrý 4 numaralý dugumunu temsil etsin.
...
n. satýr n-1 numaralý dugumunu temsil etsin.
*/

#include <stdio.h>
#define MAX 20

void swap(int *, int *);
void bubbleSort(int[], int);
void yazdir(int[][2], int);

void main()
{
	FILE * grafPtr;  // Graf.txt dosyasýný gösterecek.

	// Grafý simgeleyen komþuluk matrisi
	// Grafý dosyadan okuyup bu matriste saklayacaðýz.
	int graf[MAX][MAX];

	// Hangi numaralý düðüm kaç kenara sahip onu tutacak.
	// ilk sütun düðüm numaralarýný ikinci sütun kaç kenara sahip olduðunu tutar.
	int dugum[MAX][2];

	// Graftaki düðüm sayýsýný tutacak.
	int dugum_sayisi;

	if ((grafPtr = fopen("Graf.txt", "r")) == NULL)
	{
		printf("!! Dosya acilamadi !!\n");
	}
	else
	{
		// graftaki düðüm sayýsýný dosyadan oku.
		fscanf(grafPtr, "%d", &dugum_sayisi);

		// Dugumleri numaralandýr.
		for (int i = 0; i < dugum_sayisi; i++)
		{
			dugum[i][0] = i;
		}

		// Grafý dosyadan oku diziye ata
		for (int i = 0; i < dugum_sayisi; i++)
			for (int j = 0; j < dugum_sayisi; j++)
				fscanf(grafPtr, "%d", &graf[i][j]);


		int say = 0; // Düðümlerin kenar sayýlarýný saymak için kullanacaðýz.
		for (int i = 0; i < dugum_sayisi; i++)
		{
			for (int j = 0; j < dugum_sayisi; j++)
			{
				if (graf[i][j] == 1)
				{
					say++; // kenar bulundu. Kenar sayýsýný 1 arttýr.
				}
			}

			dugum[i][1] = say;
			say = 0;
		}

		yazdir(dugum, dugum_sayisi);

		// Düðümleri, kenar sayýlarýna göre küçükten büyüðe doðru sýrala
		for (int i = 0; i < dugum_sayisi; i++)
		{
			for (int j = 0; j < dugum_sayisi - i - 1; j++)
			{
				if (dugum[j][1] > dugum[j + 1][1])
				{
					swap((*(dugum + j) + 1), (*(dugum + j + 1) + 1));
					swap((*(dugum + j) + 0), (*(dugum + j + 1) + 0));
				}
			}
		}

		printf("\n\nDugumleri, kenar sayilarina gore kucukten buyuge:\n");
		yazdir(dugum, dugum_sayisi);

	}

	getchar();
	getchar();
}

void swap(int * a, int * b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void bubbleSort(int dizi[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (dizi[j] > dizi[j + 1])
				swap(dizi + j, dizi + j + 1);
}

void yazdir(int dizi[][2], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d numarali dugumun kenar sayisi : %d\n", dizi[i][0], dizi[i][1]);
	}

}