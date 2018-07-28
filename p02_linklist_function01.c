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
	
	node input;
	int i, value;
	char op;
	
	while (1) {
		puts("i �s�W�`�I");
		puts("l �C�L�`�I");
		puts("q ���}");
		
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
				whitle (ptr !== NULL){
					printf("%d", ptr-> data);
					ptr = ptr -> next;
				}
				break;
			case 'q':
				return 0;
				break
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

node *getnode () /* ����Ʋ��ͤ@�ӷs�`�I */
{
	node *p;
	p = (node *) malloc(sizeof(node));
	 /* malloc �|�ʺA�a�t�m�j�p��sizeof ���O����*/
	 /* sizeof �|�Ǧ^�@�ӫ��A��node����*/
	if ( p == NULL)
	{
	printf ("�O���餣��");
	exit(1);
	}
	return(p);
}
