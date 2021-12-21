#ifndef ITEM_QUEUE_
#define ITEM_QUEUE_
#include<iostream>
#include <memory>

using namespace std;
template <class ItemType>
class ItemQueue
{
private:
   unique_ptr<ItemType[]> queueArray;
   int queueSize;
   int front;
   int rear;
   int numItems;
public:
   ItemQueue(int); 
   void enqueue(ItemType);
   void dequeue(ItemType &);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
   void display();
};
#include "ItemQueue.cpp"
#endif
