#include <bits/stdc++.h>
using namespace std;

struct node {
    bool endmark;
    int cnt;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        cnt = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void insertString(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt = curr->cnt+1;
    }
    curr->endmark = true;
}
int countWords(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        curr = curr->next[id];
        if(curr==NULL) return 0;
    }
    return curr->cnt;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
int main()
{

    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        scanf("%s", str);
        insertString(str, strlen(str));
    }
    puts("ENTER NUMBER OF QUERY");
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        scanf("%s", str);
        cout<< countWords(str,strlen(str))<<endl;

    }
    del(root); //ট্রাইটা ধ্বংস করে দিলাম
    return 0;
}
