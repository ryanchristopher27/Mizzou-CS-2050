//JAMES ALSPAW
//APRIL 8TH, 2020

//HEADERS///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

//NODES AND LIST////////////////////////////////////////////////////////////////
typedef struct statestruct{
    float populationInMillion;
    struct statestruct *nextState;
}State;

typedef struct Qinfo{
    int size;
    State *head;
    State *tail;
}Qinfo;

typedef struct Qstruct{
    Qinfo *qPtr;
}Queue;

//FUNCTION PROTOTYPES///////////////////////////////////////////////////////////
Queue initQueue();//Initialize Queue and returns it empty => O(1)
int enQueue(State*,Queue);//adds node to end of Queue => O(1)
State* deQueue(Queue);//removes node from beginning of Queue => O(1)
int getQsize(Queue);//returns size of queue => O(1)
void printList(Queue);//prints Queue => O(n)
void freeQueue(Queue);//frees all allocated memory => O(n)
int randInt();

//MAIN//////////////////////////////////////////////////////////////////////////
int main(void){
  Queue test;
  test = initQueue();
  State* a = NULL;
  enQueue(a,test);
  printList(test);
  enQueue(a,test);
  printList(test);
  deQueue(test);
  enQueue(a,test);
  printList(test);
  deQueue(test);
  enQueue(a,test);
  printList(test);
  enQueue(a,test);
  printList(test);
  deQueue(test);
  enQueue(a,test);
  printList(test);
  enQueue(a,test);
  printList(test);
  enQueue(a,test);
  printList(test);
  deQueue(test);
  deQueue(test);
  deQueue(test);
  deQueue(test);

  printf("Queue:");
  printList(test);
  getQsize(test);
  freeQueue(test);


  return 0;
}

//FUNCTIONS/////////////////////////////////////////////////////////////////////
Queue initQueue(){
    Queue q;
    q.qPtr = malloc(sizeof(Qinfo));
    q.qPtr->size = 0;
    q.qPtr->head = q.qPtr->tail = NULL;
    return q;
}

int enQueue(State* e, Queue q){
  e = malloc(sizeof(State));
  if(e == NULL){
      printf("Error: Malloc Failed\n");
      return -1;
  }

  e->populationInMillion = randInt();
  e->nextState = NULL;

  if(q.qPtr->tail == NULL){
      q.qPtr->head = q.qPtr->tail = e;
      q.qPtr->size++;
  }
  else{
      q.qPtr->tail->nextState = e;
      q.qPtr->tail = e;
      q.qPtr->size++;
  }
  return 1;
}

State* deQueue(Queue q){
  State* e = q.qPtr->head;
  q.qPtr->head = e->nextState;
  printf(" %.2f was deQueued\n", e->populationInMillion);
  q.qPtr->size--;
  return e;
}

int getQsize(Queue q){
  printf("\nSize is: %d", q.qPtr->size);
  return q.qPtr->size;
}

void printList(Queue q) {
  State* temp = q.qPtr->head;
  while (temp != NULL){
  printf("[%.2f] ", temp->populationInMillion);
  temp = temp->nextState;
  }
  printf("\n");
}

void freeQueue(Queue q){
  State* temp = q.qPtr->head;
  int i = 0;
  while(temp != NULL){
      State *new_head = temp->nextState;
      i++;
      free(temp);
      temp = new_head;
  }
  free(q.qPtr);
  printf("\nFreed %d times\n", i);
}

int randInt(){
    return (rand()%(10-1+1)+1);
}
////////////////////////////////////////////////////////////////////////////////
