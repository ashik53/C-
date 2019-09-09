#include <stdio.h>

int main(void){

  int T,self,lift,i,t;
  int total_time;
   scanf("%d",&T);

    for(i=0;i<T;i++){
        scanf("%d%d",&self,&lift);
        if(self>lift){
            t = (self-lift) + self ;
            total_time = (t *4) +19 ;

           }
        else {
                t = (lift - self) + self ;
                total_time = (t*4) + 19 ;

           }

        printf("Case %d: %d\n",i+1,total_time);
    }





  return 0;

}
