#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_CARDSET			2
#define N_CARD				52

int CardTray[N_CARDSET*N_CARD];

int main(void) {
	
	int hartA = 0;
	int hart2 = 1;
	int hart3 = 2;
	int hart4 = 3;
	int hart5 = 4;
	int hart6 = 5;
	int hart7 = 6;
	int hart8 = 7;
	int hart9 = 8;
	int hart10 = 9;
	int hartJ = 10;
	int hartQ = 11;
	int hartK = 12;
	
	int diaA = 13;
	int dia2 = 14;
	int dia3 = 15;
	int dia4 = 16;
	int dia5 = 17;
	int dia6 = 18;
	int dia7 = 19;
	int dia8 = 20;
	int dia9 = 21;
	int dia10 = 22;
	int diaJ = 23;
	int diaQ = 24;
	int diaK = 25;

	int spadeA = 26;
	int spade2 = 27;
	int spade3 = 28;
	int spade4 = 29;
	int spade5 = 30;
	int spade6 = 31;
	int spade7 = 32;
	int spade8 = 33;
	int spade9 = 34;
	int spade10 = 35;
	int spadeJ = 36;
	int spadeQ = 37;
	int spadeK = 38;
	
	int clubA = 39;
	int club2 = 40;
	int club3 = 41;
	int club4 = 42;
	int club5 = 43;
	int club6 = 44;
	int club7 = 45;
	int club8 = 46;
	int club9 = 47;
	int club10 = 48;
	int clubJ = 49;
	int clubQ = 50;
	int clubK = 51;
	
	int i,j;
	int CardTray[N_CARDSET*N_CARD];
	int n = N_CARDSET*N_CARD;
	
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		CardTray[i] = rand()%n;
		for(j=0;j<i;j++)
		{
			if(CardTray[i]==CardTray[j])
			{
				i--;
				break;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		CardTray[i] = CardTray[i]%52;
		printf("CardTray[%i] is %i\n",i,CardTray[i]);
	}
	return 0;
}
