#include <stdio.h>

int main() {
    short year, month, date, day, n, leapYear;
    char ch, cond;

    do {
        cond = 0;
        printf("Enter an year from 1922 till 2122:\n");
        scanf("%hd%c", &year, &ch);
        if(ch!='\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
            continue;
        };
        if(year <= 1922 || year >= 2122) {
            printf("Year out of range, try again\n");
            cond = 1;
            fflush(stdin);
            ch=' ';
        };
    } while(cond);
    ch=' ';

    if( (year%100!=0 && year%4==0) || (year%100==0 && year%400==0) ) {
        leapYear = 1;
    } else {
        leapYear = 0;
    }

    do {
        cond = 0;
        printf("Enter a month:\n");
        scanf("%hd%c", &month, &ch);
        if(ch!='\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
            continue;
        };
        if(month <= 0 || month > 12) {
            printf("There is no such month\n");
            cond = 1;
            fflush(stdin);
            ch=' ';
        };
    } while(cond);
    ch=' ';

    do {
        cond = 0;
        printf("Enter a date:\n");
        scanf("%hd%c", &date, &ch);
        if(ch!='\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
            continue;
        };
        if(date <= 0 ||
            ( (month==1||month==3||month==5||month==7||month==8||month==10||month==12) && date>31) ||
            ( (month==4||month==6||month==9||month==11) && date>30) ||
            ( leapYear && month==2 && date>29) ||
            ( !leapYear && month==2 && date>28)) {
            printf("There is no such date\n");
            cond = 1;
            fflush(stdin);
            ch=' ';
        };
    } while(cond);

    if(month > 2) {
        n = 0;
    } else if(leapYear && month <= 2) {
        n = 1;
    } else if(!leapYear && month <=2) {
        n = 2;
    }

    day = ( (int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;

    switch(day) {
        case 0:
            printf("Monday");
            break;

        case 1:
            printf("Tuesday");
            break;
        case 2:
            printf("Wednesday");
            break;
        case 3:
            printf("Thursday");
            break;
        case 4:
            printf("Friday");
            break;
        case 5:
            printf("Saturday");
            break;
        case 6:
            printf("Sunday");
            break;
    }

    return 0;
}
