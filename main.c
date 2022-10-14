#include <stdio.h>

int main() {
    short year, month, date, day, n;

    printf("year:\n");
    scanf("%hd", &year);
    printf("month:\n");
    scanf("%hd", &month);
    printf("date:\n");
    scanf("%hd", &date);

    if (year <= 0 || month <= 0 || month>12 || date <= 0 ||
        ( (month==1||month==3||month==5||month==7||month==8||month==10||month==12) && date>31) ||
        ( (month==4||month==6||month==9||month==11) && date>30) ||
        (((year%100!=0 && year%4==0) || (year%100==0 && year%400==0)) && month==2 && date>29) ||
        (!((year%100!=0 && year%4==0) || (year%100==0 && year%400==0)) && month==2 && date>28)) {
        printf("no such date");
    } else {
        if(month > 2) {
            n = 0;
        } else if(((year%100!=0 && year%4==0) || (year%100==0 && year%400==0)) && month <= 2) {
            n = 1;
        } else if(!((year%100!=0 && year%4==0) || (year%100==0 && year%400==0)) && month <=2) {
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
    }
    return 0;
}
