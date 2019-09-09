#include <stdio.h>
int main() {

int T,i,a,b,c;
int array[3];
scanf("%d",&T);

   for(i=0;i<T;i++){
       scanf("%d%d%d",&a,&b,&c);
      a = a*a;
      b = b*b;
      c = c*c ;

         if((a+b)==c || (a+c)== b || (b+c)== a) printf("Case %d: yes\n",i+1);
         else printf("Case %d: no\n",i+1);



     }

  return 0;

}
