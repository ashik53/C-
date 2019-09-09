
#include <stdio.h>

int main() {




   int array[3];
   int big = array[0];
   int i;

   for(i=0;i<3;i++) scanf("%d",&array[i]);

   for(i=0;i<3;i++){

         if(big<array[i]) big = array[i];

   }

   printf("%d eh o maior\n",big);

   return 0;
}
