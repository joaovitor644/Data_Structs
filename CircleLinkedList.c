#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// -- List Implementation
typedef struct Node{
	char name[50];
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct List{
	Node* head;
	Node* tail;
}List;

List* createList(){
	List* l = malloc(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	return l;
}

void Add(List* list,char* data){
	Node* newValue = (Node*)malloc(sizeof(Node));
	strcpy(newValue->name,data);
	newValue->next = NULL;
	newValue->prev = NULL;
	if(list->head == NULL){
        newValue->next = newValue;
        newValue->prev = newValue;
        list->tail = newValue;
		list->head = list->tail;
	} else {
		list->tail->next = newValue;
		newValue->prev = list->tail;
		list->tail = newValue;
        list->tail->next = list->head;
        list->head->prev = list->tail;
	}
}

void Remove(List* list,char* data) {
    Node* current = list->head;
    Node* previous = NULL;
    while (current != NULL && strcmp(current->name,data) != 0) {
        previous = current;
        current = current->next;
        if(current == list->head)
            break;
    }
    if (current != NULL) {
        if (previous == NULL) {
            list->head = current->next;
            list->head->prev = list->tail;
			 list->tail->next = list->head;
        } else {
            previous->next = current->next;
            if (current->next != NULL)
                current->next->prev = previous;
        }
        if (current == list->tail)
            list->tail = previous;

        free(current);
    }
}

uint32_t search(List* list,char* data){
	Node* value = list->head;
	while(value != NULL){
		if(strcmp(value->name, data) == 0)
			return 1;

		value = value->next;
        if(value == list->head)
            break;
	}
	return 0;
}


int main(int argc, char* argv[]) {



    return 0;
}
