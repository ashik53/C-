#include <bits/stdc++.h>

using namespace std;


int sizeOfArray,queries,vajok,sizeOfGroup;
long numberList[207];
int result[27][27];

void recursion(int index,long sum,int cnt,int pos);
int main()
{

    int line =1;

    srand(time(NULL));

    while(scanf("%d%d",&sizeOfArray,&queries)==2) {
           for(int i=0;i<sizeOfArray;i++){
                long num = rand()%200 + 1 ;
                numberList[i] = num;
               // scanf("%d",&numberList[i]);
           }

           for(int i=1;i<=20;i++) for(int j=1;j<=20;j++) result[i][j] = 0;
           recursion(0,0,0,0);
           printf("SET %d:\n",line);
           for(int i=0;i<queries;i++){
                scanf("%d%d",&vajok,&sizeOfGroup);
                printf("QUERY %d: %d\n",i+1,result[sizeOfGroup][vajok]);
           }

           line++;

    }//cases

}//main

void recursion(int index,long sum,int cnt,int pos){

    if(pos){
        for(int i=1;i<=20;i++){
            if(sum%i==0) result[cnt][i]++;
        }
    }

    if(index==sizeOfArray) return;

    if(cnt<10) {
        recursion(index+1,sum+numberList[index],cnt+1,1);
        recursion(index+1,sum,cnt,0);
    }
}
