#include <bits/stdc++.h>
using namespace std;

int parentInfo[200007];

void makeSet(int n){
    parentInfo[n] = n;
}
int findParent(int u){

    if(parentInfo[u] == u) return u;
    else return parentInfo[u] = findParent(parentInfo[u]);
}

void unionNodes(int a, int b){

    int u = findParent(a);
    int v = findParent(b);

    if(u != v){
        parentInfo[u] = v;
    }

}

int main(){
    int cases;
    string str;

    cin >> cases;
    getchar();
    getchar();
    for(int li = 0; li < cases; li++){
        getline(cin,str);
        int largestNode = ((int)str[0] - (int)'A') + 1;

        for(int i = 1; i <= largestNode; i++){
            makeSet(i);
        }


        while(getline(cin,str)){
            if(str.empty()) {/*cout << "string empty chilo\n"; */ break;}
           // cout << str << endl
           int u = (str[0] - (int)'A') + 1;
           int v = (str[1] - (int)'A') + 1;
           unionNodes(u, v);
        }//

        set<int> parent;
        for(int i = 1; i <= largestNode; i++){
            parent.insert(findParent(i));
            //cout << findParent(i) << endl;
        }

        int ans = parent.size();
        printf("%d\n",ans);
        if(li != cases-1) printf("\n");
       // cout << "getline false\n";
    }// cases

}
