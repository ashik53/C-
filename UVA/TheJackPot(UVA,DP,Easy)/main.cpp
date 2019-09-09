#include <bits/stdc++.h>

using namespace std;

int sz,numbersAra[10007];

int main()
{
    while(scanf("%d",&sz)==1 && sz!=0){
        for(int i=0;i<sz;i++){
            scanf("%d",&numbersAra[i]);
        }

        int ans = -2147483600;

        for(int i=0;i<sz;i++){
            int sum = 0;
            for(int j= i;j<sz;j++){
                sum+=numbersAra[j];
                if(sum>ans) ans = sum;
            }
        }

        if(ans<=0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",ans);



    }//input
}
