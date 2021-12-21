#include <iostream>
#include "ItemQueue.h"
#include <cstdlib>

using namespace std;

template class ItemQueue<int>;
template class ItemQueue<float>;
template class ItemQueue<string>;


//*************************
// Constructor.           *
//*************************
template <class ItemType>
ItemQueue<ItemType>::ItemQueue(int s)
{
   queueArray = make_unique<ItemType[]>(s);
   queueSize = s;
   front = -1;
   rear = -1;
   numItems = 0;
}


//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class ItemType>
void ItemQueue<ItemType>::enqueue(ItemType num)
{
   if (isFull())
   {
      cout << "The queue is full.\n";
      exit(1);
   }
   else
   {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;      
      // Insert new item
      queueArray[rear] = num;      
      // Update item count
      numItems++;
   }
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <class ItemType>
void ItemQueue<ItemType>::dequeue(ItemType &num)
{
   if (isEmpty())
   {
      cout << "The queue is empty.\n";
      exit(1);
   }
   else
   {
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      num = queueArray[front];
      // Update item count		
      numItems--;
   }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class ItemType>
bool ItemQueue<ItemType>::isEmpty() const
{
   return numItems == 0;
}

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise.             *
//********************************************
template <class ItemType>
bool ItemQueue<ItemType>::isFull() const
{
   return numItems == queueSize;
}

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0.         *
//*******************************************
template <class ItemType>
void ItemQueue<ItemType>::clear()
{
   front = -1;
   rear = -1;
   numItems = 0;
}

//*******************************************
// Function that displays items in the       *
// queue.									 *
//*******************************************
template <class ItemType>
void ItemQueue<ItemType>::display(){
	for(int i=0; i < numItems; i++){
		cout<<" "<< queueArray[i]<<endl;
	}
	
}

