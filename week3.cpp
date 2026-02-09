#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef char elemType;

/*
视频里的代码是C语言的
typedef struct Lnode{
    elemType data;
    struct Lnode *next;
}Lnode,*LinkList;

等价于
struct Lnode{
    elemType data;
    struct Lnode *next;
};
typedef struct Lnode Lnode;
typedef Lnode* LinkList;

视频里写法， LinkList等同于Lnode* ，是语法规定
*/

//和视频里等价的C++写法
struct lNode{
    elemType data;
    lNode *next;
};
typedef lNode* linkList;
/*
也许更容易接受的C++写法

using linkList = lNode*;
*/

// 约定 linkList 存链表， lNode* 存指针节点

status initList(linkList &l)//初始化
{
    l = new lNode;
    if(!l)
        return ERROR;
    l->next = NULL;
    return OK;
}
bool listEmpty(linkList l)//判断是否为空
{
    return l->next==NULL;
}
status destroyList(linkList &l)//销毁链表
{
    lNode *p;
    while(l != NULL)
    {
        p = l;
        l = l->next;
        delete p;
    }
    return OK;
}

//清空链表   头指针依然存在
status clearListTeacher(linkList &l)// 视频里做法
{
    /*
        L——>a——>b——>c——>d...——>NULL
            P
        
        L——>a——>b——>c——>d...——>NULL
            P   Q
        
        (一个循环结束后)
        L——>野指针
                b——>c——>d...——>NULL
                Q
                P

        L——>野指针
                b——>c——>d...——>NULL
                P   Q
        
        ......

        L——>野指针
                NULL
                Q
                P
        
        L——>NULL
    */
    lNode *p,*q;
    p = l->next;
    while(p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    l->next = NULL;
    return OK;
}
status clearList(linkList &l)// 也许更优雅的做法
{
    /*
        L——>a——>b——>c——>d...——>NULL
            p

          -->-
         /    \
        L  a——>b——>c——>d...——>NULL
           p
        
        L——>b——>c——>d...

        ......

        最后剩下NULL，不用额外处理
        L——>NULL
    */
    if(l == NULL)
        return ERROR;
    lNode *p;
    while(l->next != NULL)
    {
        p = l->next;
        l->next = p->next;
        delete p;
    }
    return OK;
}
int linkLength(linkList l)//链表表长
{
    int cnt = 0;
    for(lNode *p=l->next; p!=NULL; p=p->next)
        cnt++;
    return cnt;
}

status getElem(linkList l,int i,elemType &e)//获取第i个元素
{
    lNode *p = l->next;
    int j = 1;
    while(p!=NULL && j<i)
    {
        p = p->next;
        j++;
    }
    if(p==NULL || j>i)
        return ERROR;
    e = p->data;
    return OK;
}
lNode* locateElemPos(linkList l,elemType e)//按元素查找，返回指针
{
    lNode *p = l->next;
    while(p!=NULL && p->data!=e)
        p = p->next;
    return p;//没找到就返回NULL
}
int locateElemIth(linkList l,elemType e)//按元素查找，返回第几个
{
    lNode *p = l->next;
    int i = 1;
    while(p!=NULL && p->data!=e)
    {
        i++;
        p = p->next;
    }
    if(p != NULL)
        return i;
    return 0;
}
status listInsert(linkList &l,int i,elemType e)//第i个节点前插入e
{
    lNode *p = l;
    int j = 0;
    /*
        j==i-2  (j<i-1)==true
        j==i-1   第(i-1)个节点
    */
    while(p!=NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p==NULL || i<=0)
        return ERROR;
    /*
       i-1     i
        p ——>  a
                        s

        p ——>  a
        s -->-/

        p      a
        |      ^
        v      |
        s -->--|

        p ——> s ——> a
    */
    lNode *s = new lNode;
    s->data = e;

    s->next = p->next;
    p->next = s;

    return OK;
}
status deleteIthList(linkList &l,int i,elemType &e)//删除第i个元素
{
    int j = 0;
    lNode *p = l;
    while(p->next!=NULL &&j<i-1)
    {
        j++;
        p = p->next;
    }
    if(p->next==NULL || j>i-1)
        return ERROR;
    lNode *q = p->next;//第i个
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

void createListHead(linkList &l,int n)//头插法
{
    l = new lNode;
    l->next = NULL;
    for(int i=n; i>=1; i--)
    {
        lNode *p = new lNode;
        std::cin >> p->data;//c++输入p->data

        p->next = l->next;
        l->next = p;
    }
}
void createListTail(linkList &l,int n)//尾插法建立单链表
{
    l = new lNode;
    l->next = NULL;
    lNode *tp = l;//tail pointer
    for(int i=0; i<n; i++)
    {
        lNode *p = new lNode;
        std::cin >> p->data;
        p->next = NULL;

        tp->next = p;

        tp = p;
    }
}

int main()
{
    
    return 0;
}