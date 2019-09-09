#include <stdio.h>
#include <string.h>

int main(void){

    char str[100];
    int i,j,k,t,m;
    scanf("%d",&t);
    getchar();

    for(m=0;m<t;m++){
         gets(str);
         k = 1;
         j = strlen(str)-1 ;
           for(i=0,j;str[i]!='\0' && j>=0;i++,j--){
              if(str[i] != str[j]){
                  k=0;
                  break;
             }

          }

         if(k==0) printf("Case %d: No\n",m+1);
         else printf("Case %d: Yes\n",m+1);

    } //for


} //main
