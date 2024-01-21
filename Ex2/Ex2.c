#include <stdio.h>

int main(void) 
{
    float taxArray[12];
    //float array2[12];
    float salary;
    float taxRate;
    float incomeLimit;
    float incomeLimitYearly;
    int index = 0;
    int i = 0;

    printf("Enter tax rate: ");
    scanf("%f", &taxRate);

    printf("Enter income limit: ");
    scanf("%f", &incomeLimit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &incomeLimitYearly);

    while(index < 12) 
    {
        printf("Enter income for month %d: \n", (index + 1));
        scanf("%f", &salary);
        taxArray[index] = salary;
        index++;
    }

    return 0;
}