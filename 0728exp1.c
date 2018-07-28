#include<stdio.h>

struct _node {
	int data;
	struct _node * next;
};
typedef struct _node node;

int main() {
	node * head;
	head = (node *)malloc(sizeof(node));
	head -> data = 10;
	head -> next = NULL; 
	
	printf("%d\n", head -> data);
	
	return 0;
};

