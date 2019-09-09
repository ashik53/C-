#include <stdio.h>
#include <math.h>
int main(void){
   int T,i;
   double a,b,c,d,dif,x1,y,area;

    scanf("%d",&T);
    if(T<=20){
     for(i=0;i<T;i++){
      scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
      printf("Case %d: ",i+1);
      if(a<=200 && a>=0 && b<=200 && b>=0 && c>=0 && c<=200 && d>=0 && d<=200){

            a = fabs(a);
            b = fabs(b);
            c = fabs(c);
            d = fabs(d);

              if(a>c) dif = a-c;
              else dif = c- a ;

               x1 = ((b*b - d*d) + (dif*dif)) /(2*dif) ;
               y = sqrt((b*b) - (x1*x1));

             area = y * ((a+c)/2) ;
             printf("%.10lf\n",area);
           }
       } //if
  } //case

return 0;
} //main
