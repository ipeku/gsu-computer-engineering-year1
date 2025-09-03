//
//  process.h
//  queue_cpu_scheduling
//
//  Created by timoteosonurozcelik on 14/04/2023.
//

#ifndef process_h
#define process_h

#include <stdio.h>
#include <stdlib.h>

struct process {
    int PID;
    int dur;
    int is_interrupt;
};

struct process_queue {
    struct process process;
    struct process_queue *next;
};

void enqueue(struct process_queue**, struct process);
void dequeue_and_pop(struct process_queue**);

void push(struct process_queue**, struct process);

struct process_queue* peek(struct process_queue*);
void round_queue(struct process_queue** head);

int is_empty(struct process_queue*);
int get_size(struct process_queue*);

void print_queue(struct process_queue*);

#endif /* process_h */
