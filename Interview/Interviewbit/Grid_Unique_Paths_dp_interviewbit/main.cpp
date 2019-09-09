#include <bits/stdc++.h>

using namespace std;

long long dpAra[1007][1007], vis[1007][1007];
int True, X, Y;
int sol(int X, int Y);
long long recursion(int row, int col){

    if(row == X && col == Y) return 1;
    if(row > X || col > Y)  return 0;
    if(vis[row][col] == True) return dpAra[row][col];

    vis[row][col] = True;

    long long ret1 = recursion(row + 1, col);
    long long ret2 = recursion(row, col + 1);

    return dpAra[row][col] = ret1 + ret2;

}



int main(){

     /*for(int i = 1; i <= 60; i++) {
        for(int j = 1; j <= 60; j++) {
            X = i, Y = j;
            True++;
            long long res = (long long) recursion(1, 1) ;
            if(res > 4294967296){
                cout << res  << " " << i <<","<< j<<" greater than 32 bit \n";
                break;
            }
            else cout << i << ","<< j << " "<< res << " less than 32 bit" << endl;
        }
     } */


    while(cin >> X >> Y){
        cout << sol(X, Y) <<endl;
    }
}
int sol(int X, int Y){

    if(X == 0 || Y == 0) return 0;
    if(X == 1 && Y == 1) return 1;

    return sol(X-1, Y) + sol(X, Y-1);

}
