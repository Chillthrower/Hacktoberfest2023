#include <bits/stdc++.h>
#define MAX 10
using namespace std;

struct Queue {
    int front, rear;
    int data[MAX];
};

void initialize(struct Queue *queue) {
    queue->front = queue->rear = -1;
}

void insert(struct Queue *queue, int value) {
    if ((queue->rear == MAX - 1 && queue->front == 0) || (queue->rear + 1 == queue->front)) {
        cout << "Queue is full. Cannot insert " << value << endl;
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX;
    }

    queue->data[queue->rear] = value;
    cout << "Element inserted: " << value << endl;
}

int del(struct Queue *queue) {
    if (queue->front == -1) {
        cout << "Queue is empty. Cannot delete." << endl;
        return -1;
    }

    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }

    return value;
}

int main() {
    struct Queue queue;
    initialize(&queue);

    insert(&queue, 10);
    insert(&queue, 20);
    insert(&queue, 30);

    int deletedValue = del(&queue);
    if (deletedValue != -1) {
        cout << "Deleted element: " << deletedValue << endl;
    }

    return 0;
}
