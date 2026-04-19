#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode *next; //指针域
}LNode,*LinkList;
int Insert_L(LinkList &L)
{//将新图书入库并输出
int m;
    cin >> m;
    
    Book newBook;
    cin >> newBook.no >> newBook.name >> newBook.price;
    
    // 检查插入位置合法性
    if (m < 1 || m > L->length + 1) {
        cout << "Sorry，the position to be inserted is invalid!" << endl;
        return ERROR;
    }
    
    // 找到待插入位置的前驱结点
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < m - 1) {
        p = p->next;
        j++;
    }
    
    // 创建新结点
    LNode *s = new LNode;
    s->data = newBook;
    s->next = p->next;
    p->next = s;
    
    // 更新链表长度
    L->length++;
    
    // 输出所有图书信息
    p = L->next;
    while (p != NULL) {
        cout << p->data.no << " "
             << p->data.name << " "
             << fixed << setprecision(2) << p->data.price << endl;
        p = p->next;
    }
    
    return OK;
}
