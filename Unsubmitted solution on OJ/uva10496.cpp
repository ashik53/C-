
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int a;
    int b;
    P(int x,int y):a(x),b(y){};


};

vector<Node*> nodeList,result;
int X[] = {0,0,-1,1};
int Y[] = {1,-1,0,0};
int True,True2,startX,startY,totalNodes;
int vis[27][27],taken[27][27];
int distance[27][27];
bool isValid(int x,int y){

  if(x<row && y<col && x>=0 && y>=0 && vis[x][y]!=True) return true;

  return false;

}
int bfs(int x1,int y1,int x2,int y2);
int main(){

   int cases,x,y;

   for(int line = 0;line<cases;line++){
       scanf("%d%d",&row,&col);
       scanf("%d%d",&startX,&startY);
       scanf("%d",&totalNodes);
       nodeList.clear();
       for(int i=0;i<totalNodes;i++){
          scanf("%d%d",&x,&y);
          nodeList.push_back(new Node(x,y));
       }

       solve();


   }//cases

}

void solve(){

   True2++;

   int sz = nodeList.size();
   Info* source = Node(startX,startY);
   for(int i=0;i<sz;i++){
      int distance = 10000000;

      for(int j=0;j<sz;j++){
        if(taken[source->x][source->y]!=True2 && bfs(source->x,source->y,nodeList[j]->x,nodeList[j]->y)<distance){
            distance = bfs(source->x,source->y,nodeList[j]->x,nodeList[j]->y);
            source = Node(nodeList[j]->x,nodeList[j]->y);
        }
        ans+= distance;
        taken[source->x][source->y] = True2;
      }

      if(i==sz-1){
        ans+= bfs(startX,startY,source->x,source->y);
      }


   }// n*n node loop

}
int bfs(int x1,int y1,int x2,int y2){

  True++;
  memset(distance,0,sizeof(distance[0][0])*27*27);

  queue<Node*>mq;

  vis[x1][y1] = True;
  mq.push(Node(x1,y1));

  while(mq.size()!=0)){

    Node* top = mq.front();

    if(top->a==x2 && top->b==y2) return distance[x2][y2];

    mq.pop();

    //loop to move all directions
    for(int i=0;i<4;i++){
        int tx = top->a;
        int ty = top->b;
        if(isValid(tx,ty)){
            vis[tx][ty] = True;
            distance[tx][ty] = distance[top->a][top->b]+1;
            mq.push(tx,ty);
        }
    }//loop to move all directions
  }//queue

  return distance[x2][y2];

}

