#include <stdio.h>
#include <stdlib.h>

struct trie{
    int flag;
    struct trie *childPtr[26];
};

int getStrLen(char *p)
{
    int count=0;
    while(*p != '\0'){
        count++;
        p++;
    }
    return count;
}

struct trie * allocateTrieNode()
{
    struct trie *newNode = (struct trie *)malloc(sizeof(struct trie));
    if(!newNode) return 0;
    newNode->flag = 0;
    for(int i=0;i<26;i++)
        newNode->childPtr[i] = NULL;
    return newNode;
}

int insertStr(struct trie *t, char *str)
{
    int length = getStrLen(str);
    int level = 0;
    int index = -1;
    for(;level<length;level++)
    {
        index = str[level] - 'a';
        if(!t->childPtr[index]){
            t->childPtr[index] = allocateTrieNode();
            if(!t->childPtr[index]) return 0;
        }
        t=t->childPtr[index];
    }
    t->flag = 1;
    return 1;
}


int searchStr(struct trie *t, char *str)
{
    int length = getStrLen(str);
    int level = 0;
    int index = -1;
    for(;level<length;level++)
    {
        index = str[level] - 'a';
        if(!t->childPtr[index])
            return 0;
        t=t->childPtr[index];
    }

    if(t && t->flag == 1)
        return 1;
    else
        return 0;
}


int main()
{
    struct trie *root = allocateTrieNode();
    char *strArr[5] = {"bats","bear","best","cat","car"};
    for(int i=0;i<5;i++)
        insertStr(root,strArr[i]);
    printf("Here\n");
    if(searchStr(root,"best"))
        printf("Found best\n");
    else
        printf("not found\n");
    if(searchStr(root,"bat"))
        printf("Found bat\n");
    else
        printf("not found\n");
    return 0;
}