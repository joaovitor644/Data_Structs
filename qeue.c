#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    uint32_t data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* ini;
    QueueNode* end;
} Queue;

uint32_t isEmpty(Queue* qeue){
	if(qeue->ini == NULL && qeue->end == NULL){
		return 1;
	}
	return 0;
}

void enqueue(Queue* qeue,uint32_t data){
	QueueNode* newNode = malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;
	if(isEmpty(qeue)){
		qeue->ini = newNode;
		qeue->end = newNode;
	}
	if(qeue->ini != NULL && qeue->end == NULL){
		qeue->end = newNode;
	} 
	else{
		qeue->end->next = newNode;
		qeue->end = newNode;
	}
}

uint32_t dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    if (queue->end == queue->ini) {
        QueueNode* res = queue->ini;
        uint32_t data = res->data;
        queue->ini = NULL;
        queue->end = NULL;
        free(res);
        return data;
    }
    else {
        QueueNode* res = queue->ini;
        queue->ini = queue->ini->next;
        uint32_t data = res->data;
        free(res);
        return data;
    }
}

int main() {
    Queue* queue = malloc(sizeof(Queue));
    queue->ini = NULL;
    queue->end = NULL;
    // Verifica se a fila está vazia
    printf("Queue is empty: %s\n", isEmpty(queue) ? "Yes" : "No");

    // Adiciona elementos à fila
    enqueue(queue, 10);
    enqueue(queue, 0);
    // Verifica se a fila está vazia
    printf("Queue is empty: %s\n", isEmpty(queue) ? "Yes" : "No");

    // Remove elementos da fila e imprime seus valores
    printf("Dequeued value: %d\n", dequeue(queue));
    printf("Dequeued value: %d\n", dequeue(queue));
    printf("Dequeued value: %d\n", dequeue(queue));
    // Verifica se a fila está vazia após remover todos os elementos
    printf("Queue is empty: %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("Fila vazia:%d\n",isEmpty(queue));
    

    free(queue);

    return 0;
}
