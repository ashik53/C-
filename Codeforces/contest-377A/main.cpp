#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void bfs(int t1,int t2);
int row,col,newBlock;
char grid[507][507];
int level[507][507];
int vis[507][507];
int X[] ={-1,1,0,0};
int Y[] ={0,0,-1,1};
typedef pair<int, int> pii;
map<int,vector<pii> >mainList;
int main()
{



   scanf("%d%d%d",&row,&col,&newBlock);
   getchar();
   int x=-1 ,y=-1;
   for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
         scanf("%c",&grid[i][j]);
         if(grid[i][j]=='.' && x==-1) x = i, y =j;
      }
      getchar();
   }//input loop
  // cout<<x<<" "<<y<<endl;
   level[x][y] = 0;
   vis[x][y] =1 ;
   bfs(x,y);

   int bigDistance  = -100;
   for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
          if(grid[i][j]=='.'){
               if(level[i][j]>bigDistance) bigDistance = level[i][j];
               mainList[level[i][j]].push_back(pii(i,j));
          }
      }
   }
   bool cont = true;
   int cnt = 0;
   for(int i= bigDistance;i>=0;i--){
      for(int j = 0;j<mainList[i].size();j++){
          if(cnt == newBlock) {
             cont = false;
             break;
          }
          pii now = mainList[i][j];
          grid[now.first][now.second] = 'X';
          cnt++;

      }
      if(cont==false) break;
   }

  // cout<<endl;
  for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){

           printf("%c",grid[i][j]);
      }
      cout<<endl;
   }
}
void bfs(int t1,int t2){

   int x,y;

       queue<pii> mq;
       mq.push(pii(t1,t2));
       while(mq.size()!=0){
         pii now = mq.front();
         mq.pop();
           for(int i=0;i<4;i++){
              x = X[i]+ now.first,y = Y[i]+ now.second;
              if(x<row && y<col && grid[x][y]!='#' && x>=0 && y>=0 && vis[x][y]==0){
                   mq.push(pii(x,y));
                   vis[x][y]=1;
                   level[x][y] = level[now.first][now.second]+1;
               }
           }

       }
   }
