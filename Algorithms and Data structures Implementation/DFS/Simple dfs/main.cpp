/// interviewbit, LIS, unsolved

#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[107];
bool vis[107];
void dfs(int startNode);

int main(void){

    int numberOfPaths, startNode, a, b;

    memset(vis, false, sizeof(vis));

    cin >> numberOfPaths;

    for(int i = 0; i < numberOfPaths; i++){

        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);

    }// for

    cin >> startNode;
    dfs(startNode);

    int cnt = 0;
    for(int i = 0; i < 107; i++){
        if(vis[i]) cnt++;
    }

    cout << cnt << " nodes are connected to each other \n";

}

void dfs(int startNode){

    if(vis[startNode]) return;

    vis[startNode] = true;

    for(int i = 0; i < adjList[startNode].size(); i++){

        int nextNode = adjList[startNode][i];

        dfs(nextNode);
    }//for


}//

