#include <stdio.h>
#include <math.h>
void printMenu();
double division(double a, double b);
double modulus(int a, int b);
int main()
{
    int choice;
    double num1, num2, result;
    while(1)
    {
        printMenu();
        scanf("%d", &choice);
        if(choice == 7)
        {
            break;
        }

        if(choice < 1 || choice > 7)
        {
            fprintf(stderr, "Invalid Menu Choice.");
            continue;
        }

        printf("\nPlease enter the First Number : ");
        scanf("%lf", &num1); //%lf as the data type is double 
        printf("Now, please enter the Second Number : ");
        scanf("%lf", &num2);

        switch(choice)
        {
            case 1: //Add
                result = num1 + num2;
                break;
            case 2: //Substract
                result = num1 - num2;
                break;
            case 3: //Multiply
                result = num1 * num2;
                break;
            case 4: //Divide
                result = division(num1, num2);
                break;
            case 5: //Modulus
                result = modulus((int)num1, (int)num2);
                break;
            case 6: //Power
                result = pow(num1, num2);
                break;
        }
        if(!isnan(result))
        {
            printf("\nResult of the operation is: %.2f", result);
        }    
    }
    
    return 0;
}
void printMenu()
{
    printf("\n\n-----------------------------------");
    printf("\nWelcome to Simple Calculator\n");
    printf("\nChoose one of the following options:");
    printf("\n1.Add");
    printf("\n2.Subtract");
    printf("\n3.Multiply");
    printf("\n4.Divide");
    printf("\n5.Modulus");
    printf("\n6.Power");
    printf("\n7.Exit");
    printf("\nNow, Enter your choice:");
}
double division(double a, double b)
{
    if(b == 0)
    {
        //For Error Handling, We can use the method of fprintf which prints in the file. This gives a standard error.       
        fprintf(stderr, "Invalid Argument for Division");
        return NAN; //NAN = Not An Number
    }
    else
    {
        return a / b;
    }
}
double modulus(int a, int b)
{
    if(b == 0)
    {
        fprintf(stderr, "Invalid Argument for Modulus");
        return NAN; //NAN = Not An Number
    }
    else
    {
        return a % b;
    }
}