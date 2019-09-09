#include<bits/stdc++.h>

using namespace std;

int numberOfWords;
char wordList[10007][20];
bool ans;
struct node {
    bool endmark;
    node* next[10 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} * root;

//this function will work as an output

void insertWord(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];

        //now I will check that if there is already a gray node(endMark=true) here and must before the last node
        if(ans==true && i!=len-1 && curr->endmark==true){
            ans = false;
        }
    }
    curr->endmark = true;

    //I will set another check after the last node
    for(int i=0;i<10;i++){
        if(curr->next[i]!=NULL){
            ans = false;
            break;
        }
    }//for




}//void insertWord(char* str, int len)


void del(node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
int main()
{
    int cases;
    char word[20];

    scanf("%d",&cases);
    for(int line = 0;line<cases;line++){

        root = new node();

        scanf("%d",&numberOfWords);
        getchar();

        //input the words
        ans = true; //find the phone list is consistent or not
        for(int i=0;i<numberOfWords;i++){
            scanf("%s",word);
            insertWord(word,strlen(word));
        }

        if(ans) printf("YES\n");
        else printf("NO\n");

        //destroy the trie
        del(root);
    }//all cases
}
