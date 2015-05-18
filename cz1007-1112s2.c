#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _listnode {
    void * item;
    struct _listnode *next;
} ListNode;




///// From lab 9
void printList(ListNode *head){ 
	if (head == NULL) 
		return; 
	while (head != NULL){ 
		printf("%s ", head->item); 
		head = head->next; 
	} 
	printf("\n"); 
}

ListNode *findNode(ListNode *head, int index){ 
	if (head == NULL || index < 0) 
		return NULL; 
	while (index > 0){ 
		head = head->next; 
		if (head == NULL) 
			return NULL; 
		index--; 
	} 
	return head; 
}
int insertNode(ListNode **ptrHead, int index, void * value){ 
	ListNode *pre, *cur; 
    //printf("%s ", value);
	// If empty list or inserting first node, need to update head pointer 
	if (*ptrHead== NULL || index == 0){ 
		cur = *ptrHead; 
		*ptrHead = malloc(sizeof(ListNode)); 
        //(*ptrHead)->item = value;
        (*ptrHead)->item = malloc(sizeof(value));
		strcpy((*ptrHead)->item, value); 
		(*ptrHead)->next = cur; 
		return 0; 
	} 
	// Find the nodes before and at the target position 
	// Create a new node and reconnect the links 
	if ((pre = findNode(*ptrHead, index-1)) != NULL){ 
		cur = pre->next; 
		pre->next = malloc(sizeof(ListNode)); 
		//pre->next->item = value; 
        pre->next->item = malloc(sizeof(value));
		strcpy(pre->next->item, value); 
		pre->next->next = cur; 
		return 0; 
	} 
	return -1; 
}

int removeNode(ListNode **ptrHead, int index) {
	ListNode *pre, *cur; 
	// remove the first node
	if (index == 0) {
		cur = *ptrHead;
		*ptrHead = (*ptrHead)->next;
		free(cur);
		return 0;
	}
	// remove else
	if ((pre = findNode(*ptrHead, index-1)) != NULL){ 
		cur = pre->next;
		pre->next = pre->next->next;
		// what if pre->next->next is null?
		free(cur);

		return 0;

	}
	return -1;
}

int main () {
    ListNode *head = NULL;
    int k = 0, i, p;
    char s[1000];
    printf("String as item\n");
    scanf("%s", s); 
    while (strcmp(s, "-1") != 0){
		insertNode(&head, k++, &s);
		scanf("%s", s); 
	}
    printList(head);
    
    
    printf("x:\n");
    scanf("%s", s);
    
    printf("p:\n");
    scanf("%d", &p);
    
    // findNode(s)
    // insert value of node s at p
    
    return 0;
}
