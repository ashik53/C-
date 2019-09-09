#include <bits/stdc++.h>
using namespace std;


map<string, int> strInfo;
set<string> allNodes;
int parentInfo[200005], groupInfo[200005];
int cnt;
string friend1, friend2;
void stringMapping(string &str);

void makeSet(int n){
    parentInfo[n] = n;
    groupInfo[n] = (99999999 -99999999) + 1;
}

int findParent(int u){

    if(parentInfo[u] == u) return parentInfo[u];
    else return parentInfo[u] = findParent(parentInfo[u]);
}

int unionNodes(int a, int b){

    int u = findParent(a);
    int v = findParent(b);

   // int total = groupInfo[u] + groupInfo[v];
    //cout << u->node << " " << v->node << " "<< total << endl;
    if(u != v) {
        if(groupInfo[u] > groupInfo[v]){
            groupInfo[u] += groupInfo[v], parentInfo[v] = u;
            return groupInfo[u];
        }
        parentInfo[u] = v;
        groupInfo[v] += groupInfo[u];

        return groupInfo[v];
    }
    return groupInfo[u];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, connections;
    string inputString;

    scanf("%d", &cases);
    for(int li = 0; li < cases; li++){
        scanf("%d", &connections);
        getchar();

        strInfo.clear();
        allNodes.clear();
        cnt = 1;
        for(int i = 1; i < (connections*2+7); i++) {makeSet(i);}
        for(int i = 1; i <= connections; i++){
            cin >> friend1 >> friend2;
           // cout << friend1 <<" " << friend2 << endl;
            stringMapping(friend1);
            stringMapping(friend2);
           // cout << strInfo[friend1] << " " << strInfo[friend2] << endl;
            //make frends
            printf("%d\n",(int) unionNodes(strInfo[friend1], strInfo[friend2]));



        }
    }//cases

}

void stringMapping(string &str){

    set <string> :: iterator it = allNodes.find(str);
    if(it == allNodes.end() && strInfo[str] == 0){ // IF NOT FOUND
        strInfo[str] = cnt++;
        allNodes.insert(str);
    }
}


