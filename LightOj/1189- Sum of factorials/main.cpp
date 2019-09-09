#include <stdio.h>

int main(void){

  unsigned long long fact[21] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,
    1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
  int i,match ,array[30],count1,j,k,t,l,p,line,one=0,count2;
  int one_array[one];
  unsigned long long n[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  unsigned long long number,sum,swap,count=0;

  scanf("%d",&line);

  for(l=0;l<line;l++){
    scanf("%lld",&number);
    match = 0 ;
    i = 20 ;
     while(i>=0){
            if(fact[i]==number){
                match = 1;
                break;
              }
            else if(fact[i]<number) {
                break;
              }

          i--;


      } //while


      if(match==1){
            if(number!=1) printf("Case %d: %lld!\n",l+1,n[i]);
            else {

                 if(count%2==0) printf("Case %d: 1!\n",l+1);
                 else printf("Case %d: 0!\n",l+1);
                 count++;
              }

        }

      else {
             sum = 0,j=0;
           for(i;i>=0;i--){
               sum = sum + fact[i] ;
                if(sum > number) sum = sum - fact[i] ;
                else if(sum==number) {
                     array[j] = i;
                     j++;
                     break;
                   }
                else if(sum < number) {
                    array[j] = i;
                    j++;
                  }
             }
          if(sum<number) printf("Case %d: impossible\n",l+1);
          else {

                //use bubble sort here to sort
                   for(i=0;i<j-1;i++){
                          for(k = 0 ; k<j-i-1;k++) {
                              if(array[k] > array[k+1]) {
                                  swap = array[k];
                                  array[k] = array[k+1];
                                  array[k+1] = swap ;
                              }
                           }
                      }
                   count2 =0;
                   for(i=0;i<j;i++) {
                        if(array[i]==1 || array[i]==0) {
                            one_array[one] = number;
                            one++;
                            count2++;
                          }
                      }

                  if(count2==0 || count2==2){
                    printf("Case %d: ",l+1);
                        for(i=0;i<j;i++){
                             if(i==j-1) printf("%d!\n",array[i]);
                             else printf("%d!+",array[i]);
                          }

                      }

                   else if(count2==1) {
                           count1 = 0;
                           for(i=0;i<one;i++) if(number == one_array[i]) count1++;
                           if(count1%2==0) {
                               printf("Case %d: ",l+1);
                               for(i=0;i<j;i++){
                                 if(array[i]==1) printf("0!+");
                                 else if(i==j-1) printf("%d!\n",array[i]);
                                 else printf("%d!+",array[i]);
                               }
                             }
                           else {
                               printf("Case %d: ",l+1);
                               for(i=0;i<j;i++){
                                 if(array[i]==1) printf("1!+");
                                 else if(i==j-1)printf("%d!\n",array[i]);
                                 else printf("%d!+",array[i]);
                             }
                          }

                       }
             }

         }

   } //for

   return 0;
 }
