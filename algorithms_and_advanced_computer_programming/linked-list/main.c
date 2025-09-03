//
//  main.c
//  linkedlist
//
//  Created by timoteosonurozcelik on 31/03/2023.
//

#include <stdio.h>
#include "linkedlist.h"

int main(int argc, const char * argv[]) {
    int elements[] = {1, 5, 0, 3, 6};
    struct node* head = NULL;
    
    int i;
    for(i=0; i<5; i++) {
        insert_element(&head, elements[i]);
        print(head);
    }
    printf("\n");
    print(head);
    printf("\n");
    
    printf("Length of linked list: %d\n", get_length(head));
    
    int data = 5;
    printf("Index of element %d in linked list: %d\n", data, search_element(head, data));
    printf("\n");
    
    reverse(&head);
    printf("Reversed linked list\n");
    print(head);
    printf("\n");
    
    for(i=0; i<5; i++) {
        remove_element(&head, elements[i]);
        print(head);
    }
    
    return 0;
}
