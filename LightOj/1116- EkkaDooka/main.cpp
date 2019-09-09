#include <stdio.h>


int main(void){

   unsigned long long i,number,k,quotient,mod;
   int T,j;
   scanf("%d",&T);
 for(j=0;j<T;j++){
    scanf("%lld",&number);

   if(number%2==0){
          for(i=2;i<=number;i=i+2){
              mod = number % i;
              if(!mod) quotient = number /i ;
              if(quotient%2!=0) {
                  printf("Case %d: %lld %lld\n",j+1,quotient,i);
                  break;
                }

         }

      }
   else printf("Case %d: Impossible\n",j+1);


  }
  return 0;
}
