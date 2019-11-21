#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users
int bet[N_MAX_USER];

//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];		

void offerCards(void) {
	
	int i;
	configuser();
	
	//1. give two card for each players
	for (i=0;i<=n_user;i++)
	{
		cardhold[i][0] = pullCard();
	}
	cardhold[n_user+1][0] = pullCard();			//give #one card for the operator
	
	for (i=0;i<=n_user;i++)
	{
		cardhold[i][1] = pullCard();
	}
	cardhold[n_user+1][1] = pullCard();			//give #two card for the operator
	
	return;
}

int configuser(void) {
	
	srand((unsigned)time(NULL));
	
	do {
		
		printf("number of players:");
		scanf("%d", &n_user);			//get the input of number of players
	
    	if(n_user>5)
			printf("input number of players less than 5\n");			//users should be less than 5
	
	} while(n_user>5);			//if n_user is more than 5, repeat the loop

	return n_user;
}

int pullCard(void) {
	
	int i,j;
	mixCardTray();
	
	for (j=0;j<2;j++)
	{
		for (i=0;i<=n_user;i++)
		{
			cardhold[i][j] = CardTray[cardIndex];
		}
	}
	
	return cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
}

int mixCardTray(void) {
	
	int i,j;
	int n = N_CARDSET*N_CARD;			//make brief of N_CARDSET*N_CARD
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<n;i++)
	{
		CardTray[i] = rand()%n;			//input random number in array
		for(j=0;j<i;j++)			//examine whether the same random number has placed or not
		{
			if(CardTray[i]==CardTray[j])			//if the same number has arranged, return to same i and do the loop
			{
				i--;
				break;
			}
		}
	}
	
	for(i=0;i<n;i++)			//if N_CARDSET changes, CardTray[] still has 0~51 random number in each CARDSET
	{
		CardTray[i] = CardTray[i]%52;
	}
	
	return CardTray[N_CARDSET*N_CARD];
}

//print initial card status
int main(int argc, char *argv[]) {
	
	int i;
	configuser();
	
	printf("bet dollars(Max %d): ",N_DOLLAR);
	scanf("%d", &bet[0]);
	
	srand((unsigned)time(NULL));
	for(i=1;i<n_user-1;i++)
	{
		bet[i] = rand()%5+1;
		printf("player[%d] bet : %d\n", i, bet[i]);
	}

	
	return 0;
}
