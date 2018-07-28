#include<stdio.h>
#include<stdlib.h>

struct _node {
	int data;
	struct _node * next;
};
typedef struct _node node;

int main() {
	node *head, *ptr;
	head = (node *)malloc(sizeof(node));
	ptr = head;
	
	int i, value;
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &value);
		if (i < 5 -1) {
			ptr -> data = value;
			ptr -> next = (node *)malloc(sizeof(node));
			ptr = ptr->next;
		}
		else {
			ptr -> data = value;
			ptr -> next = NULL;
		}

	}
	
	ptr = head;
	while (ptr != NULL) {
		printf("%d ", ptr -> data);
		ptr = ptr -> next;
	}
	
	return 0;
};

