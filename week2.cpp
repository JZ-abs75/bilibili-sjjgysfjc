#include<cstdio>
#include<cstdlib>
#include<cmath>

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef char elemType;

const int MAXSIZE = 105;
struct sqList{
    elemType *elem;
    int length;
};

status initSqList(sqList &l)//初始化
{
    l.elem = new elemType[MAXSIZE];//动态分配
    if(!l.elem)
    {
        printf("无法分配内存");
        exit(OVERFLOW);
    }
    l.length = 0;
    return OK;
}

void destorySqList(sqList &l)//销毁
{
    if(l.elem)
        delete[] l.elem;
}
void clearSqList(sqList &l)//清空
{
    l.length = 0;
}
int getLength(sqList l)//元素个数
{
    return l.length;
}
bool isEmpty(sqList l)//是否为空
{
    return l.length==0;
}

status getElem(sqList l,int i,elemType &e)//获取元素
{
    if(i<1 || i>l.length)
        return ERROR;
    e = l.elem[i-1];
    return OK;
}
int locateElem(sqList l,elemType e)//定位元素
{
    for(int i=0; i<l.length; i++)
        if(l.elem[i] == e)
            return i+1;
    return 0;
}
status insertElem(sqList &l,int pos,elemType e)//插入元素
{
    /* 
        把原先第pos个元素和之后的往后挤
        1 <= pos <= n+1         pos为n+1时表示在最后插入
    */
    if(pos<1 || pos>l.length+1)
        return ERROR;
    if(l.length == MAXSIZE)//满了
        return ERROR;
    /*
        第多少个位置    1 2 3 ...  pos-1    pos     pos+1  ...   l.length
        对应数组下标    0 1 2 ...  pos-2   pos-1     pos   ...   l.length-1
    */
    for(int i=l.length-1; i>=pos-1; i--)
        l.elem[i+1] = l.elem[i];
    l.elem[pos-1] = e;
    l.length++;
    return OK;
}
status eraseElem(sqList &l,int pos)//删除第pos个元素
{
    if(pos<1 || pos>l.length)
        return ERROR;
    /*
        第多少个位置    1 2 3 ...  pos-1    pos     pos+1  ...   l.length
        对应数组下标    0 1 2 ...  pos-2   pos-1     pos   ...   l.length-1
    */
    for(int i=pos; i<l.length; i++)
        l.elem[i-1] = l.elem[i];
    l.length--;
    return OK;
}
int main()
{
    sqList l;
    initSqList(l);


    destorySqList(l);
    return 0;
}
