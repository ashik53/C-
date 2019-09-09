    #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;
    #define mx 100001
    struct lazyInfo{
       int propagationValue,sum;

    }segmentTree[mx*3];
    int ara[mx];


    void buildTree(int node,int be,int en){
        if(be==en){
            segmentTree[node].sum = ara[be];
            return;
        }
        int Left = node*2;
        int Right = (node*2)+1;
        int mid = (be+en)/2;

        buildTree(Left,be,mid);
        buildTree(Right,mid+1,en);

        segmentTree[node].sum = segmentTree[Left].sum + segmentTree[Right].sum;


    }
    void updateTree(int node,int be,int en,int i,int j,int newValue){

       if(i>en || j<be) return;
       if(be>=i && en<=j){
           segmentTree[node].sum += ((en-be+1)*newValue);
           segmentTree[node].propagationValue +=newValue;
           return;
       }
        int Left = node*2;
        int Right = (node*2)+1;
        int mid = (be+en)/2;
      //  cout<<"node-left -  "<<Left <<" niye call\n";
        updateTree(Left,be,mid,i,j,newValue);
       // cout<<"node- right "<<Right <<" niye call\n";
        updateTree(Right,mid+1,en,i,j,newValue);

        segmentTree[node].sum = segmentTree[Left].sum + segmentTree[Right].sum + ((en - be + 1) *segmentTree[node].propagationValue);

    }
    int query(int node,int be,int en,int i,int j,int carry = 0){

        if(i>en || j<be){
            return 0;
        }
        if(be>=i && en<=j){
            return segmentTree[node].sum + (carry*(en-be+1));
        }

        int Left = node*2;
        int Right = (node*2) +1;
        int mid = (be+en)/2;
         // cout<<"node-left -  "<<Left <<" niye call\n";
        int p1 =  query(Left,be,mid,i,j,carry + segmentTree[node].propagationValue) ;
        // cout<<"node- right "<<Right <<" niye call\n";
        int p2 = query(Right,mid+1,en,i,j,carry+segmentTree[node].propagationValue);

        return p1+p2;

    }


    int main()
    {
        int sz,updateSize,low,high,newValue,querySize;

       while(1){
         scanf("%d%d%d",&sz,&updateSize,&querySize);
         memset(&segmentTree,0,sizeof(segmentTree));
         for(int i=0;i<sz;i++){
             scanf("%d",&ara[i]);
         }

         buildTree(1,0,sz-1);
         for(int i=0;i<updateSize;i++){
           //  cout<<"i = "<< i <<endl;
             scanf("%d%d%d",&low,&high,&newValue);
             updateTree(1,0,sz-1,low-1,high-1,newValue);
         }
        //cout<<"update ends here\n";
        for(int i=0;i<querySize;i++){
            scanf("%d%d",&low,&high);
            int ans = query(1,0,sz-1,low-1,high-1,0);
            printf("%d\n",ans);
        }
        //cout<< "query ends\n";
       }//cases
    }//main function
