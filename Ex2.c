#include <stdio.h>

int main(void) 
{
    float taxArray[12];
    float salary;
    float taxRate;
    float higherTax;
    float incomeLimit;
    float tax;
    int index = 0;
    int i = 0;

    printf("Enter tax rate: ");
    scanf("%f", &taxRate);
    taxRate = taxRate / 100;

    printf("Enter income limit: ");
    scanf("%f", &incomeLimit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &higherTax);
    higherTax = higherTax / 100;

    while(index < 12) 
    {
        printf("Enter income for month %d: ", (index + 1));
        scanf("%f", &salary);
        taxArray[index] = salary;
        index++;
    }
    index = 0;

    printf("%-10s%-10s%5s\n", "Month", "Income", "Tax");
    while(index < 12)
    {
        if (taxArray[index] > incomeLimit) 
        {
            tax = taxArray[index] * higherTax;
        }
        else 
        {
            tax = taxArray[index] * taxRate;
        }
        
        printf("%5d%11.2f%9.2f\n", index + 1, taxArray[index], tax);
	    index++;
    }
    return 0;
}
