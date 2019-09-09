#include <bits/stdc++.h>

using namespace std;

bool vis[107];
int dis[107];
vector<int> adjList[107];

void bfs(int startNode);
int main(){

    int proceed, u, v, numberOfEdges,startNode;

    while(cin >> proceed && proceed == 1){

        scanf("%d", &numberOfEdges);
        for(int i = 1; i <= numberOfEdges; i++){
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        scanf("%d", &startNode);
        bfs(startNode);

    }
}

// this bfs finds all nodes shortest path
void bfs(int startNode){

    memset(vis, false, 107);
    memset(dis, 0, 107);

    queue<int> Queue;
    Queue.push(startNode);
    vis[startNode] = 1;


    while(!Queue.empty()){
        int currentNode = Queue.front();
        Queue.pop();
        printf("distance of %d is %d\n", currentNode, dis[currentNode]);

        for(unsigned int i = 0 ; i < adjList[currentNode].size(); i++){
            int neighbourNode = adjList[currentNode][i];

            if(vis[neighbourNode] == 0){
                vis[neighbourNode] = 1;
                dis[neighbourNode] = dis[currentNode] + 1;
                Queue.push(neighbourNode);
            }
        }//for
    }


}
