#include <stdio.h>
#include <math.h>

int main()
{
    int month, year;
    printf("Enter month and year: ");
    scanf("%d %d", &month, &year);
    int leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    int n;
    if (month == 2)                                                 n = leap>0 ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11) n = 30;
    else                                                            n = 31;

    long total_days = year * 365 + 1*year / 4 - 1*year / 100 + 1*year / 400;

    int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (leap)
    {
        month_days[1] = 29;
    }

    for (int i = 0; i < month - 1; i++)
        total_days += month_days[i];

    int start = total_days % 7;
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < start; i++)
    {
        printf("    ");
    }

    for (int d = 1; d <= n; d++)
    {
        if(d < 10)
        {
            printf("  %d ", d);
        }
        else
        {
            printf(" %d ", d);
        }
        if((d + start) % 7 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}