
///

#include <bits/stdc++.h>

using namespace std;

int level, row, col, True;
char grid[32][32][32];
int dis[32][32][32], vis[32][32][32];
int sl, sr, sc, el, er, ec;
//direction array
int dl[] = {0, 0, 1, -1, 0, 0};
int dr[] = {1, -1, 0, 0, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};
class Node{
public:
    int ll, rw, cl; // cl = column, rw = row, ll = level;
    Node(int l, int r, int c): ll(l), rw(r), cl(c) {};

};

bool isValid(int l, int x, int y){

    if(l >= 1 && l <= level && x >= 1 && x <= row && y >= 1 && y <= col) return true;
    return false;
}
void bfs();

int main(){

    while(cin >> level >>row >> col){
       //getchar();
        if(level == 0 && row == 0 && col == 0) break;

        for(int l = 1; l <= level ; l++){
            for(int r = 1; r <= row; r++){
                for(int c = 1; c <= col; c++){
                    cin >> grid[l][r][c];
                    if(grid[l][r][c] == 'S') {
                        sl = l, sr = r, sc = c;
                    }
                    if(grid[l][r][c] == 'E') {
                        el = l, er = r, ec = c;
                    }
                }//col
                //getchar();
            }//row
            //getchar();
            //getchar();
        }//level
        getchar();
        getchar();

        /*for(int l = 1; l <= level ; l++){
            for(int r = 1; r <= row; r++){
                for(int c = 1; c <= col; c++){
                    cout << grid[l][r][c];
                } //col
                cout << endl;
            } //row
            cout << endl;
        }  //level
        */

        //bfs calling
        True++;
        memset(dis, 0, sizeof(dis[0][0][0]) * level * row * col);
        bfs();

        //solution printing
        if(vis[el][er][ec] == True){
            printf("Escaped in %d minute(s).\n", dis[el][er][ec]);
        } else{
            printf("Trapped!\n");
        }

        sl = 0, sr = 0, sc = 0;
        el = 31, er = 31, ec = 31;

    } //input
}

void bfs(){

    queue<Node*> Queue;
    vis[sl][sr][sc] = True;
    Queue.push(new Node(sl, sr, sc));

//    cout

    while(!Queue.empty()){
        Node* node = Queue.front();
        Queue.pop();

        for(int i = 0; i < 6 ; i++){
            int a = node->ll + dl[i];
            int b = node->rw + dr[i];
            int c = node->cl + dc[i];

            if(isValid(a, b, c) == true && vis[a][b][c] != True && grid[a][b][c] != '#'){
                Queue.push(new Node(a, b, c));
                vis[a][b][c] = True;
                dis[a][b][c] = dis[node->ll][node->rw][node->cl] + 1;
            }

        }//for

    }// Queue traverse


}
