#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
	int item;
	struct _listnode *next;
    struct _listnode *prev;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

void printList (LinkedList *ll) {
    ListNode *temp = ll->head;
    while (temp != NULL) {
        printf("%c", temp->item);
        temp = temp->next;
    }
    printf("\n");
}


ListNode * findNode (LinkedList *ll, int index) {
    ListNode *temp;
    
    if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;
    temp = ll->head;
    if (temp == NULL) return NULL;
    
    while (index > 0) {
        temp = temp -> next;
        if (temp == NULL) return NULL;
        index--;
    }
    return temp;
}

int insertNode (LinkedList *ll, int index, int item) {
    /* put new node AFTER node[index]
    // 1-based node index
    // insert at front: put index = 0*/
    ListNode *pre, *cur, *next;
    
    
    /* If empty list or inserting first node, need to update head pointer*/
    if (index == 0 || ll->head == NULL) {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        if (ll->size == 0)
            ll->tail = ll->head;
        ll->head->item = item;
        ll->head->next = cur;
        /*ll->head->next->prev = ll->head;*/
        ll->size++;
        return 0;
    }
    if (index == ll->size) {
        cur = ll->tail;
        next = cur->next;
        cur->next = malloc(sizeof(ListNode));
        ll->tail = cur->next;
        cur->next->item = item;
        cur->next->next = next;
        /*cur->next->prev = cur;*/
        
        ll->size++;
        return 0;
    }
    if ((pre = findNode(ll, index - 1)) != NULL) {
        next = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = item;
        pre->next->next = next;
        /*pre->next->next->prev = pre->next;
        pre->next->prev = pre;*/
        
        ll->size++;
        return 0;
    }
    return -1;
}

/*
int insertNode(LinkedList *ll, int index, int value){
	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));

		if (ll->size == 0)
			ll->tail = ll->head;

		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as new last node
	if (index == ll->size){
		pre = ll->tail;
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		ll->tail = pre->next;
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}
*/
int removeNode(LinkedList *ll, int index) {
    ListNode *pre, *cur;
    /* Highest index we can remove is size-1*/
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	/* If removing first node, need to update head pointer*/
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	/* Find the nodes before and after the target position
	// Free the target node and reconnect the links*/
	if ((pre = findNode(ll, index - 1)) != NULL){
		/* Removing the last node, update the tail pointer*/
		if (index == ll->size - 1){
			ll->tail = pre;
			free(pre->next);
			pre->next = NULL;
		} else {
			cur = pre->next->next;
			free(pre->next);
			pre->next = cur;
		}
		ll->size--;
		return 0;
	}

	return -1;
}

int main () {
    LinkedList ll;
    char st[100010];
    int i, point, home_point;
    ll.head = NULL;
    ll.size = 0;
    while(scanf("%s%*c", st) != EOF) {
        point = 1; /*1: end; -1: front*/
        /*printf("%s\n", st);*/
        i = 0;
        home_point = 0;
        while (st[i] != '\0') {
            /*printf("%c 1; ", st[i]);*/
            if (st[i] == '[') {
                point = -1;
                home_point = 0;
                i++;
                continue;
            }
            if (st[i] == ']') {
                point = 1;
                i++;
                continue;
            }
            /*printf("%c 2; ", st[i]);*/
            if (point > 0)
                insertNode(&ll, ll.size, st[i]);
            else
                insertNode(&ll, home_point++, st[i]);
            /*printf("%c 3; \n", st[i]);*/
            i++;
        }
        printList(&ll);
        while(ll.size > 0) {
            removeNode(&ll, 0);
        }
        /*printf("%s\n", st);*/
    }
    
    return 0;
}
