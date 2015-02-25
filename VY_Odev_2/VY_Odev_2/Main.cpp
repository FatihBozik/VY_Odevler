// Fatih Bozik
// 1358120003

#include <stdio.h>
#include <stdlib.h>

typedef struct listeDugumu
{
	int info;
	struct listeDugumu * nextPtr;

}ListeDugumu;

typedef ListeDugumu * ListeDugumuPtr;

// fonksiyon prototipleri
void ekle(ListeDugumuPtr *, int);
int elemanSay(ListeDugumuPtr);
void menu();

int main()
{
	ListeDugumuPtr baslangicPtr = NULL;
	int eleman, elemanSayisi;

	do
	{
		menu();
		scanf("%d", &eleman);
		ekle(&baslangicPtr, eleman);
	} while (eleman != 0);

	elemanSayisi = elemanSay(baslangicPtr);

	printf("Eleman alimi durduruldu.\n");
	printf("Listedeki eleman sayisi = %d'dir.\n", elemanSayisi);

	getchar();
	getchar();
	return 0;
}

void ekle(ListeDugumuPtr * sPtr, int deger)
{
	ListeDugumuPtr yeniPtr, oncekiPtr, suandakiPtr;

	yeniPtr = (ListeDugumuPtr)malloc(sizeof(ListeDugumu));

	if (yeniPtr != NULL && deger != 0)
	{
		yeniPtr->info = deger;
		yeniPtr->nextPtr = NULL;

		oncekiPtr = NULL;
		suandakiPtr = *sPtr;

		while (suandakiPtr != NULL && deger > suandakiPtr->info)
		{
			oncekiPtr = suandakiPtr;
			suandakiPtr = suandakiPtr->nextPtr;
		}

		if (oncekiPtr == NULL)
		{
			yeniPtr->nextPtr = *sPtr;
			*sPtr = yeniPtr;
		}
		else
		{
			oncekiPtr->nextPtr = yeniPtr;
			yeniPtr->nextPtr = suandakiPtr;
		}
	}


}

int elemanSay(ListeDugumuPtr suandakiPtr)
{
	int sayici = 0;

	if (suandakiPtr != NULL)
	{
		while (suandakiPtr != NULL)
		{
			sayici++;
			suandakiPtr = suandakiPtr->nextPtr;
		}
	}

	return sayici;
}


void menu()
{
	printf("Tek bagli listeye eleman eklemek icin\n");
	printf("lutfen bir sayi giriniz.\n");
	printf("(Eleman alimini sonlandirmak icin 0 giriniz)\n");
	printf("\n");

}