#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Quexetor.h"

using namespace std;

struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity){
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;

  queue->rear = capacity - 1;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));

  return queue;
}


// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue){
  return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue){
  return(queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item) {
  if(isFull(queue)) return;
  queue->rear = (queue->rear + 1) % queue->capacity;

  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;

  cout << "enqueued to queue" << item << endl;
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue){
  if(isEmpty(queue)) return INT_MIN;
  int item = queue->array[queue->front];

  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

int front(struct Queue* queue){
  if(isEmpty(queue)) return INT_MIN;

  return queue->array[queue->front];
}

int rear(struct Queue* queue){
  if(isEmpty(queue)) return INT_MIN;

  return queue->array[queue->rear];
}