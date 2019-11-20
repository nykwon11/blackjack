#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//set the number of players

int main(int argc, char *argv[]) {
	
	int n_user;
	
	do {
		
		printf("number of players:");
		scanf("%d", &n_user);
	
    	if(n_user>5)
			printf("input number of players less than 5\n");
	
    } while(n_user>5);                                                    ///configUser() erased 
    
    return 0;
}
