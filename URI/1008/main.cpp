#include <stdio.h>

int main() {


  int code1,count1,code2,count2;
  float price1,price2,result;

  scanf("%d%d%f%d%d%f",&code1,&count1,&price1,&code2,&count2,&price2);

  result = price1*count1+price2*count2;

  printf("VALOR A PAGAR: R$ %.2f\n",result);


    return 0;
}
