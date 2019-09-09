#include <stdio.h>

int main (){
   int T,i,j;

   double sq,r,ci;

   scanf("%d",&T);

   if(T<=1000){

       for(j=0;j<T;j++){

          scanf("%lf",&r);

          if(r>0 && r<=1000) {
             sq = (2*r)*(2*r);
             ci = (2*acos(0.0))* r *r ;

             printf("Case %d: %.2lf\n",j+1,sq-ci);
           } //if
         } //for


       } //case

   return 0;
}
