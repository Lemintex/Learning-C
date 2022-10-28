#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
    int yearday;
    char mon_name[3];
};

static int day_tab[2][12] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int dayOfYear(struct date *pd);

int main() {
    struct date input = {1, 12, 2014, 0, "dec"};
    int day = dayOfYear(&input);
    printf("%i", day);
}

int dayOfYear(struct date *pd) {
    int i, day, leap;

    day = pd->day;
    leap = pd->year % 4 == 0 && pd->year % 100 != 0 || pd->year % 400 == 0;
    for (i = 1; i < pd->month; i++) {
        day += day_tab[leap][i];
    }
    return (day);
}
