#include<stdio.h>
#include<stdlib.h>

#define max 5

struct queue{
    int items[max];
    int front;
    int rear;
};
typedef struct queue QUEUE;

// Inserting an item at the rear end of the queue.
int insert_rear(int item, QUEUE *q){
    if((q->rear) == max-1){
        printf("\nQueue is full! Can't insert any more items.\n");
        return 0;
    }
    (q->rear)++;
    q->items[q->rear]=item;
    printf("\n%d successfully inserted in the queue.",item);
}

// Deleting an item from the front end of the queue.
int delete_front(QUEUE *q){
    if(q->front > q->rear){
        printf("\nQueue is empty! Can't delete any item from the queue.\n");
        return 0;
    }

    printf("%d successfully deleted from the front end of the queue.\n",q->items[q->front]);
    (q->front)++;

    if(q->front > q->rear){
        q->front=0;
        q->rear=-1;
    }
}

// Inserting an item at the front end of the queue.
int insert_front(int item, QUEUE *q){
    if(q->front==0){
        printf("\nFront end of the queue is full! Can't insert any more items at front end.\n");
        return 0;
    }
    (q->front)--;
    q->items[q->front]=item;
    printf("\n%d successfully inserted in the queue.",item);
}

// deleting an item from the rear end of the queue.
int delete_rear(QUEUE *q){
    if(q->front > q->rear){
        printf("\nQueue is empty! Can't delete any item from the queue.\n");
        return 0;
    }

    printf("%d successfully deleted from the rear end of the queue.\n",q->items[q->rear]);
    (q->rear)--;

    if(q->front > q->rear){
        q->front=0;
        q->rear=-1;
    }
}

// Displaying all the elements of the queue.
int display_queue(QUEUE *q){
    if((q->front) > (q->rear)){
        printf("Queue is empty! Nothing to display.");
        return 0;
    }
    printf("The items in the queue are: \n\n");
    for(int i=(q->front);i<=(q->rear);i++){
        printf("%d\t",q->items[i]);
    }
}

// Main function.
int main(){
    QUEUE q;
    q.front=0;
    q.rear=-1;

    int item, input;

    // Menu for the Deque program.
    for(;;){
        printf("\n----------------------------- + Deque Program + ---------------------------------\n");

        printf("1. Insert at rear end of the queue.\n2. Insert at front end of the queue.\n3. Delete from the front end of the queue.\n4. Delete from the rear end of the queue.\n5. Display the items in the queue.\n6. Exit.\n\nChoice : ");
        scanf("%d",&input);
        printf("\n");
        switch(input){
            case 1: printf("Enter a number to be inserted: ");
                    scanf("%d",&item);
                    insert_rear(item,&q);
                    display_queue(&q);
                    break;
            case 2: printf("Enter a number to be inserted: ");
                    scanf("%d",&item);
                    insert_front(item,&q);
                    display_queue(&q);
                    break;
            case 3: delete_front(&q);
                    display_queue(&q);
                    break;
            case 4: delete_rear(&q);
                    display_queue(&q);
                    break;
            case 5: display_queue(&q);
                    break;
            case 6: exit(0);
                    break;
            default: printf("Invalid input!");
                     continue;
        }

        printf("\n---------------------------------------------------------------------------------\n");
    }
    return 0;
}
