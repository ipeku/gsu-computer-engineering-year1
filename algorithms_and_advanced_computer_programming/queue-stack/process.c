//
//  process.c
//
//

#include "process.h"
#include <assert.h>

//kuyruğun sonuna eleman ekleme
void enqueue(struct process_queue** head, struct process proc) {

    struct process_queue* node_new;
    node_new = (struct process_queue*) malloc(sizeof(struct process_queue));

    node_new->process = proc;
    node_new->next = NULL;

    
    if (*head == NULL) 
        *head = node_new;

    else { 
    struct process_queue* node_last;
    node_last = *head;

    while (node_last->next != NULL) {
        node_last = node_last->next;
    }

    node_last->next = node_new;
    }
}
//kuyruğun başından eleman silme; process çekilip işlendikten sonra işlem süresi kalmadıysa.
void dequeue_and_pop(struct process_queue** head) {
    if (*head == NULL)
        return;

    struct process* temporary = *head;
    *head = (*head)->next;
    free(temporary);   
}


//kuyruğun başına eleman ekleme
void push(struct process_queue** top, struct process proc) {

    struct process_queue* node_new;
    node_new = (struct process_queue*) malloc(sizeof(struct process_queue));

    node_new->process = proc;
    node_new->next = *top;
    *top = node_new;
}


//kuyruğun başındaki elemanı çekme; free işlemi yok
struct process_queue* peek(struct process_queue* head) {
    if(head == NULL) 
        return NULL;
    
    else 
        return &(head->process);
    
}



int is_empty(struct process_queue* head) {
    
    if (head == NULL) 
        return 0;
    
    else 
        return 1;
    
}

//kuyruğun başındaki elemanı sona atma; standart process çekilip işlendikten sonra süresi kaldıysa.
void round_queue(struct process_queue** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct process_queue* current = *head;
    struct process_queue* previous = NULL;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = *head;
    *head = (*head)->next;
    current->next->next = NULL;

}

void print_queue(struct process_queue* head) {
    if(head == NULL) {
        printf("Process Queue is empty \n");
    }
    while(head != NULL) {
        printf("Process PID: %d -> ", head->process.PID);
        head = head->next;
    }
    printf("NULL \n");
}
