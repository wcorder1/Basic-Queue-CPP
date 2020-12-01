
#include "QueType.h"
#include <iostream>

using namespace std;


template <class ItemType>
QueType<ItemType>::QueType() {
  maxQue = 501;
  items = new ItemType[maxQue];
  front = 1;
  rear = 1;
}


template <class ItemType>
QueType<ItemType>::QueType(int max) {
  maxQue = max+1;
  items = new ItemType[maxQue];
  front = 1;
  rear = 1;
}


template <class ItemType>
QueType<ItemType>::~QueType() {
  delete [] items;
}


template <class ItemType>
void QueType<ItemType>::makeEmpty() {
  front = 1;
  rear = 1;
}


template <class ItemType>
bool QueType<ItemType>::isEmpty() const {
  return bool(front == rear);
}


template <class ItemType>
bool QueType<ItemType>::isFull() const {
  return bool(rear == front-1);
}


/* rear is set equal to the new item and if
rear equals the max number of items then rear
will be set to 0 */
template <class ItemType>
void QueType<ItemType>::enqueue(ItemType newItem) {
  if (isFull()) {
    throw QueueOverflow();
  } else {
    items[rear] = newItem;
    rear = ((rear+1)%maxQue);
  }
}


template <class ItemType>
void QueType<ItemType>::dequeue(ItemType& item) {
  if (isEmpty()) {
    throw QueueUnderflow();
  } else {
    ItemType temp = items[front];
    front = ((front+1)%maxQue);
    item = temp;
  }
}


template <class ItemType>
ItemType QueType<ItemType>::peek() {
  if (isEmpty()) {
    throw QueueUnderflow();
  }
  else {
    return items[front];
  }
}


template <class ItemType>
int QueType<ItemType>::length() {
  int i = front;
  int j = 0;
  while (i != rear) {
    i = ((i+1)%maxQue);
    j++;
  }
  return j;
}


template <class ItemType>
void QueType<ItemType>::printQueue(ofstream& outFile) {
  if (isEmpty()) {
    outFile << "Queue is empty" << endl;
  } else {
    int i = front;
    while (i != rear) {
      outFile << items[i] << "  ";
      i = ((i+1)%maxQue);
    }
    outFile << endl;
  }
}
