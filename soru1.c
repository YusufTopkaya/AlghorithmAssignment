#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetRandom(int, int);

int main()
{
	srand(time(0));
	int dizi[10], diziTek[10], diziCift[10];
	int* diziPtr, * cDiziPtr, * tDiziPtr;
	diziPtr = dizi;
	cDiziPtr = diziCift;
	tDiziPtr = diziTek;
	int a = 0, b = 0;
	for (int i = 0; i < 10; i++)
	{
		dizi[i] = GetRandom(100, 1);
		(dizi[i] % 2 == 0) ? a++ : b++;
	}
	cDiziPtr = (int*)malloc(a * sizeof(int));
	tDiziPtr = (int*)malloc(b * sizeof(int));
	b = a = 0;
	for (int g = 0; g < 10; g++)
	{
		int sayi = *(diziPtr + g);
		if (sayi % 2 == 0)
			*(cDiziPtr + a++) = sayi;
		else
			*(tDiziPtr + b++) = sayi;
	}
	tDiziPtr = realloc(tDiziPtr, (10 - (a)) * sizeof(int));
	cDiziPtr = realloc(cDiziPtr, (10 - (b)) * sizeof(int));
	printf("Ciftler\n");
	for (int j = 0; j < a; j++)
		printf("%d\n", *(cDiziPtr + j));
	free(cDiziPtr);
	printf("Tekler\n");
	for (int k = 0; k < b; k++)
		printf("%d\n", *(tDiziPtr + k));
	free(tDiziPtr);
	return 0;
}

int GetRandom(int max, int min)
{
	return (rand() % (max + 1) + min);
}
