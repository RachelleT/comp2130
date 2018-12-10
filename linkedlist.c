#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

void printlist(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int main()
{
	node_t * numlist = malloc(sizeof(node_t));
    	numlist->val = 1;
    	numlist->next = malloc(sizeof(node_t));
    	numlist->next->val = 2;
    	numlist->next->next = malloc(sizeof(node_t));
    	numlist->next->next->val = 3;
    	numlist->next->next->next = NULL;
    	
    	//printlist(numlist);
    	push(&numlist, 4);
    	pop(&numlist);
    	printlist(numlist);
}
