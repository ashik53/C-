#include <stdio.h>
int main(void){

     unsigned long long array[31] = {1073741824,536870912,268435456,134217728,67108864,33554432,16777216,8388608,4194304,2097152,1048576,524288,262144
       ,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1} ;

    unsigned long long number,i,sum,count,line,m;

    scanf("%lld",&line);

    for(m=0;m<line;m++){
        scanf("%lld",&number);

        sum = 0,count=0;
        for(i=0;i<31;i++){
          if(array[i]<=number){
              sum = sum + array[i];
              if(sum>number) {
                 sum = sum - array[i];
                 //printf("0");
               }
              else count++;

          }
        }
        if(count%2==0) printf("Case %lld: even\n",m+1);
        else printf("Case %lld: odd\n",m+1);

    } //for
} //main
