### 快速定位

[第二周——线性表的顺序表示](week2.cpp)

[第三周——线性表的链式表示](week3.cpp)

[第四周——循环链表、双向链表、线性表的应用、案例](week4.md)

### 本文档前言

+ 默认C++11，但**不会**使用高级特性，大部分语法和C语言兼容
+ 只会给出代码，部分会有注释

---

关于C++，需要注意以下几个和C语言不一样的点：



不用 ```#include<stdbool.h>``` 就可以使用 ```bool```



C++中，目前可以认为 ```#include<example.h>``` 和 ```#include<cexample>``` 无差别，例如

```cpp
#include<cstdio>
#include<stdio.h>

#include<cmath>
#include<math.h>

#include<cstdlib>
#include<stdlib.h>
```





关于 ```struct```

```cpp
struct exampleName{
    int x,y;
}a;//a是一个exampleName型变量

exampleName b;//直接当一个变量类型即可，不用再typedef了
b.x = 5;
```



关于 ```new``` 和 ```delete``` 

```cpp
int *p = new int;//new一个int类型的指针
int *arr = new int[100];//new一个大小100的int数组， *arr 可以认为等同于 arr[0]

delete p;//释放单个内存
delete[] arr;//释放数组内存
```



关于引用符号 ```&``` ，可以这么看：

```cpp
//没有引用符号
#include<stdio.h>
void f(int num){
    num = 5;
}
int main(){
    int x = 1;
    f(5);
    printf("%d",x);// 输出1
    return 0;
}
```

```cpp
//有引用符号
#include<stdio.h>
void f(int &num){
    num = 5;
}
int main(){
    int x = 1;
    f(5);
    printf("%d",x);// 输出5
    return 0;
}
```

加了引用符号之后，函数体内修改参数，函数体外对应的变量的值也会修改

---

对于每个数据结构，我们实现以下函数：

+ 初始化

+ 销毁

+ 清空

+ 判断是否为空

+ 获取元素个数

+ 获取某个位置的元素

+ 定位元素

+ 求某个元素的前驱

+ 求某个元素的后缀

+ 插入元素

+ 删除某个元素

+ 遍历某个元素
