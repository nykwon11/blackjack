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
int gameEnd = 0; 							//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)
int getIntegerInput(void) {
	
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


//card processing functions ---------------

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
	mixCardTray();
	
	int i;
	cardnum = i;
	
	if(i<13)			//replace number to letters in the CardTray[]
	{
		{
			if(i==0)
				printf("hartA");
					
			else if(i==10)
				printf("hartJ");
				
			else if(i==11)
				printf("hartQ");
					
			else if(i==12)
				printf("hartK");
					
			else
				printf("hart%d",i);			
		}	
	}
	else if(i>=13 && i<26)
	{
		{
			if(i==13)
				printf("diaA");
				
			else if(i==23)
				printf("diaJ");
				
			else if(i==24)
				printf("diaQ");
					
			else if(i==25)
				printf("diaK");
				
			else
				printf("dia%d", i-12);
		}
	}
	else if(i>=26 && i<39)
	{
		{
			if(i==26)
				printf("spadeA");
			
			else if(i==36)
				printf("spadeJ");
				
			else if(i==37)
				printf("spadeQ");
				
			else if(i==38)
				printf("spadeK");
					
			else
				printf("spade%d",i-25);
		}
	}
	else
	{
		{
			if(i==39)
				printf("clubA");
					
			else if(i==49)
				printf("clubJ");
			
			else if(i==50)
				printf("clubQ");
				
			else if(i==51)
				printf("clubK");
				
			else
				printf("club%d", i-38);
		}
	}
}


//card array controllers -------------------------------

//mix the card sets and put in the array
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

//get one card from the tray
int pullCard(void) {
	
	mixCardTray();
	cardIndex++;
	
	return CardTray[cardIndex];			//pull one card out of the cardtray
}


//playing game functions -----------------------------

//set the number of players
int configuser(void) {
	
	do {
		
		printf("number of players:");
		scanf("%d", &n_user);			//get the input of number of players
	
    	if(n_user>5)
			printf("input number of players less than 5\n");			//users should be less than 5
	
	} while(n_user>5);			//if n_user is more than 5, repeat the loop

	return n_user;
}


//betting
int betDollar(void) {
	
	int i;
	
	printf("bet dollars(Max %d): ",N_DOLLAR);
	scanf("%d", &bet[0]);			//bet for player"you"
	
	srand((unsigned)time(NULL));
	
	for(i=1;i<n_user;i++)			//other players will bet randomly
	{
		bet[i] = rand()%5+1;
		printf("player[%d] bet : %d\n", i, bet[i]);
	}
	
	return bet[N_MAX_USER];
}


//offering initial 2 cards
void offerCards(void) {
	
	int i;
	
	//1. give two card for each players
	for (i=0;i<=n_user;i++)			//give first card for players
	{
		cardhold[i][0] = pullCard();
	}
	cardhold[n_user+1][0] = pullCard();			//give first card for the operator
	
	for (i=0;i<=n_user;i++)			//give second card for players
	{
		cardhold[i][1] = pullCard();
	}
	cardhold[n_user+1][1] = pullCard();			//give second card for the operator
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	
	int i;
	
	offerCards();
	printCard(pullCard());			//pullcard(); to print letters
 
	printf("you : %d %d\n", cardhold[0][0], cardhold[0][1]);			//initial two cards for "you"	

	for (i=1;i<n_user;i++)
	{
		printf("player[%d] : %d %d\n", i, cardhold[i][0], cardhold[i][1]);			//initial two cards for other players
	}
	
	printf("dealer : X %d\n", cardhold[n_user][0], cardhold[n_user][1]);			//initial two cards for "dealer"
}

int getAction(void) {
	
	int i;
	
	printf("go(0)? stop(1)? : ");
	scanf("%d" &i);
	
	if (i==0)
	{
	pullCard();
	printf("you : %d %d %d", cardhold[0][0], cardhold[0][1], cardhold[0][2]);
	}
	
	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
							//see each step result
							//if player is over 21, printf dead!
}							//if player is 21, blackjack!
							//else go to next step

int checkResult() {
	
}

int checkWinner() {
							//see result
							//if player sum is higher than dealer, printf win!
							//else if dealer is blackjack, printf lose!
							//else if player sum is higher than 21, printf lose!
	
}



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configuser();


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	do {
		
		betDollar();
		offerCards(); //1. give cards to all the players
		
		printCardInitialStatus();
		printf("\n------------------ GAME start --------------------------\n");
		
		//each player's turn
		for() //each player
		{
			while () //do until the player dies or player says stop
			{
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
			getAction();		//GO? STOP? ::: getAction()
				//check if the turn ends or not
			}
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}
