#include <stdio.h>

int main() {
  char str[80];
  double salary,total_value,total_salary;

  gets(str);
  scanf("%lf%lf",&salary,&total_value);

  total_salary = salary+total_value*.15;

  printf("TOTAL = R$ %.2lf\n",total_salary);

  return 0;
}
