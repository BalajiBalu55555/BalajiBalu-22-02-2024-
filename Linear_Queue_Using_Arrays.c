#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("OVERFLOW \n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("UNDERFLOW \n");
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() { 
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        int i ;
        for ( i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int find(int element) {
	int i ;
    for ( i = front; i <= rear; i++) {
        if (queue[i] == element) {
            printf("%d found at position %d\n", element, i - front + 1);
            return 1;
        }
    }
    printf("%d not found in the queue\n", element);
    return 0;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display(); 

    dequeue();
    dequeue();
    display(); 

    find(5); 
    find(6); 

    return 0;
}
