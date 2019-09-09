#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s, t,nw;
    vector<int> v,v1;
    int m, n,d,res = 1000000;

    scanf("%d%d",&m,&n);
    cin >> s >> t;

    for(int i=0;i<=n-m;i++)
    {
         d = 0;
         for(int j=0,k=i;j<m;j++,k++)
         {
              if(s[j]!=t[k]) d++;

         }
        if(d<res)
        {
           res = d;
           v1.clear();
           for(int j=0,k=i;j<m;j++,k++)
           {
              if(s[j]!=t[k]) {
                    d++;
                  v1.push_back(j+1);
              }
           }
        }

    }
    //sort(v.begin(), v.end());
    cout<< res <<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<< v1[i]<<" ";

    }
    cout<< "\n";
}
