#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node* link;  // We can do node* but that is only possible in C++
}

void main()
{
    struct node* result;
	struct node* head ;
	head = (struct node*)malloc(sizeof *head);
	result = (struct node*)malloc(sizeof *result);
	result->item = 10;
	result->link = NULL;
	head->link = result;
	
}
