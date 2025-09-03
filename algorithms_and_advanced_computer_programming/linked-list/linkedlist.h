//
//  linkedlist.h
//  linkedlist
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <stdlib.h>

// singly linked list;

struct node {
    int data;
    struct node* next;
};

void insert_element(struct node**, int);
void remove_element(struct node**, int);

int search_element(struct node* head, int data);
int get_length(struct node*);

void reverse(struct node**);
void print(struct node*);

#endif /* linkedlist_h */
//