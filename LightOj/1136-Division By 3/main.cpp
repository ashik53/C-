#include <stdio.h>
int main(void){

 unsigned long long first,last,count,result,i,j,all,line,m;
 unsigned long long array[11] = {9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999,99999999999};
 unsigned long long seven[11] = {7,67,667,6667,66667,666667,6666667,66666667,666666667,6666666667,66666666667} ;
 unsigned long long six[11] =   {6,66,666,6666,66666,666666,6666666,66666666,666666666,6666666666,66666666666} ;

 scanf("%lld",&line);

   for(m=0;m<line;m++){

         scanf("%lld%lld",&first,&last);
         count =0;
         if((array[0]+ first)>=last) {
              for(first;first<=last;first++){
                  result = ((first* (first+1))/2)%3;
                  if(result==0) count++;
              }
            printf("Case %lld: %lld\n",m+1,count);
           }
         else {
            i=0,all=0;
            while((array[i]+first)<last) i++;
            i--;
            while(i>0){
                first = first + array[i] ;
                if(first>last) {
                    first = first - array[i];
                    i--;
                  }
                else {
                   count=0;
                   for(j=first;j<=(first+9);j++){
                      result = ((j*(j+1))/2) % 3;
                      if(result==0) count++;
                    }
                   if(count==6) all = all + six[i];
                   else all = all + seven[i];
                   first++;
                 }
              }
              count=0;
              for(first;first<=last;first++){
                  result = ((first*(first+1))/2) % 3;
                  if(result==0) count++;
                }
              all = all+ count;
              printf("Case %lld: %lld\n",m+1,all);
          }

    }




}
