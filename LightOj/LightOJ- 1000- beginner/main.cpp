#include <stdio.h>
int main(void){
 
 int T,a,b,i;
 scanf("%d",&T);
 
 if(T<=125){
   for(i=0;i<T;i++){
      scanf("%d%d",&a,&b);
      printf("Case %d: %d\n",i+1,a+b);
     }
   }
   
  return 0;
 
 
}