#include<stdio.h>
#include<stdlib.h>

struct _node {
	int data;
	struct _node * next;
};
typedef struct _node node;

node *insert_node (node *head, node *ptr, node data);
node *delete_node (node * head, node *ptr);
node *getnode ();
node *find_node(node *head, int num);
void freenode (node *p);

int main() {
	node *head, *ptr;
	node input;
	head = NULL;
	int value, i;
	char op;
	
	while (1) {
//		puts("i �s�W�`�I(last)");
//		puts("j �s�W�`�I(first)");
//		puts("m �s�W�`�I(@ pos)");
//		puts("n �s�W�`�I(@n���᭱)");
//		puts("s �s�W�K�Ƨ�");
//		puts("l �C�L�`�I");
//		puts("f �M��`�I");
//		puts("d �R���`�I");
//		puts("q ���}");
		
		scanf(" %c", &op);
		
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
					}
					head = insert_node(head, ptr, input);
				}
				break;
			case 'j':
				scanf("%d", &input.data);
				head = insert_node(head, NULL, input);
				
				break;
			case 'l':
				ptr = head;
				while (ptr != NULL){
					printf("%d ", ptr-> data);
					ptr = ptr -> next;
				}
				puts("");
				break;
			case 's':
				scanf("%d", &input.data);
				if (head == NULL || input.data < head -> data) {
					head = insert_node(head, NULL, input);
				}
				else {
					ptr = head;
					while (ptr -> next != NULL && input.data > ptr->next->data) {
						ptr = ptr -> next;
					}
					head = insert_node(head, ptr, input);
				}
				break;
			case 'm':
				scanf("%d", &value);
				scanf("%d", &input.data);
				
				if (head == NULL || value == 0) {
					head = insert_node(head, NULL, input);
				}
				else {
					ptr = head;
					for (i=0; i< value - 1 && ptr->next != NULL; i++) {
						ptr = ptr->next;
					}
					head = insert_node(head, ptr, input);
				}
				break;
			case 'n':
				scanf("%d", &value);
				ptr = find_node(head, value);
				if (ptr != NULL) {
					printf("found %d\n", ptr -> data);
					scanf("%d", &input.data);
					head = insert_node(head, ptr, input);
				}
				else {
					printf("%d not found, can not insert\n", value);
				}
				break;
			case 'f':
				scanf("%d", &value);
				ptr = find_node(head, value);
				if (ptr != NULL) {
					printf("found %d\n", ptr -> data);
				}
				else {
					printf("nout found\n");
				}
				break;
			case 'd':
				scanf("%d", &value);
				ptr = find_node(head, value);
				if (ptr != NULL) {
					ptr = delete_node(head, ptr);
					puts("Delete ok");
				}
				else {
					puts("cannot delete");
				}
				break;
			case 'q':
				return 0;
				break;
		}
		system("pause");
		system("cls");
	}
}

void freenode (node *p) {
	free(p);
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
};

node *find_node(node *head, int num) {
	node *ptr;
	ptr = head;
	while(ptr != NULL) {
		if (ptr->data == num) {
			return (ptr);
		}
		else {
			ptr = ptr -> next;
		}
	}
	return (ptr);
};
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
	return(head);
};

node *delete_node(node * head, node *ptr) {
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
};
