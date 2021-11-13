#include<stdio.h>
#include <time.h>
#include <conio.h> /*for clrscr()*/


int isLeapYear(int year, int mon)
{
    int flag = 0;
    if (year % 100 == 0)
    {
            if (year % 400 == 0)
            {
                    if (mon == 2)
                    {
                            flag = 1;
                    }
            }
    }
    else if (year % 4 == 0)
    {
            if (mon == 2)
            {
                    flag = 1;
            }
    }
    return (flag);
}

void age()
{
    int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm *ct;
    system ("cls");


     printf("Enter your date of birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&days,&month, &year);

    //get the current date.
    ts = time(NULL);
    ct = localtime(&ts);
    printf("Current Date: %d/%d/%d\n",ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);



    days = DaysInMon[month - 1] - days + 1;

    if (isLeapYear(year, month))
    {
            days = days + 1;
    }

    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;

    if (isLeapYear((ct->tm_year + 1900), (ct->tm_mon + 1)))
    {
            if (days >= (DaysInMon[ct->tm_mon] + 1))
            {
                    days = days - (DaysInMon[ct->tm_mon] + 1);
                    month = month + 1;
            }
    }
    else if (days >= DaysInMon[ct->tm_mon])
    {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    }

    if (month >= 12)
    {
            year = year + 1;
            month = month - 12;
    }

    printf("\n You are %d years %d months and %d days old.\n",year, month, days);




    return;

}




void bmi()
{
    double h,w,bmi;


    printf("Enter weight in kg:  ");
    scanf("%lf", &w);

    printf("Enter height in meter:  ");
    scanf("%lf", &h);

    bmi=w/(h*h);
            system ("cls");


    printf("\nYour BMI is %lf", bmi);

    if(bmi<=15)
        printf("\nBMI Category:  Starvation\n");
    else if(bmi<=17.5)
        printf("\n2BMI Category:  Anorexic\n");
    else if(bmi<=18.5)
        printf("\nBMI Category:  Underweight\n");
    else if(bmi<=24.9)
        printf("\nBMI Category:  Ideal\n");
    else if(bmi<=25.9)
        printf("\nBMI Category:  Overweight\n");
    else if(bmi<=39.9)
        printf("\nBMI Category:  Obese\n");
    else
        printf("\nBMI Category:  Morbidly Obese\n");


    return;

}


void temparature()
{
    float celsius,fahrenheit;


    // Reads temperature in fahrenheit
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f",&fahrenheit);

    // Fahrenheit to celsius conversion formula
    celsius=(fahrenheit - 32)*5/9;
            system ("cls");

    // Print the result
    printf("\nCelsius = %.3f",celsius); //.3f means correct to 3 decimal places


    return;
}


void calculation()
{
    char op;
    float num1, num2, result=0.0f;


    /* Print welcome message */

    printf("Enter [number 1] [+ - * /] [number 2]\n");

    /* Input two number and operator from user */
    scanf("%f %c %f", &num1, &op, &num2);

    /* Switch the value and perform action based on operator*/
    switch(op)
    {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;

        default:
            printf("Invalid operator");
    }

          system ("cls");
          printf("\n");

    /* Prints the result */
    printf(" Result is :  %.2f\n", result);

    return;
}



int main()
{
    printf("                                                                                                  \n");
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    WELCOME TO  Daily Life Measurement      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                                                                                                   \n");

    printf("Enter 1 for AGE calculation !!\n");
    printf("Enter 2 for BMI calculation !!\n");
    printf("Enter 3 for Temperature calculation !!\n");
    printf("Enter 4 for Math calculation !!\n");
    printf("Enter 0 for Exit !!\n");
        printf("\n");




    int op;

    printf("Enter an option: ");
    scanf("%d",&op);
    printf("\n");

    if(op==0)
    {

        return 0;


    }


    else if(op==1){
        age();

    }

    else if(op==2){
        bmi();
    }
    else if(op==3){
        temparature();
    }
    else if(op==4){
        calculation();
    }

    main();


    return 0;

}



