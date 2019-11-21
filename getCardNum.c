#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//get one card from the tray


int pullCard(void) {
	
	extern mixCardTray();
	cardIndex++;
	
	return CardTray[N_CARDSET*N_CARD];
}


//print initial card status
void printCardInitialStatus(void) {
	
	int i;

	extern offerCards();
	
	printf("dealer : %d %d\n", cardhold[n_user][0], cardhold[n_user][1]);
	printf("You : %d %d\n", cardhold[0][0], cardhold[0][1]);
	
	for (i=1;i<n_user;i++)
	{
		printf("player[%d] : %d %d\n", i, cardhold[i][0], cardhold[i][1]);
	}	
}


int getCardNum(int cardnum) {
	
	extern mixCardTray();
	
	if(0<=CardTray[cardnum]<4)
		CardTray[cardnum] = 1 || 11;
	
	else if(4<=CardTray[cardnum]<8)
		CardTray[cardnum] = 2;
		
	else if(8<=CardTray[cardnum]<12)
		CardTray[cardnum] = 3;
	
	else if(12<=CardTray[cardnum]<16)
		CardTray[cardnum] = 4;
	
	else if(16<=CardTray[cardnum]<20)
		CardTray[cardnum] = 5;

	else if(20<=CardTray[cardnum]<24)
		CardTray[cardnum] = 6;
			
	else if(24<=CardTray[cardnum]<28)
		CardTray[cardnum] = 7;
	
	else if(28<=CardTray[cardnum]<32)
		CardTray[cardnum] = 8;
			
	else if(32<=CardTray[cardnum]<36)
		CardTray[cardnum] = 9;
		
	else
		CardTray[cardnum] = 10;
	
	return CardTray[cardnum];	
}

