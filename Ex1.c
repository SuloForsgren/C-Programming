#include <stdio.h>

int main(void)
{
	float busTicket = 0; 
	float taxiTicket = 0; 
	float money = 0;
	int selection = 0;


	printf("Enter bus ticket price: ");
	scanf("%f", &busTicket);
	
	printf("Enter taxi ticket price: ");                     
    scanf("%f", &taxiTicket);                                                                                                      

	printf("How much money do you have?: ");
	scanf("%f", &money);
	printf("You have %.2f euros left.\n", money);

	travel:

		if (money < busTicket && money < taxiTicket)
		{
			printf("You need to walk. Bye!\n");
		}
		else 
		{
			printf("1) Bus (%.2f euros)\n2) Taxi (%.2f euros)\n", busTicket, taxiTicket);
			printf("Enter your selection: ");
			scanf("%d", &selection);
			
			
			switch(selection) 
			{
			case 1:
				if (money >= busTicket) 
				{
					printf("You chose bus\n");
					money -= busTicket;
					printf("%.2f\n", money);
				}
				else 
				{
					printf("You don't have enough money for bus\n");
				}
				break;
			case 2:
				if (money >= taxiTicket)
				{
					printf("You chose taxi\n");
					money -= taxiTicket;
					printf("%.2f\n", money);
				}
				else 
				{
					printf("You don't have enough money for taxi\n");
				}
				break;
			

			default:
				printf("Invalid\n");
			}
		goto travel;

	}

}
