
//UVA 729, simple backtracking

/*How to compile
g++ -o main main.cpp, then main
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int x;
    int y;
    Node(int a,int b):x(a),y(b){};


};

vector<Node*> nodeList,combinationList;
int X[] = {0,0,-1,1};
int Y[] = {1,-1,0,0};
int True,minValue,startX,startY,totalNodes,row,col;
int vis[27][27],dis[27][27];
bool taken[27];

bool isValid(int x,int y){

  if(x<=row && y<=col && x>=1 && y>=1 ) return true;

  return false;

}
int bfs(int x1,int y1,int x2,int y2);
void backTracking(int len);
int main(){

   int cases,x,y;


   scanf("%d",&cases);
   for(int line = 0;line<cases;line++){
       scanf("%d%d",&row,&col);
       scanf("%d%d",&startX,&startY);
       scanf("%d",&totalNodes);
       nodeList.clear();

       for(int i=0;i<totalNodes;i++){
          scanf("%d%d",&x,&y);
          nodeList.push_back(new Node(x,y));
       }


       minValue = 100000;
       combinationList.clear();
       backTracking(0);
       printf("The shortest path has length %d\n",minValue);
   }//cases


}





void backTracking(int len){

  if(len==totalNodes){
      int ans = 0+  bfs(startX,startY,combinationList[0]->x,combinationList[0]->y);
      for(int n=0;n<totalNodes-1;n++){
         ans+= bfs(combinationList[n]->x,combinationList[n]->y,combinationList[n+1]->x,combinationList[n+1]->y);
      }
      ans+= bfs(startX,startY,combinationList[len-1]->x,combinationList[len-1]->y);
      minValue = min(ans,minValue);
  }//check min


  for(int i=0;i<totalNodes;i++){
      if(taken[i]==true) continue;

      taken[i] = true;
      combinationList.push_back(nodeList[i]);
      backTracking(len+1);
      taken[i] = false;
      combinationList.pop_back();

  }


}
int bfs(int x1,int y1,int x2,int y2){

  True++;

  for(int i=0;i<27;i++) for(int j=0;j<27;j++) dis[i][j] = 0;

  queue<Node*>mq;

  vis[x1][y1] = True;
  mq.push(new Node(x1,y1));

  while(!mq.empty()){

    Node* top = mq.front();

    if(top->x==x2 && top->y==y2) return dis[x2][y2];

    mq.pop();

    //loop to move all directions
    for(int i=0;i<4;i++){
        int tx = top->x+X[i];
        int ty = top->y+Y[i];
        if(isValid(tx,ty) && vis[tx][ty]!=True){
            vis[tx][ty] = True;
            dis[tx][ty] = dis[top->x][top->y]+1;
            mq.push(new Node(tx,ty));
        }
    }//loop to move all directions
  }//queue

  return dis[x2][y2];

}

