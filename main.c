// 191180055 - ALÝ MERT KOCAMAN - SECTION 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // These are the libraries I used.
#include <unistd.h>
#define SIZE 10

int Option();
bool isFull();
bool isEmpty();
bool Enqueue(int); // These are the prototypes of the functions.
void Dequeue();
void PrintQueue();

typedef struct{
	int value;
} element;

element queue[SIZE] = {};
element tempStack[SIZE] = {};
int front = -1, rear = -1;


int main() {
	int x;
	
	while(1){
		// The while loop I opened for continuous operation.
		system("cls"); //Cleaning the console.
	
		switch(Option()){
			//Switch-Case structure using option input from the user.
			case 0:
				//Runs the PrintQueue method.
				PrintQueue(); 
				break;
			case 1:
				//We get integer value from user because we will Enqueue.
				printf("Enter the value to add: ");
				scanf("%d",&x);
				if(Enqueue(x)){
					printf("The element has been succesfully added.");
					sleep(1);
				} else {
					printf("\nElement insertion failed.");
					sleep(1);
				}
				break;
			case 2:
				//Runs the Dequeue method.
				Dequeue();
				break;
			case 3:
				// Ends the app.
				printf("\nApplication is ending...");
				exit(0);
				break;
			default:
				printf("Invalid enterance");
				sleep(1);
				break;
		}
	}
}

int Option(){
	// Function that presents options to the user.
	int i;
	
	printf("\n---------OPTIONS---------\n");
	printf("0- Print all elements of the queue\n");
	printf("1- Add an element into the queue\n");
	printf("2- Remove element from the queue\n");
	printf("3- Exit\n\n");
	printf("Select (0-3)? : ");
	scanf("%d",&i);
	return i;
	
}

bool isFull(){
	// Checks if the queue is full.
	if(rear == SIZE-1)
		return 1;
	return 0;
}

bool isEmpty(){
	//Checks if the queue is empty.
	if((front == -1 && rear == -1) || front > rear )
		return 1;
	return 0;
		
	
}
bool Enqueue(int x){
	// The function that adds the element to the queue.
	int i, j;
	
	if(isFull()){
		//If the queue is full, we cannot add the new element.
		printf("Overflow");
		sleep(1);
		return 0;
	}
		
	else if(isEmpty()) {
		// Our front and rear values were -1.
		// If the queue is empty, our front and rear values should be zero.
		front = rear = 0;
		
		// It assigns the entered input to the element at index 0 of the queue.
		queue[rear].value = x;
		return 1;
	}
	
	else {
		// If there are already elements in the queue, the else block works.
		
		/* A for loop that compares the element to be added with the elements 
		in the queue and assigns the larger ones to a temporary stack.*/ 
		for(i=0; x < queue[rear].value; i++){
			tempStack[i].value = queue[rear].value;
			rear--;
		}
		
		//Adds the element to the queue after the elements added to the temporary stack.
		queue[++rear].value = x;
		
		// Adds elements from the temporary stack back to the queue.
		j=i-1;
		while(j>=0){
			queue[++rear].value = tempStack[j].value;
			j--;
		}
		return 1;
	}
	return 0;
	
}

void Dequeue(){
	// Function that runs when removing an element from the queue.
	
	// If the queue is empty, any element cannot be removed.
	if(isEmpty()){
		printf("Underflow");
		sleep(1);
	}
	
	// Front and rear values can be equal if there is only one element in the queue.
	// When we delete this element, we set the front and rear values to -1 again, beacuse there will be no element in the queue.
	else if(front == rear && front == 0){
		front = rear = -1;
		printf("The element was successfully removed from the queue.");
		sleep(1);
	}
	// Increases the front value by 1 because the element is deleted.
	else{
		front++;
		printf("The element was successfully removed from the queue.");
		sleep(1);
	}
}

void PrintQueue(){
	// Function that works to print the queue to the screen.
	int i;
	if(isEmpty()){
		printf("Queue is empty.");
		sleep(1);
		return;
	}
	printf("Queue: ");
	for(i=front; i < rear+1; i++){
		printf("%d ", queue[i].value);
	}
	printf("\n");
	sleep(2);
}
