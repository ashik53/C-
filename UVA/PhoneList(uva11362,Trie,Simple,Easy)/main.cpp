#include<bits/stdc++.h>

using namespace std;

int numberOfWords;
char wordList[10007][20];

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
void insertWord(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
//search by recursive function
int searchWord(node *cur)
{

    if(cur->endmark){
        for(int i=0;i<10;i++){
            if(cur->next[i]) return true;
        }
        return false;
    }


    int retValue =false;
    for(int i=0;i<10;i++){
        if(cur->next[i]) {
            retValue = retValue|searchWord(cur->next[i]);
        }
    }

    return retValue;

}
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
        for(int i=0;i<numberOfWords;i++){
            scanf("%s",word);
            insertWord(word,strlen(word));
            strcpy(wordList[i],word);
        }

        /*find the phone list is consistent or not
        I will use a recursive function */
        int ans = searchWord(root);

        if(!ans) printf("YES\n");
        else printf("NO\n");

        //destroy the trie
        del(root);
    }//all cases
}
