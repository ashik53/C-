#include<bits/stdc++.h>

using namespace std;
 struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

int main()
{


     root  = new node();

}

