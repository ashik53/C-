#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

  char main_str[1000];
  char given_binarystring[100];
  char s_str[1000];
  char str2[1000];
  int i,j,len,number,dif,d,y,b,m,t,array[100],vagshesh;

  scanf("%d",&t);
  getchar();

   for(m=0;m<t;m++){
     gets(main_str);
     gets(str2);
     j=0,b=0;
     len = strlen(main_str) - 1;
     for(i=0;main_str[i]!='\0';i++){
          if(main_str[i] !='.' || i== len){
                if(i==len){
                    s_str[j] = main_str[i];
                    j++;
                    s_str[j] = '\0';
                    number = atoi(s_str);
                    if(number==1|| number==0){ //for  0 1 start here
                           for(y=0;y<7;y++){
                               given_binarystring[b] = '0';
                               b++;
                             }
                           if(number==1) given_binarystring[b] = '1';
                           else given_binarystring[b] = '0';
                           b++;
                           given_binarystring[b] = '\0';

                      } //for 0 1 end here
                    else {  //for another number which is last starts here
                         d = 0 ;
                         while(number!=0){
                             vagshesh = number %2 ;
                             array[d] = vagshesh;
                             d++;
                             number = number /2;
                             if(number==0) {
                                array[d] = number ;
                              }
                            }
                           d--;
                          if(d==7){
                              for(d;d>=0;d--) {
                                  given_binarystring[b] = array[d] +'0';
                                  b++;
                                }
                              given_binarystring[b] = '\0' ;
                            }
                          else{
                               dif = 7-d;
                               for(y=0;y<dif;y++) {
                                  given_binarystring[b] = '0';
                                  b++;
                                 }
                               for(d;d>=0;d--){
                                   given_binarystring[b] = array[d]+'0';
                                   b++;
                                 }
                              given_binarystring[b] = '\0' ;

                          }

                       }//for another number which is last end here
                }
                else {
                    s_str[j] = main_str[i];
                    j++;
                  }
             }
          else if(main_str[i]=='.'){
              s_str[j] = '\0';
              number = atoi(s_str);

                 if(number==1 || number==0){ //for 0 or 1 start here
                    for(y=0;y<7;y++){
                         given_binarystring[b] = '0';
                         b++;
                       }
                    if(number==1) given_binarystring[b] = '1';
                    else given_binarystring[b] = '0';
                    b++;
                    given_binarystring[b] = '.';
                    b++;
                   }  //for 0 1 end here
                 else { //for another number starts here
                         d = 0 ;
                         while(number!=0){
                             vagshesh = number %2 ;
                             array[d] = vagshesh;
                             d++;
                             number = number /2;
                             if(number==0) {
                                array[d] = number ;
                              }
                            }
                          d-- ;
                          if(d==7){
                              for(d;d>=0;d--) {
                                  given_binarystring[b] = array[d] +'0';
                                  b++;
                                }
                              given_binarystring[b] = '.';
                              b++;

                            }
                          else{
                                  dif = 7-d;
                                  for(y=0;y<dif;y++) {
                                     given_binarystring[b] = '0';
                                     b++;
                                    }
                                  for(d;d>=0;d--){
                                      given_binarystring[b] = array[d]+'0';
                                      b++;
                                    }
                                  given_binarystring[b] = '.';
                                  b++;
                               }
                    } //another number not last end here
                  j=0;
                }

        }

  if(!strcmp(given_binarystring,str2)) printf("Case %d: Yes\n",m+1);
  else printf("Case %d: No\n",m+1);

  }

  return 0;

}
