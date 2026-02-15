#include<cstdio>
#include<iostream>

#define OK 1
#define ERROR 0

typedef int status;
typedef char elemType;

struct lNode{
    elemType data;
    lNode *next;
};
typedef lNode* linkList;

/*
循环链表和单链表大部分相同，
涉及遍历时的判断条件要改成   p != 头指针
*/

status initList(linkList &L);//初始化
bool listEmpty(linkList L);//是否为空
status destroyList(linkList &L);//销毁
status clearList(linkList &L);//清空
int linkLength(linkList L);//链表表长
status getElem(linkList L,int i,elemType &e);//获取第i个元素
lNode* locateElemPos(linkList L,elemType e);//按元素查找，返回指针
int locateElemIth(linkList L,elemType e);//按元素查找，返回第几个
status listInsert(linkList &L,int i,elemType e);//第i个节点前插入e
status deleteIthList(linkList &L,int i,elemType &e);//删除第i个元素
void createListHead(linkList &L,int n);//头插法
void createListTail(linkList &L,int n);//尾插法建立单链表

//以上函数基本都复制 粘贴 修改自单链表


status mergeList(linkList Ta,linkList Tb,linkList &T)
{
    if(!Ta || !Tb)
        return ERROR;
    if(Ta == Tb)
        return ERROR;
    
    lNode *p = Ta->next;
    Ta->next = Tb->next->next;
    delete Tb->next;
    Tb->next = p;
    T = Tb;//新表尾指针
    return OK;
    /*
    begin
         ——————————<—————————             ——————————<—————————
        /                    \           /                    \
        l——>a1——>a2——>... ——>an          l——>b1——>b2——>... ——>bn
                             Ta                               Tb


    p = Ta->next
         ——————————<—————————             ——————————<—————————
        /                    \           /                    \
        l——>a1——>a2——>... ——>an          l——>b1——>b2——>... ——>bn
        p                    Ta                               Tb


    Ta->next = Tb->next->next
                                          ——————————<—————————
                                         /                    \
        l——>a1——>a2——>... ——>an          l——>b1——>b2——>... ——>bn
        p                    Ta              /                Tb
                              \——————>——————/

    
    delete Tb->next
        l——>a1——>a2——>... ——>an              b1——>b2——>... ——>bn——>野指针
        p                    Ta              /                Tb
                              \——————>——————/


    Tb->next = p
         ————————————————————<—————————————————————
        /                                          \
        l——>a1——>a2——>... ——>an——>b1——>b2——>... ——>bn
        p                                          Tb
    */
}
int main(){

}
status initList(linkList &L)
{
    L = new lNode;
    L->next = L;
    return OK;
}
bool listEmpty(linkList L)//是否为空
{
    return L==L->next;
}
status destroyList(linkList &L)//销毁
{
    if(!L)
        return ERROR;
    lNode *p = L->next,*q;
    while(p != L)
    {
        q = p;
        p = p->next;
        delete q;
    }
    delete L;
    L = NULL;
    return OK;
}
status clearList(linkList &L)//清空
{
    if(!L)
        return ERROR;
    lNode *p;
    while(L->next != L)
    {
        p = L->next;
        L->next = p->next;
        delete p;
    }
    return OK;
}
int linkLength(linkList L)//链表表长
{
    int cnt = 0;
    for(lNode *p=L->next; p!=L; p=p->next)
        cnt++;
    return cnt;
}
status getElem(linkList L,int i,elemType &e)//获取第i个元素
{
    if(i < 1)
        return ERROR;
    lNode *p = L->next;
    int j = 1;
    while(p!=L && j<i)
    {
        p = p->next;
        j++;
    }
    if(p==L || j>i)
        return ERROR;
    e = p->data;
    return OK;
}
lNode* locateElemPos(linkList L,elemType e)//按元素查找，返回指针
{
    lNode *p = L->next;
    while(p!=L && p->data!=e)
        p = p->next;
    return p;//没找到就返回L
}
int locateElemIth(linkList L,elemType e)//按元素查找，返回第几个
{
    lNode *p = L->next;
    int i = 1;
    while(p!=L && p->data!=e)
    {
        i++;
        p = p->next;
    }
    if(p != L)
        return i;
    return 0;
}
status listInsert(linkList &L,int i,elemType e)//第i个节点前插入e
{
    if(!L || i<0 || i>linkLength(L)+1)
        return ERROR;
    lNode *p = L;
    int j = 0;
    while(p->next!=L && j<i-1)
    {
        p = p->next;
        j++;
    }
    lNode *s = new lNode;
    s->data = e;

    s->next = p->next;
    p->next = s;

    return OK;
}
status deleteIthList(linkList &L,int i,elemType &e)//删除第i个元素
{
    if(!L || i<1)
        return ERROR;
    int j = 0;
    lNode *p = L;
    while(p->next!=L &&j<i-1)
    {
        j++;
        p = p->next;
    }
    if(p->next==L || j>i-1)
        return ERROR;
    lNode *q = p->next;//第i个
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}
void createListHead(linkList &L,int n)//头插法
{
    L = new lNode;
    L->next = L;
    for(int i=n; i>=1; i--)
    {
        lNode *p = new lNode;
        std::cin >> p->data;//c++输入p->data

        p->next = L->next;
        L->next = p;
    }
}
void createListTail(linkList &L,int n)//尾插法建立链表
{
    L = new lNode;
    L->next = L;
    lNode *tp = L;//tail pointer
    for(int i=0; i<n; i++)
    {
        lNode *p = new lNode;
        std::cin >> p->data;
        p->next = L;
        tp->next = p;
        tp = p;
    }
}
