#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int roll;
    node *next;
};

typedef struct Node {
    bool endmark;
    Node* next[26 + 1];
    Node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} ;
int main()
{
    Node  *root = NULL;




}
