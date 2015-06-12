/* $Id: queue.c,v 1.34 2012-11-19 19:26:39-08 - - $ */
//NAME ALEX VINCENT

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

#define STUBPRINTF(...) fprintf (stderr, __VA_ARGS__);

//static char *queue_tag = "struct queue";
//static char *queuenode_tag = "struct queuenode";

typedef struct queue_node queue_node; //queue_node of type queue_node

struct queue_node {
   //char *tag;
   queue_item_t item; //contains generic item
   queue_node *link; //contains pointer to another node
};

struct queue {
   //char *tag;
   queue_node *front; //pointer to a front queue node
   queue_node *rear; //pointer to a rear queue node
};

queue *new_queue (void) { //function returns a pointer to a queue
   queue *new_q = malloc(sizeof(struct queue)); //creates a queue, stores a pointer to it in new_q
   assert(new_q!=NULL);
   new_q->front = NULL; //to where new_q is pointing, change the value at that address to be null
   new_q->rear = NULL;
   //new -> tag = queue_tag;
   return new_q; //return that pointer to the new queue.
}

void free_queue (queue *this) {
   //assert (is_queue (this));
   assert (isempty_queue (this));
   memset (this, 0, sizeof (struct queue));
   free (this);
}

void insert_queue (queue *this, queue_item_t item) {
   //assert (is_queue (this));
   queue_node *new = malloc(3*sizeof(struct queue_node));
   assert(new!=NULL);
   new->item = item;
   new->link = NULL;
   //new.tag = queuenode_tag;
   if(this->front==NULL){
     this->front = new;
     this->rear = new;
   }
   else
       this->rear->link = new;
       this->rear = new;
}

queue_item_t remove_queue (queue *this) {
   //assert (is_queue (this));
   assert (! isempty_queue (this));
   queue_item_t temp = this -> front -> item;
   queue_node *tnode = this -> front;
  // free(queue ->front);
   this -> front = this -> front -> link;
   free(tnode);
   return temp;
}

bool isempty_queue (queue *this) {
   //assert (is_queue (this));
   return this->front == NULL;
}

//bool is_queue (queue *this) {
   //return this!=NULL;//&& this->tag == queue_tag;
//}
