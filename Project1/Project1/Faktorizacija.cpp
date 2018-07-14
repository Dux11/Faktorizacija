#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<stdlib.h>

void menu();
int unos();
void faktoriziraj(int, int,int []);
void ispis(int, int []);


void menu() {

	printf("************MENU************\n");
	printf("* U - Unos novog broja     *\n");
	printf("* K - Kraj programa        *\n");
	printf("****************************\n");

	printf("Unesite odabir : ");
}

int unos() {

	int broj;

	printf("Unesite zeljeni broj \n");
	scanf("%d", &broj);

	return broj;

}

void faktoriziraj(int num,int k,int niz_brojeva[]) {

	
	if (num % 2 == 0) {

		num = num / 2;
		niz_brojeva[k] = 2;
		faktoriziraj(num, k + 1,niz_brojeva);

	}

	else if (num % 3 == 0) {

		num = num / 3;
		niz_brojeva[k] = 3;
		faktoriziraj(num, k + 1, niz_brojeva);

	}

	else if (num % 5 == 0) {

		num = num / 5;
		niz_brojeva[k] = 5;
		faktoriziraj(num, k + 1, niz_brojeva);

	}

	else if (num % 7 == 0) {

		num = num / 7;
		niz_brojeva[k] = 7;
		faktoriziraj(num, k + 1, niz_brojeva);

	}
	

	else {

		if (num != 1) {

			niz_brojeva[k] = num;
			ispis(k, niz_brojeva);

		}
		else {

			k = k - 1;
			ispis(k, niz_brojeva);
		}
		

	}

	return;

}

void ispis(int k, int niz[]) {


	while (k >= 0) {

		printf("%d \t", niz[k]);
		k--;
	}
	printf("\n");
	return;
}


int main(void) {

	char *choice;

	choice = (char*)malloc(1 * sizeof(char));

	int num;
	int i;
	int niz_brojeva[10];



	do {

		menu();
		scanf(" %s", choice);

		switch ((toupper(*choice))) {

		case 'U':

			num = unos();
			i = 0;
			faktoriziraj(num, i,niz_brojeva);

			break;

		case 'K':

			printf("Laku noc \n");
			break;

		default:

			printf("Pogresan unos \n");
			break;
		}


	} while ((toupper(*choice)) != 'K');


	return 0;


}