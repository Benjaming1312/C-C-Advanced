#include<stdio.h>
#include<stdlib.h>

struct _node {
	int data;
	struct _node * next;
};
typedef struct _node node;

int main() {
	node *head, *ptr, *ptr2;
	head = NULL;
	
	int i, value;
	
	while (1) {
		scanf("%d", &value);
		if (value == -1) {
			break;
		}

		if (head == NULL) {	
			head = (node *)malloc(sizeof(node));
			ptr = head;
		}
		else {
			ptr -> next = (node *)malloc(sizeof(node));
			ptr = ptr -> next;	
		}
		ptr -> data = value;
		ptr -> next = NULL;
	}
	
	ptr = head;
	while (ptr != NULL) {
		printf("%d ", ptr -> data);
		ptr = ptr -> next;
	}
	
	ptr = head;
	while (ptr != NULL) {
		ptr2 = ptr -> next;
		free(ptr);
		ptr = ptr2;
	}
	
	return 0;
};

