/*
Not:   Graf.txt dosyas�n�n ilk sat�r�nda graftaki d���m say�s� yer almal�d�r.
Hemen alt�ndaki sat�rlarda ise graf 1 ve 0 lardan olu�acak �ekilde matris formunda simgelenmelidir.

Misal:  5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0

kom�uluk matrisinin ilk sat�r� 0 numaral� dugumunu temsil etsin.
ikinci sat�r� 1 numaral� dugumunu temsil etsin.
ucuncu sat�r� 2 numaral� dugumunu temsil etsin.
dorduncu sat�r� 3 numaral� dugumunu temsil etsin.
besinci sat�r� 4 numaral� dugumunu temsil etsin.
...
n. sat�r n-1 numaral� dugumunu temsil etsin.
*/

#include <stdio.h>
#define MAX 20

void swap(int *, int *);
void bubbleSort(int[], int);
void yazdir(int[][2], int);

void main()
{
	FILE * grafPtr;  // Graf.txt dosyas�n� g�sterecek.

	// Graf� simgeleyen kom�uluk matrisi
	// Graf� dosyadan okuyup bu matriste saklayaca��z.
	int graf[MAX][MAX];

	// Hangi numaral� d���m ka� kenara sahip onu tutacak.
	// ilk s�tun d���m numaralar�n� ikinci s�tun ka� kenara sahip oldu�unu tutar.
	int dugum[MAX][2];

	// Graftaki d���m say�s�n� tutacak.
	int dugum_sayisi;

	if ((grafPtr = fopen("Graf.txt", "r")) == NULL)
	{
		printf("!! Dosya acilamadi !!\n");
	}
	else
	{
		// graftaki d���m say�s�n� dosyadan oku.
		fscanf(grafPtr, "%d", &dugum_sayisi);

		// Dugumleri numaraland�r.
		for (int i = 0; i < dugum_sayisi; i++)
		{
			dugum[i][0] = i;
		}

		// Graf� dosyadan oku diziye ata
		for (int i = 0; i < dugum_sayisi; i++)
			for (int j = 0; j < dugum_sayisi; j++)
				fscanf(grafPtr, "%d", &graf[i][j]);


		int say = 0; // D���mlerin kenar say�lar�n� saymak i�in kullanaca��z.
		for (int i = 0; i < dugum_sayisi; i++)
		{
			for (int j = 0; j < dugum_sayisi; j++)
			{
				if (graf[i][j] == 1)
				{
					say++; // kenar bulundu. Kenar say�s�n� 1 artt�r.
				}
			}

			dugum[i][1] = say;
			say = 0;
		}

		yazdir(dugum, dugum_sayisi);

		// D���mleri, kenar say�lar�na g�re k���kten b�y��e do�ru s�rala
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