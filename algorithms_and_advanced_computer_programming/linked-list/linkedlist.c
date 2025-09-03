//
//  linkedlist.c
//  linkedlist
//

#include "linkedlist.h"

/*struct node* insert(struct node* head, int data){
    struct node* cur = head;
    if(head==NULL){
        head=malloc(sizeof(struct node));
        head->data=data;
        return head;

} */
void insert_element(struct node** head, int data) {
    struct node* cur= (*head);
    if(cur==NULL){
        cur=malloc(sizeof(struct node));
        cur->data=data;
        *head=cur;
    } else{
        struct node* nxt=(*head)->next;
        struct node *tmp = malloc(sizeof(struct node));
        tmp->data=data;

        if(data<cur->data){
            tmp->next=cur;
            *head=tmp;
        } else{
            while(nxt!=NULL){
                if(data>=cur->data && data < nxt->data){
                    cur->next = tmp;
                    tmp->next = nxt;
                    return;
                }
                cur=nxt;
                nxt=nxt->next;
            }
            if (data>=cur->data){
                cur->next=tmp;
            }
        }

    }
}

void remove_element(struct node** head, int data) {
    struct node* cur=(*head);
    if(cur==NULL){
        printf("Linked list is empty!!!");
    }
    else {
        if(cur->data ==data){
            *head=cur->next;
            free(cur);
        }
        else{
            struct node* nxt=(*head)->next;
            while(nxt!=NULL){
                if(nxt->data == data){
                    cur->next = nxt->next;
                    free(nxt);
                    return;
        }   cur=nxt;
            nxt=nxt->next;
            }
            printf("Element %d could not be found", data);
        }

    }

}

int search_element(struct node* head, int data) {
    struct node* tmp= head;
    int index=0;
    while (tmp != NULL){
        if(tmp->data == data){
            return index;
        }
        tmp = tmp->next;
        index++;
        return -1;
    }}

//
int get_length(struct node* head) {
    int count = 0;
struct node* cur = head;
while (cur != NULL) {
count++;
cur = cur->next;
}
return count;

}

void reverse(struct node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    struct node* prev = NULL;
    struct node* cur = *head;
    struct node* nxt = NULL;

    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    *head = prev;
}


void print(struct node*head) {
    struct node* tmp = head;
    printf("Linked list: ");
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
