#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
using namespace std;

class Customer
{
private:
    long arrive;
    int processtime;

public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    enum
    {
        Q_SIZE = 10
    };
    struct Node
    {
        Item item;
        struct Node *next;
    };
    Node *front;
    Node *rear;
    int items;
    const int qsize;

public:
    Queue(int qs = Q_SIZE); //构造函数，设置队列最大值
    ~Queue();
    bool isempty() const;           //判断队列是否为空
    bool isfull() const;            //判断队列是否为满
    int queuecount() const;         //队列中个数
    bool enqueue(const Item &item); //进队列
    bool dequeue(Item &item);       //出队列
};

#endif