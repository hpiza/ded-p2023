#ifndef QUEUE_H_
#define QUEUE_H_

typedef void* Type;
typedef enum {FALSE, TRUE} Bool;
typedef struct strQueue* Queue;

Queue queue_create();
int queue_size(Queue);
Bool queue_isEmpty(Queue);
void queue_offer(Queue, Type);
Type queue_poll(Queue);
Type queue_peek(Queue);
void queue_destroy(Queue);

#endif
