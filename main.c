#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
};

int day_of_year(struct date d1){
    int months_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = 0;

    if(d1.year % 400 == 0 || (d1.year % 4 == 0 && d1.year % 100 != 0))
        months_days[1]++;

    for(int i = 0; i < d1.month - 1; i++)
        result += months_days[i];

    result += d1.day;
    return result;
}

int compare_dates(struct date d1, struct date d2){
    if(d1.year != d2.year)
        return (d1.year > d2.year) ? 1 : -1;

    if(d1.month != d2.month)
        return (d1.month > d2.month) ? 1 : -1;

    if(d1.day != d2.day)
        return (d1.day > d2.day) ? 1 : -1;

    return 0;
}

int main(void){
    char op_code;
    while(op_code != 'q'){
        printf("Enter a number to choose one of functions: \n");
        printf("1. day_of_year(d1);\n");
        printf("2. compare_dates(d1, d2);\n");

        scanf(" %c", &op_code);
        getchar();


        struct date d1, d2;
        if(op_code == '1'){
            printf("\nEnter values of d1 as dd.mm.yyyy: ");
            scanf("%2d . %2d . %4d", &d1.day, &d1.month, &d1.year);
            getchar();
            printf("It is the day %d of the year %d.\n\n", day_of_year(d1), d1.year);
        }else if(op_code == '2'){
            printf("\nEnter values of d1 as dd.mm.yyyy: ");
            scanf("%2d . %2d . %4d", &d1.day, &d1.month, &d1.year);
            getchar();
            printf("Enter values of d2 as dd.mm.yyyy: ");
            scanf("%2d . %2d . %4d", &d2.day, &d2.month, &d2.year);
            getchar();
            int temp_var = compare_dates(d1, d2);
            if(temp_var == 0)
                printf("Both dates are the same!\n\n");
            else if(temp_var > 0)
                printf("d2 is earlier than d1\n\n");
            else
                printf("d1 is earlier than d2\n\n");
        }
    }
    return 0;
}
