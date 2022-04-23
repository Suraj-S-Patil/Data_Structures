#include<stdio.h>
#include<stdlib.h>

#define max 5

//defining structure for array and pointers for the queue.
//struc is used to store data of different datatypes.
struct queue{
    int items[max];
    int front;
    int rear;
};

typedef struct queue QUEUE;

// function for inserting an item at the rear end of the queue.
int insert(int item,QUEUE *q){
    if(q->rear == max-1){
        printf("Queue is full! Insertion at the rear end not possible.");
        return 0;
    }
    (q->rear)++;
    q->items[q->rear]=item;
}

// function for deleting an item at the front end the queue.
int delete(QUEUE *q){
    if(q->front > q->rear){
        printf("\nQueue is empty! Deletion at the front end not possible.\n");
        return 0;
    }
    printf("\nItem deleted is: %d\n",q->items[q->front]);
    (q->front)++;

    if(q->front > q->rear){
        q->front = 0;
        q->rear = -1;
    }
}

// function for displaying the items in the queue.
int display(QUEUE *q){
    if(q->front > q->rear){
        printf("Queue is empty! Nothing to display.");
        return 0;
    }

    printf("\nThe contents of the queue are: \n");
    for(int i=q->front;i<=q->rear;i++){
        printf("%d\t",q->items[i]);
    }
}

// main function
int main(){
    QUEUE q;
    q.front = 0;
    q.rear = -1;
    int input,item;

    for(;;){
        printf("\n\n************************************ Queue Program ***************************************\n");
        printf("Chose from the below :----\n1. Insert.\n2. Delete.\n3. Display.\n4. Exit.");
        printf("\n\nChoice :--- ");
        scanf("%d",&input);

        switch(input){
            case 1: printf("Please enter a number to be inserted in the queue: ");
                    scanf("%d",&item);
                    insert(item,&q);
                    display(&q);
                    break;
            case 2: delete(&q);
                    display(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid input! Please enter a valid input : ");
                     continue;
        }
    }
}
