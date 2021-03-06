#include<stdio.h>
#include<stdlib.h>

struct _node {
	int data;
	struct _node * next;
};
typedef struct _node node;

//node *insert_node (node *head, node *ptr, node data) ;
//node *delete_node(node * node, node *ptr);
//node *getnode ();

int main() {
	node *head, *ptr, *ptr2;
	head = NULL;
	
	node input;
	int i, value;
	char op;
	
	while (1) {
		puts("i 新增節點");
		puts("l 列印節點");
		puts("q 離開");
		
		scanf(" %d", &op);
		scanf("%d", &value);
		
		switch(op) {
			case 'i':
				scanf("%d", &input.data);
				
				if (head == NULL) {
					head = insert_node(head, NULL, input);
				}
				else {
					ptr = head;
					while (ptr -> next != NULL) {
						ptr = ptr -> next;
						head = insert_node(head, ptr, input);
					}	
				}
				break;
			case 'l':
				ptr = head;
				while (ptr != NULL){
					printf("%d", ptr-> data);
					ptr = ptr -> next;
				}
				break;
			case 'f':
				scanf("&d", &value);
				ptr = find_node(head, value);
				if (ptr != NULL) {
					printf("found %d\n", ptr -> data);
				}
				else {
					puts("nout found");
				}
			case 'd':
				scanf("&d", &value);
				ptr = find_node(head, value);
				if (ptr != NULL) {
					ptr = delete_node(head, ptr);
					puts("Delete ok");
				}
				else {
					puts("cannot delete");
				}
				
			case 'q':
				return 0;
				break;
		}
		
		if (value == -1) {
			break;
		}

		if (head == NULL) {	
			head = (node *)malloc(sizeof(node));
			head -> next = NULL;
		}
		else {
			head = (node *)malloc(sizeof(node));
			head -> next = ptr;
		}
		head -> data = value;
		ptr = head;
	}
	
//	ptr = head;
//	while (ptr != NULL) {
//		printf("%d ", ptr -> data);
//		ptr = ptr -> next;
//	}
//	
//	ptr = head;
//	while (ptr != NULL) {
//		ptr2 = ptr -> next;
//		free(ptr);
//		ptr = ptr2;
//	}
	
	return 0;
};

node *getnode () /* 此函數產生一個新節點 */
{
	node *p;
	p = (node *) malloc(sizeof(node));
	 /* malloc 會動態地配置大小為sizeof 的記憶體*/
	 /* sizeof 會傳回一個型態為node之值*/
	if ( p == NULL)
	{
	printf ("記憶體不足");
	exit(1);
	}
	return(p);
}

node *insert_node (node *head, node *ptr, node data) {
	node *new_node;
	new_node = getnode();
	*new_node = data;
	new_node -> next = NULL;
	if (ptr == NULL) {
		new_node -> next = head;
		head = new_node;
	}
	else {
		if (ptr ->next == NULL) {
			ptr->next = new_node;
		}
		else {
			new_node->next = ptr->next;
			ptr->next = new_node;
		}
	}
}

node *delete_node(node * node, node *ptr) {
	node *previous;
	if (ptr == head) {
		head = head -> next;
	}
	else {
		previous = head;
		while (previous -> next != ptr) {
			previous = previous -> next;
		}
		if (ptr -> next == NULL) {
			previous -> next = NULL;
		}
		else {
			previous -> next = ptr ->next;
		}
		freenode(ptr);
		return (head);
	}
}
