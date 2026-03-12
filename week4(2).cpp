/*
双向链表
*/
#include<cstdio>
#include<iostream>
#define OK 1
#define ERROR 0
typedef int status;
typedef char elemType;
struct duLNode{
    elemType data;
    duLNode *prior, *next;
};
typedef duLNode* duLinkList;
status initDuList(duLinkList &L){
    L = new duLNode;
    L->next = NULL;
    L->prior = NULL;
    return OK;
}
// 头插法
status createDuListHead(duLinkList &L, int n){
    for(int i = 0; i < n; i++)
    {
        duLNode *p = new duLNode;
        std::cin >> p->data;
        if(L->next)
            L->next->prior = p;
        p->next = L->next;
        p->prior = L;
        L->next = p;
    }
    return OK;
}
// 找到第 i 个
duLNode* getElemP_Dul(duLinkList &L, int i){
    if(!L || i < 1)
        return NULL;
    duLNode *p = L->next;
    int cnt = 1;
    while(p)
    {
        if(cnt == i)
            return p;
        cnt++;
        p = p->next;
    }
    return NULL;
}
// 第 i 个节点之前插入
status listInsert_Dul(duLinkList &L, int i, elemType e){
    /*
    begin
                   p
            a ---> b
            \      /
             --<---
             s
    
    s->prior = p->prior 
                  p
         --a ---> b
        /  \      /
        |   --<---
        ^  
        |  
         \--s     
         
    p->prior->next = s 
                      p   
         ->--a        b   
        /   / \      /    
        |   |  --<---     
        ^   v           
        |   |           
         \--s 
         
        s->next = p
                      p   
         ->--a        b   
        /   / \      / \  
        |   |  --<---  |   
        ^   v          | 
        |   |          |  
         \--s---->----/ 
         
        p->prior = s 
                      p   
         ->--a        b   
        /   /        / \  
        |   |       /  |   
        ^   v  --<--   | 
        |   | /        |  
         \--s---->----/ 
         
    */
    duLNode *p = getElemP_Dul(L, i);
    if(!p)
        return ERROR;
    duLNode *s = new duLNode;
    s->data = e;
    
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior =s;
    return OK;
}
status listDelete_Dul(duLinkList &L, int i, elemType &e){
    /*
        视频里的是双向循环链表，这里的是不循环的双向链表
        
        begin
                  p
        a---->----b---->----c
        \        / \       /
         ----<---   ---<---
        
        p->prior->next = p->next
         --------->--------
        /         p        \
        a         b---->----c
        \        / \       /
         ----<---   ---<---

        p->next->prior = p->prior
         --------->--------
        /         p        \
        a         b---->----c
      / \        /          |
      \  ----<---          /
       -----------<--------

       delete p
        --------->--------
        /                  \
        a                   c
      /                     |
      \                     /
       -----------<--------
    */
    duLNode *p = getElemP_Dul(L, i);
    if(!p)
        return ERROR;
    e = p->data;
    p->prior->next = p->next;
    if(p->next)// p->next不能是空指针
        p->next->prior = p->prior;
    delete p;    
    return OK;    
}
int main(){
    
}
