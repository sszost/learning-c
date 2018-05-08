// this program converts day of year into day of the month and vice versa
#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);
int is_leap(int);

static int day_tab[2][13] = {
    {0,
     31,
     28,
     31,
     30,
     31,
     30,
     31,
     30,
     31,
     30,
     31,
     30},
    {0,
     31,
     29,
     31,
     30,
     31,
     30,
     31,
     30,
     31,
     30,
     31,
     30}};

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  int yearday = day_of_year(2018, 5, 7);
  printf("Today is %d day of year\n", yearday);

  int month, day;
  month_day(2018, yearday, &month, &day);
  printf("Today is %d month %d day\n", month, day);

  return 0;
}

int is_leap(int year)
{
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = is_leap(year);
  for (i = 1; i < month; i++)
    day += day_tab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = is_leap(year);
  for (i = 1; yearday > day_tab[leap][i]; i++)
    yearday -= day_tab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
