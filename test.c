/*
Author and Lab Group: KENRICK FSP1
Program name: FSP1_Kenrick.c
Date: 29 March 2014
Purpose: Implementing the required functions for Assignment 2
*/
#define _CRT_SECURE_NO_WARNINGS
// to enable scanf at Visual Studio Professional 2013

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

///// Basic LinkedList operations, from Prof Mark Yong
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

///// For CZ1007 Assignment 2
void createLinkedList(LinkedList *ll);
int insertSorted(LinkedList *ll, int value);
int removeDuplicates(LinkedList *ll);

////////////////////////////////////////////////////////////////////////////////

int main(){
	// initialize variables
	int choice = 0, item = 0, idx = 0;

	LinkedList l;
	l.head = 0;
	l.size = 0;

	// Print menu
	printf("1. createLinkedList\n");
	printf("2. insertSorted\n");
	printf("3. removeDuplicates\n");
	printf("4. exit\n");
	do {
		printf("Choose an option : ");
		scanf("%d", &choice);
		fflush(stdin);

		// Process choice
		switch (choice) {
		case 1: // Task 1: createLinkedList()
			createLinkedList(&l);
			break;
		case 2: // Task 2: insertSorted()

			// Input a number
			printf("Enter a number: ");
			scanf("%d", &item);

			// Print current list first
			printf("Current list: ");
			printList(&l);
			printf("\n");
			
			// Call insertSorted()
			idx = insertSorted(&l, item);

			// Print list after calling insertSorted()
			printf("After insertSorted(): ");
			printList(&l);
			printf("\n");

			// Print index where the number was added (or failure notice)
			if (idx >= 0)
				printf("The value %d was added at index %d\n", item, idx);
			else
				printf("insertSorted() could not complete successfully :(\n");

			break;
		case 3: // Task 3: removeDuplicates()

			// Print current list first
			printf("Current list: ");
			printList(&l);
			printf("\n");

			// Call removeDuplicates()
			item = removeDuplicates(&l);

			// Print list after calling removeDuplicates()
			printf("After removeDuplicates(): ");
			printList(&l);
			printf("\n");

			// Print how many numbers were removed
			printf("%d numbers were removed from the list\n", item);

			break;
		case 4: // Quit program
			printf("Quitting...\n");
			break;
		default:
			printf("Please input a valid choice...\n");
		}
	} while (choice != 4);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Functions used in this file

///// Basic LinkedList operations, from Prof Mark Yong
void printList(LinkedList *ll){

	ListNode *temp = ll->head;

	if (temp == NULL)
		return;

	while (temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}
}

ListNode * findNode(LinkedList *ll, int index){
	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

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

int removeNode(LinkedList *ll, int index){
	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		// Removing the last node, update the tail pointer
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

///// Functions for Assignment 2
void createLinkedList(LinkedList *ll) {
	int item;

	// Input numbers
	printf("Enter a list of numbers, terminated by the value -1: ");
	scanf("%d", &item);

	// until found -1 in input
	while (item != -1){
		insertNode(ll, ll->size, item);
		scanf("%d", &item);
	}

	// Print the current list
	printf("Printing list: ");
	printList(ll);
	printf("\n");
}

int insertSorted(LinkedList *ll, int value) {
	int idx = 0;
	ListNode *temp = ll->head;
	
	// If LinkedList is not exists, return -1
	if (temp == NULL)
		return -1;

	// If LinkedList is not at end, then traverse
	while (temp != NULL) {
		if (temp->item < value) {
			// If LinkedList value is smaller than "value", traverse the list
			temp = temp->next;
			idx++;
		}
		else {
			// Once the LinkedList value is not smaller than "value",
			//     (i.e. bigger or equal to "value", 
			//           guarantees smallest possible index position)
			//     insert it there
			//     and terminate the traversal
			insertNode(ll, idx, value);
			return idx;
		}
	}
	// in case of value is bigger than all of the items
	insertNode(ll, idx, value);
	return idx;
}

int removeDuplicates(LinkedList *ll) {
	int idx = 0, tmp_val = -1, cnt = 0;
	ListNode *temp = ll->head;

	// If LinkedList is not at end, then traverse
	while (temp != NULL) {
		if (tmp_val != temp->item) {
			// If current item != previous item,
			//     1. let previous item = current item
			//     2. traverse next node
			tmp_val = temp->item;
			temp = temp->next;
			idx++;
		}
		else {
			// If current item == previous item,
			//     1. traverse next node
			//        (if not, the address of next node will be lost)
			//     2. remove the current item
			//     3. increase counter of removed items
			temp = temp->next;
			removeNode(ll, idx);
			cnt++;
			// Note: idx is unchanged, because of the result of
			//       traversing to next node (+1) 
			//       and deleting the current node (-1)
		}
	}
	return cnt;
}
