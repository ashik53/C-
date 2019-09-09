#include <stdio.h>
int main(void){

  int i,count,big,small,j,k=0,l,line,n;
  int array[1000],order[1000];

 scanf("%d",&line);


  for(i=0;i<1000;i++) array[i] = i+1;

  for(i=1;i<1000;i++){
      count = 0;
     for(j=1;j<=array[i];j++) if(array[i]%j==0) count++;

      if(i==1){
          big = count;
          small =count;
        }
      else {
           if(big<count) big = count;
           if(small>count) small = count ;
         }
     }

  order[k] = 1;
  k++;

  for(small;small<=big;small++){
      for(i=999;i>=1;i--){
          count = 0;
          for(j=1;j<=array[i];j++){
             if(array[i]%j==0) count++;
            }
          if(count==small){
             order[k] = array[i];
             k++;
           }
        }

    }

  for(l=0;l<line;l++){
     scanf("%d",&n);
     n--;
     for(i=0;i<1000;i++){
         if(i==n){
             printf("Case %d: %d\n",l+1,order[i]);
             break;
            }
        }

    }
return 0;

}
