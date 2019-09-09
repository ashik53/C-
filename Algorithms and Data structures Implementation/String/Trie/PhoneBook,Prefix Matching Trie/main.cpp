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

void printAllWords(node* cur,vector<char>str){

    if(cur->endmark){
        for(unsigned int i=0;i<str.size();i++){
            cout<< str[i];
        }
        cout<<endl;
    }
    for(int i=0;i<27;i++){
        if (cur->next[i]){
            char ch = i+((int)'a');
            str.push_back(ch);
            printAllWords(cur->next[i],str);

            str.pop_back(); // যা এক্সট্রা  char ভেক্টরে ঢুকবে তাই ডিলিট হয়ে যাবে

        }
    }




}

void insertString(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        //cout<< id <<"\n";
        if (curr->next[id] == NULL){
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}
void searchString(vector<char>str, int len)
{
    node* curr = root;

    bool found = true;

    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL){
            found = false;
            break;
        }
        curr = curr->next[id];
    }

    if(found){
        printAllWords(curr,str);
    }else{
        cout<< "No string matched\n";
    }
}

//print all word matched by prefix in the dictionary



void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main(void){
    root = new node();

    char str[100];
    int numberOfWords,numberOfQuery;

    scanf("%d%d",&numberOfWords,&numberOfQuery);
    getchar();
    for(int i=0;i<numberOfWords;i++){
        scanf("%s",str);
        insertString(str,strlen(str));
    }

    for(int i=0;i<numberOfQuery;i++){
        scanf("%s",str);
        vector<char>result;
        for(int i=0;i<strlen(str);i++) result.push_back(str[i]);

        searchString(result,strlen(str));

    }//queries */
}
