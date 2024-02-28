#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() { 
    return (rear + 1) % SIZE == front;
}

void enqueue(int value) {
    if (isFull()) {
        printf("OVERFLOW \n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = value;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("UNDERFLOW \n");
    } else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("UNDERFLOW\n");
    } else {
        int i = front;
        printf("Queue elements are: ");
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        printf("\n");
    }
}  
int find(int element) {  
    if (isEmpty()) {
        printf("UNDERFLOW\n");
        return 0;
    }
    int i = front;
    do {
        if (queue[i] == element) {
            printf("%d found at position %d\n", element, i - front + 1);
            return 1;
        }
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);
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
    
    enqueue(6);
    enqueue(7);
    
    display(); 

    find(5); 
    find(10);

    return 0;
} 
